#ifndef M4CAN_H
#define M4CAN_H
#include <stddef.h>

#include "hal.h"
#include "ch.h"

#define CAN_ID_M4FC      (1)
#define CAN_ID_M4PSU     (2)
#define CAN_ID_M4PYRO    (3)
#define CAN_ID_M4RADIO   (4)
#define CAN_ID_M4IMU     (5)
#define CAN_ID_M4DL      (6)
#define CAN_ID_GROUND    (7)

#define CAN_MSG_ID(x)    (x<<5)

#define CAN_MSG_ID_VERSION                  CAN_MSG_ID(63)
#define CAN_MSG_ID_STATUS                   CAN_MSG_ID(0)

extern uint8_t m4can_own_id;

// Fill out known CAN message IDs here, so all boards can know about them

/* M4RADIO */
#define CAN_MSG_ID_M4RADIO_GPS_LATLNG       (CAN_ID_M4RADIO | CAN_MSG_ID(48))
#define CAN_MSG_ID_M4RADIO_GPS_ALT          (CAN_ID_M4RADIO | CAN_MSG_ID(49))
#define CAN_MSG_ID_M4RADIO_GPS_TIME         (CAN_ID_M4RADIO | CAN_MSG_ID(50))
#define CAN_MSG_ID_M4RADIO_GPS_STATUS       (CAN_ID_M4RADIO | CAN_MSG_ID(51))
#define CAN_MSG_ID_M4RADIO_SI4460_CFG       (CAN_ID_M4RADIO | CAN_MSG_ID(52))
#define CAN_MSG_ID_M4RADIO_PACKET_COUNT     (CAN_ID_M4RADIO | CAN_MSG_ID(53))
#define CAN_MSG_ID_M4RADIO_PACKET_STATS     (CAN_ID_M4RADIO | CAN_MSG_ID(54))
#define CAN_MSG_ID_M4RADIO_PING             (CAN_ID_M4RADIO | CAN_MSG_ID(55))
#define CAN_MSG_ID_M4RADIO_SET_FREQ         (CAN_ID_M4RADIO | CAN_MSG_ID(56))


/* M4PSU */
#define CAN_MSG_ID_M4PSU_TOGGLE_PYROS           (CAN_ID_M4PSU | CAN_MSG_ID(16))
#define CAN_MSG_ID_M4PSU_TOGGLE_CHANNEL         (CAN_ID_M4PSU | CAN_MSG_ID(17))
#define CAN_MSG_ID_M4PSU_TOGGLE_CHARGER         (CAN_ID_M4PSU | CAN_MSG_ID(18))
#define CAN_MSG_ID_M4PSU_TOGGLE_LOWPOWER        (CAN_ID_M4PSU | CAN_MSG_ID(19))
#define CAN_MSG_ID_M4PSU_TOGGLE_BATTLESHORT     (CAN_ID_M4PSU | CAN_MSG_ID(20))
#define CAN_MSG_ID_M4PSU_PYRO_STATUS            (CAN_ID_M4PSU | CAN_MSG_ID(48))
#define CAN_MSG_ID_M4PSU_CHANNEL_STATUS_12      (CAN_ID_M4PSU | CAN_MSG_ID(49))
#define CAN_MSG_ID_M4PSU_CHANNEL_STATUS_34      (CAN_ID_M4PSU | CAN_MSG_ID(50))
#define CAN_MSG_ID_M4PSU_CHANNEL_STATUS_56      (CAN_ID_M4PSU | CAN_MSG_ID(51))
#define CAN_MSG_ID_M4PSU_CHANNEL_STATUS_78      (CAN_ID_M4PSU | CAN_MSG_ID(52))
#define CAN_MSG_ID_M4PSU_CHANNEL_STATUS_910     (CAN_ID_M4PSU | CAN_MSG_ID(53))
#define CAN_MSG_ID_M4PSU_CHANNEL_STATUS_1112    (CAN_ID_M4PSU | CAN_MSG_ID(54))
#define CAN_MSG_ID_M4PSU_CHARGER_STATUS         (CAN_ID_M4PSU | CAN_MSG_ID(55))
#define CAN_MSG_ID_M4PSU_BATT_VOLTAGES          (CAN_ID_M4PSU | CAN_MSG_ID(56))
#define CAN_MSG_ID_M4PSU_CAPACITY               (CAN_ID_M4PSU | CAN_MSG_ID(57))
#define CAN_MSG_ID_M4PSU_AWAKE_TIME             (CAN_ID_M4PSU | CAN_MSG_ID(58))


