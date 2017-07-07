/*
 * display.cpp
 *
 *  Created on: Mar 30, 2017
 *      Author: Joe
 */

#include <stdint.h>

#define STATUS_SENDBSY 0x1
#define STATUS_RECVBSY 0x2

uint8_t volatile* const bufferRegister = (uint8_t*) 0x20000;
uint8_t volatile* const statusRegister = (uint8_t*) 0x20001;

void send (char const* string) {
   while (*string) {
      while (*statusRegister & STATUS_SENDBSY);
      *bufferRegister = *string++;
   }
}

void show (char const* name, char const* value) {

   send(name);
   send(": ");
   send(value);
}

