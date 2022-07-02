/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#include "hal.h"
#include "ch.h"
#include "chprintf.h"

#include "ublox.h"


/*
 * Application entry point.
 */
int main(void) {

  /*
   * System initializations.
   * - HAL initialization, this also initializes the configured device drivers
   *   and performs the board-specific initializations.
   */
  halInit();
  chSysInit();

  //Debug on serial 4
  sdStart(&SD4, NULL);

  sdWrite(&SD4, (uint8_t *)"Init ublox\r\n", 12);

  ublox_init(&SD2);
  sdWrite(&SD4, (uint8_t *)"Done\r\n", 6);
  ublox_thd_init();
  sdWrite(&SD4, (uint8_t *)"Thd\r\n", 5);

  /*
   * Normal main() thread activity, in this demo it just performs
   * a shell respawn upon its termination.
   */
  while (true) {
    //sdWrite(&SD4, (uint8_t *)"Main\r\n", 6);
    chThdSleepMilliseconds(500);

  }
}