/* M4FC */
#define CAN_MSG_ID_M4FC_MISSION_STATE       (CAN_ID_M4FC | CAN_MSG_ID(32))
#define CAN_MSG_ID_M4FC_ACCEL               (CAN_ID_M4FC | CAN_MSG_ID(48))
#define CAN_MSG_ID_M4FC_BARO                (CAN_ID_M4FC | CAN_MSG_ID(49))
#define CAN_MSG_ID_M4FC_SE_T_H              (CAN_ID_M4FC | CAN_MSG_ID(50))
#define CAN_MSG_ID_M4FC_SE_V_A              (CAN_ID_M4FC | CAN_MSG_ID(51))
#define CAN_MSG_ID_M4FC_SE_VAR_H            (CAN_ID_M4FC | CAN_MSG_ID(52))
#define CAN_MSG_ID_M4FC_SE_VAR_V_A          (CAN_ID_M4FC | CAN_MSG_ID(53))
#define CAN_MSG_ID_M4FC_CFG_PROFILE         (CAN_ID_M4FC | CAN_MSG_ID(54))
#define CAN_MSG_ID_M4FC_CFG_PYROS           (CAN_ID_M4FC | CAN_MSG_ID(55))
#define CAN_MSG_ID_M4FC_CFG_ACCEL_X         (CAN_ID_M4FC | CAN_MSG_ID(56))
#define CAN_MSG_ID_M4FC_CFG_ACCEL_Y         (CAN_ID_M4FC | CAN_MSG_ID(57))
#define CAN_MSG_ID_M4FC_CFG_ACCEL_Z         (CAN_ID_M4FC | CAN_MSG_ID(58))
#define CAN_MSG_ID_M4FC_CFG_RADIO_FREQ      (CAN_ID_M4FC | CAN_MSG_ID(59))
#define CAN_MSG_ID_M4FC_CFG_CRC             (CAN_ID_M4FC | CAN_MSG_ID(60))
#define CAN_MSG_ID_M4FC_SET_CFG_PROFILE     (CAN_ID_M4FC | CAN_MSG_ID(1))
#define CAN_MSG_ID_M4FC_SET_CFG_PYROS       (CAN_ID_M4FC | CAN_MSG_ID(2))
#define CAN_MSG_ID_M4FC_LOAD_CFG            (CAN_ID_M4FC | CAN_MSG_ID(3))
#define CAN_MSG_ID_M4FC_SAVE_CFG            (CAN_ID_M4FC | CAN_MSG_ID(4))
#define CAN_MSG_ID_M4FC_MOCK_ENABLE         (CAN_ID_M4FC | CAN_MSG_ID(5))
#define CAN_MSG_ID_M4FC_MOCK_ACCEL          (CAN_ID_M4FC | CAN_MSG_ID(6))
#define CAN_MSG_ID_M4FC_MOCK_BARO           (CAN_ID_M4FC | CAN_MSG_ID(7))
#define CAN_MSG_ID_M4FC_ARM                 (CAN_ID_M4FC | CAN_MSG_ID(8))
#define CAN_MSG_ID_M4FC_FIRE                (CAN_ID_M4FC | CAN_MSG_ID(9))
#define CAN_MSG_ID_M4FC_SET_CFG_ACCEL_X     (CAN_ID_M4FC | CAN_MSG_ID(10))
#define CAN_MSG_ID_M4FC_SET_CFG_ACCEL_Y     (CAN_ID_M4FC | CAN_MSG_ID(11))
#define CAN_MSG_ID_M4FC_SET_CFG_ACCEL_Z     (CAN_ID_M4FC | CAN_MSG_ID(12))
#define CAN_MSG_ID_M4FC_SET_CFG_RADIO_FREQ  (CAN_ID_M4FC | CAN_MSG_ID(13))
#define CAN_MSG_ID_M4FC_SET_CFG_CRC         (CAN_ID_M4FC | CAN_MSG_ID(14))


