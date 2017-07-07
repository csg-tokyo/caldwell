/*
 * utility.h
 *
 *  Created on: Jul 6, 2017
 *      Author: Joe
 */

#ifndef INC_UTILITY_H_
#define INC_UTILITY_H_

#include <stdint.h>
#include "String.h"

inline uint32_t ConvertToLittleEndian (uint32_t value) {
   asm (
      "rev %[output], %[value]"
      : [output] "=r" (value)
      : [value] "r" (value)
   );

   return value;
}

String ConvertIntegerToString (int32_t data);
String ConvertBoolToString (bool data, const char* t = "true", const char* f = "false");

#endif /* INC_UTILITY_H_ */
