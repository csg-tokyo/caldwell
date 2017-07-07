/*
 * Display.cpp
 *
 *  Created on: Mar 27, 2017
 *      Author: Joe
 */

/*
 * display.cpp
 *
 *  Created on: Mar 30, 2017
 *      Author: Joe
 */

#include "Display.h"
#include <stdint.h>

uint8_t const STATUS_SENDBSY = 0x1;
uint8_t const STATUS_RECVBSY = 0x2;

uint8_t volatile* const bufferRegister = (uint8_t*) 0x20000;
uint8_t volatile* const statusRegister = (uint8_t*) 0x20001;

void Display::send (String const& string) {
   for (int i = 0; i < string.length(); ++i) {
      while (*statusRegister & STATUS_SENDBSY);
      *bufferRegister = string[i];
   }
}

void Display::show (String const& name, String const& value) {
   send(name);
   send(": ");
   send(value);
}
