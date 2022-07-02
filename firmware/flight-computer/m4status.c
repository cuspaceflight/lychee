#include "ch.h"
#include "m4status.h"
#include "m4can.h"

static uint8_t components[256] = {0};
static systime_t last_transmit[256] = {0};

static void m4status_set(uint8_t component, uint8_t status, uint8_t errorcode);

void m4status_set_ok(uint8_t component) {
    m4status_set(component, M4STATUS_OK, 0);
}

void m4status_set_init(uint8_t component) {
    m4status_set(component, M4STATUS_INITIALISING, 0);
}

void m4status_set_error(uint8_t component, uint8_t errorcode) {
    m4status_set(component, M4STATUS_ERROR, errorcode);
}

static void m4status_set(uint8_t component, uint8_t status, uint8_t errorcode)
{
    chDbgAssert(m4can_own_id != 0, "m4can_init() hasn't been called");

    /* Check if we should transmit the new status */
    bool transmit_status = false;
    if(components[component] != status) {
        /* Transmit if status has changed since last time */
        transmit_status = true;
    } else if (TIME_I2MS(chVTTimeElapsedSinceX(last_transmit[component])) > 500) {
        /* Transmit if we haven't sent this one in at least 500ms */
        transmit_status = true;
    }

    /* Store new status for this component */
    components[component] = status;

    if(transmit_status) {
        /* Compute overall status as highest of all components */
        uint8_t overall_status = m4status_get();

        uint8_t data[4] = {overall_status, component, status, errorcode};
        uint8_t len = 3;
        if(status == M4STATUS_ERROR) {
            len = 4;
        }

        m4can_send(m4can_own_id | CAN_MSG_ID_STATUS, false, data, len);
        last_transmit[component] = chVTGetSystemTimeX();
    }
}

uint8_t m4status_get_component(uint8_t component) {
    return components[component];
}

uint8_t m4status_get() {
    uint8_t overall_status = 0;
    int i;
    for(i=0; i<256; i++) {
        overall_status |= components[i];
    }
    if(overall_status & M4STATUS_ERROR) {
        overall_status = M4STATUS_ERROR;
    }
    return overall_status;
}
