/*
 * M4 CAN Send/Receive Wrappers
 * Cambridge University Spaceflight
 */

#include <string.h>

#include "hal.h"
#include "m4can.h"
#include "ch.h"

#ifndef FIRMWARE_VERSION
#error "Please check your Makefile sets FIRMWARE_VERSION"
#endif

uint8_t m4can_own_id = 0;

static volatile bool m4can_loopback_enabled;
static void m4can_send_git_version(void);


static const CANConfig cancfg = {
    .mcr =
        /* Automatic Bus Off Management enabled,
         * Automatic Wake Up Management enabled.
         */
        CAN_MCR_ABOM | CAN_MCR_AWUM,
    .btr =
        /* CAN is on APB1 at 42MHz, we want 1Mbit/s.
         * 1/Baud = (BRP+1)/(APB1) * (3+TS1+TS2)
         */
        CAN_BTR_BRP(5) | CAN_BTR_TS1(3) | CAN_BTR_TS2(1)
        /* Allow up to 2 time quanta clock synchronisation */
        | CAN_BTR_SJW(1)
};


static void m4can_filter_messages(uint16_t *allowed_ids, uint8_t numids) {
//    // clear all filters
//    canSTM32SetFilters(27, 0, NULL);
//    // Layout of bits in register (we're in 16-bit mode; see manual p. 1092):
//    // STDID       RTR IDE EXID
//    // A9876543210 0   0   17,16,15
//    // mask: last 5 bits match RTR, IDE, EXID -- ignore those
//    const uint32_t mask = 0x1f << (5+16);  // match last 5 bits of STDID, shift to mask position
//    const uint32_t numfilters = numids/2 + (numids % 2);
//    chDbgAssert(numfilters <= 27, "Too many filters passed in");
//
//    CANFilter filters[27] = { 0 };
//    for (uint8_t i = 0; i < numids; i += 2) {
//        uint8_t n = i / 2;  // CANFilter number -- 2 filters per CANFilter
//        filters[n].filter       = n;    // filter number to be programmed
//        filters[n].mode         = 0;    // mask mode
//        filters[n].scale        = 0;    // 16-bit mode enough to filter STDID
//        filters[n].assignment   = 0;    // must be zero
//        // registers: 16 LSB are ID, 16 MSG are mask
//        // each register is one filter
//        filters[n].register1 = (allowed_ids[i] << 5) | mask;
//        if (i == numids-1) {
//            // odd number of IDs passed in
//            filters[n].register2 = filters[n].register1;
//        } else {
//            filters[n].register2 = (allowed_ids[i+1] << 5) | mask;
//        }
//    }
//    canSTM32SetFilters(27, numfilters, filters);
}


void m4can_send(uint16_t msg_id, bool rtr, uint8_t *data, uint8_t datalen) {
    static CANTxFrame txmsg;

    chDbgAssert(datalen <= 8, "CAN packet >8 bytes");

    if(rtr == false) {
        txmsg.RTR = CAN_RTR_DATA;
    } else {
        txmsg.RTR = CAN_RTR_REMOTE;
    }
    txmsg.IDE = CAN_IDE_STD;
    txmsg.DLC = datalen;
    txmsg.SID = msg_id;

    memcpy(&txmsg.data8, data, datalen);

    canTransmit(&CAND1, CAN_ANY_MAILBOX, &txmsg, TIME_MS2I(100));

    if(m4can_loopback_enabled) {
        m4can_recv(msg_id, rtr, data, datalen);
    }
}


void m4can_send_u8(uint16_t msg_id, uint8_t d0, uint8_t d1, uint8_t d2,
                 uint8_t d3, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7,
                 size_t n)
{
    uint8_t buf[8] = {d0, d1, d2, d3, d4, d5, d6, d7};
    m4can_send(msg_id, false, buf, n);
}

void m4can_send_u16(uint16_t msg_id, uint16_t d0, uint16_t d1, uint16_t d2,
                  uint16_t d3, size_t n)
{
    uint8_t buf[8] = {d0, d0>>8, d1, d1>>8, d2, d2>>8, d3, d3>>8};
    m4can_send(msg_id, false, buf, n<<1);
}

void m4can_send_u32(uint16_t msg_id, uint32_t d0, uint32_t d1, size_t n)
{
    uint8_t buf[8] = {d0, d0>>8, d0>>16, d0>>24, d1, d1>>8, d1>>16, d1>>24};
    m4can_send(msg_id, false, buf, n<<2);
}

void m4can_send_i8(int16_t msg_id, int8_t d0, int8_t d1, int8_t d2,
                 int8_t d3, int8_t d4, int8_t d5, int8_t d6, int8_t d7,
                 size_t n)
{
    uint8_t buf[8] = {d0, d1, d2, d3, d4, d5, d6, d7};
    m4can_send(msg_id, false, buf, n);
}

void m4can_send_i16(int16_t msg_id, int16_t d0, int16_t d1, int16_t d2,
                  int16_t d3, size_t n)
{
    uint8_t buf[8] = {d0, d0>>8, d1, d1>>8, d2, d2>>8, d3, d3>>8};
    m4can_send(msg_id, false, buf, n<<1);
}

void m4can_send_i32(int16_t msg_id, int32_t d0, int32_t d1, size_t n)
{
    uint8_t buf[8] = {d0, d0>>8, d0>>16, d0>>24, d1, d1>>8, d1>>16, d1>>24};
    m4can_send(msg_id, false, buf, n<<2);
}

void m4can_send_f32(uint16_t msg_id, float d0, float d1, size_t n)
{
    float buf[2] = {d0, d1};
    m4can_send(msg_id, false, (uint8_t*)buf, n<<2);
}


static THD_WORKING_AREA(can_rx_wa, 512);
static THD_FUNCTION(can_rx_thd, arg) {
    (void)arg;

    event_listener_t el;
    CANRxFrame rxmsg;
    systime_t time_last_id = 0;

    chEvtRegister(&CAND1.rxfull_event, &el, 0);

    while(true) {
        if(chEvtWaitAnyTimeout(ALL_EVENTS, TIME_MS2I(100)) == 0) {
            continue;
        }

        /* Handle all pending frames */
        while(canReceive(&CAND1, CAN_ANY_MAILBOX, &rxmsg,
                         TIME_IMMEDIATE) == MSG_OK) {
            m4can_recv(rxmsg.SID, rxmsg.RTR, rxmsg.data8, rxmsg.DLC);
        }

        /* Send our git ID every 5 seconds */
        if(TIME_I2MS(chVTTimeElapsedSinceX(time_last_id)) > 5000) {
            m4can_send_git_version();
            time_last_id = chVTGetSystemTimeX();
        }
    }
}

void m4can_set_loopback(bool enabled) {
    m4can_loopback_enabled = enabled;
}


void m4can_init(uint8_t board_id, uint16_t* filter_ids, size_t num_filter_ids)
{
    m4can_own_id = board_id;
    if(filter_ids != NULL) {
        m4can_filter_messages(filter_ids, num_filter_ids);
    }
    canStart(&CAND1, &cancfg);
    m4can_send_git_version();
    chThdCreateStatic(can_rx_wa, sizeof(can_rx_wa), NORMALPRIO,
                      can_rx_thd, NULL);
}

static void m4can_send_git_version(void) {
    m4can_send(m4can_own_id | CAN_MSG_ID_VERSION, false,
             (uint8_t*)FIRMWARE_VERSION, 8);
}

//Radio
void m4can_recv(uint16_t msg_id, bool rtr, uint8_t* data, uint8_t datalen) {
    m4radio_router_handle_can(msg_id, rtr, data, datalen);
}
