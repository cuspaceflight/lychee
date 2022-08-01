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
int main(void)
{

  /*
   * System initializations.
   * - HAL initialization, this also initializes the configured device drivers
   *   and performs the board-specific initializations.
   */
  halInit();
  chSysInit();

  //Debug on serial 4
  sdStart(&SD4, NULL);

  /* Debug title block */
  /* This is designed to be a solid 40 char wide block */
  chprintf(&SD4, "                                        \r\n");
  chprintf(&SD4, " =======================================\r\n");
  chprintf(&SD4, " == Lychee - High-Altitude Ballooning ==\r\n");
  chprintf(&SD4, " =======================================\r\n");
  chprintf(&SD4, " All work copyright 2022 CU Spaceflight \r\n");
  chprintf(&SD4, " Henry Franks & William Yu              \r\n");
  chprintf(&SD4, " =======================================\r\n");
  chprintf(&SD4, "                                        \r\n");

  /* === BEGIN  U-blox (GPS)  BEGIN === */

#ifdef __BYTE_ORDER__
    if (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__)
      chprintf(&SD4, "Big Endian System\r\n");
    else
      chprintf(&SD4, "Little Endian System\r\n");
#else
    chprintf(&SD4, "BYTE_ORDER not defined\r\n");
#endif

  ublox_init(&SD2);
//  ublox_thd_init();

  /* ===  END   U-blox (GPS)   END  === */

  /*
   * Normal main() thread activity, in this demo it just performs
   * a shell respawn upon its termination.
   */
  while (true) {}
}