/* M4DL */
#define CAN_MSG_ID_M4DL_FREE_SPACE          (CAN_ID_M4DL | CAN_MSG_ID(32))
#define CAN_MSG_ID_M4DL_RATE                (CAN_ID_M4DL | CAN_MSG_ID(33))
#define CAN_MSG_ID_M4DL_TEMP_1_2            (CAN_ID_M4DL | CAN_MSG_ID(48))
#define CAN_MSG_ID_M4DL_TEMP_3_4            (CAN_ID_M4DL | CAN_MSG_ID(49))
#define CAN_MSG_ID_M4DL_TEMP_5_6            (CAN_ID_M4DL | CAN_MSG_ID(50))
#define CAN_MSG_ID_M4DL_TEMP_7_8            (CAN_ID_M4DL | CAN_MSG_ID(51))
#define CAN_MSG_ID_M4DL_TEMP_9              (CAN_ID_M4DL | CAN_MSG_ID(52))
#define CAN_MSG_ID_M4DL_PRESSURE            (CAN_ID_M4DL | CAN_MSG_ID(53))


/* M4IMU */


/* M4PYRO */
#define CAN_MSG_ID_M4PYRO_FIRE_COMMAND      (CAN_ID_M4PYRO | CAN_MSG_ID(1))
#define CAN_MSG_ID_M4PYRO_ARM_COMMAND       (CAN_ID_M4PYRO | CAN_MSG_ID(2))
#define CAN_MSG_ID_M4PYRO_FIRE_STATUS       (CAN_ID_M4PYRO | CAN_MSG_ID(16))
#define CAN_MSG_ID_M4PYRO_ARM_STATUS        (CAN_ID_M4PYRO | CAN_MSG_ID(17))
#define CAN_MSG_ID_M4PYRO_CONTINUITY        (CAN_ID_M4PYRO | CAN_MSG_ID(48))
#define CAN_MSG_ID_M4PYRO_SUPPLY_STATUS     (CAN_ID_M4PYRO | CAN_MSG_ID(49))



/* Define this function somewhere else and implement it */
void m4can_recv(uint16_t msg_id, bool can_rtr, uint8_t *data, uint8_t datalen);

/* Call m4can_init early during startup, setting your board ID from the list
 * above.
 * filter_ids is an array of allowed board IDs to listen to,
 * num_filter_ids is the length of that array.
 */
void m4can_init(uint8_t board_id, uint16_t *filter_ids, size_t num_filter_ids);

/* Call m4can_send to transmit a packet.
 * msg_id should be from the list above
 * can_rtr is the "remote transmission request", set to indicate you're asking
 *         for data rather than sending it
 * data[] and datalen are the data (and number of bytes of it) to send.
 */
void m4can_send(uint16_t msg_id, bool can_rtr, uint8_t *data, uint8_t datalen);

/* Type specific m4can_send functions. In each case 'n' refers to the number of
 * values transmitted, not the number of corresponding bytes, so e.g. should be
 * 0 or 1 for send_u32.
 */
void m4can_send_u8(uint16_t msg_id, uint8_t d0, uint8_t d1, uint8_t d2,
                 uint8_t d3, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7,
                 size_t n);
void m4can_send_u16(uint16_t msg_id, uint16_t d0, uint16_t d1, uint16_t d2,
                  uint16_t d3, size_t n);
void m4can_send_u32(uint16_t msg_id, uint32_t d0, uint32_t d1, size_t n);
void m4can_send_i8(int16_t msg_id, int8_t d0, int8_t d1, int8_t d2,
                 int8_t d3, int8_t d4, int8_t d5, int8_t d6, int8_t d7,
                 size_t n);
void m4can_send_i16(int16_t msg_id, int16_t d0, int16_t d1, int16_t d2,
                  int16_t d3, size_t n);
void m4can_send_i32(int16_t msg_id, int32_t d0, int32_t d1, size_t n);
void m4can_send_f32(uint16_t msg_id, float d0, float d1, size_t n);

/* Enable processing all sent messages (via m4can_send) as though they were
 * also received (in m4can_recv).
 * Useful for boards like datalogger and radio which want to receive their own
 * packets for storage/transmission.
 */
void m4can_set_loopback(bool enabled);


void m4can_send_u8(uint16_t msg_id, uint8_t d0, uint8_t d1, uint8_t d2,
                   uint8_t d3, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7,
                   size_t n);

#endif
