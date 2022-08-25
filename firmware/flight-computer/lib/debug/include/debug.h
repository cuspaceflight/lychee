#ifndef DEBUG_H_
#define DEBUG_H_

#include "chprintf.h"

#define DEBUG_SERIAL &SD4

#define DEBUG_INIT sdStart(DEBUG_SERIAL, NULL) //Debug on serial 4

#define DEBUG_PRINT(...)   chprintf((BaseSequentialStream *)DEBUG_SERIAL, __VA_ARGS__)
#define DEBUG_PRINTLN(x) DEBUG_PRINT(x "\r\n")

#endif /* DEBUG_H_ */
