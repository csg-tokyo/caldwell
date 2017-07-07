/*
 * arm.cpp
 *
 *  Created on: Jul 7, 2017
 *      Author: Joe
 */


#include "arm.h"
#include <stdint.h>

uint32_t to_little_endian (uint32_t value) {
   asm (
      "rev %[output], %[value]"
      : [output] "=r" (value)
      : [value] "r" (value)
   );

   return value;
}

