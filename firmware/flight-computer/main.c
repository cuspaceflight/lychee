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

#include "mpu9250.h"
#include "ms5611.h"
#include "ublox.h"
#include "usbserial.h"

#if DEBUG
#include "debug.h"
#endif

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

#if DEBUG
  DEBUG_INIT;

  /* Debug title block */
  /* This is designed to be a solid 40 char wide block */
  DEBUG_PRINTLN("                                        ");
  DEBUG_PRINTLN(" =======================================");
  DEBUG_PRINTLN(" == Lychee - High-Altitude Ballooning ==");
  DEBUG_PRINTLN(" =======================================");
  DEBUG_PRINTLN(" All work copyright 2022 CU Spaceflight ");
  DEBUG_PRINTLN("        Henry Franks & William Yu       ");
  DEBUG_PRINTLN(" =======================================");
  DEBUG_PRINTLN("                                        ");
#endif


  /* BEGIN INIT */
  mpu9250_init();

#if ENABLE_BARO
  ms5611_init();
#endif

#if ENABLE_GPS
  ublox_init(&SD2);
#endif

#if ENABLE_USB
  usb_init();
#endif
  /*  END INIT  */

  /* START THREADS */
#if ENABLE_BARO
  ms5611_init_thd();
#endif

#if ENABLE_GPS
  //ublox_thd_init();
#endif

#if ENABLE_USB
  usb_thd_init();
#endif

#if ENABLE_BARO
    ms5611_init_thd();
#endif

  while (true) {

    DEBUG_PRINT("0x%04x\r\n", mpu9250_fifo_count());

    chThdSleepMilliseconds(10);
  }
}
