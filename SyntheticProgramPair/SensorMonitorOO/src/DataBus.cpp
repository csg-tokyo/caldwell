/*
 * DataBus.cpp
 *
 *  Created on: Mar 27, 2017
 *      Author: Joe
 */

#include "DataBus.h"

uint8_t const STATUS_SENDBSY = 0x1;
uint8_t const STATUS_RECVBSY = 0x2;

uint8_t volatile* const bufferRegister = (uint8_t*) 0x2000;
uint8_t volatile* const statusRegister = (uint8_t*) 0x2001;

void DataBus::read (uint8_t* buffer, uint8_t address, uint16_t start, uint16_t length) {
   *bufferRegister = address;
   while (*statusRegister & STATUS_SENDBSY);

   *bufferRegister = start >> 8;
   while (*statusRegister & STATUS_SENDBSY);

   *bufferRegister = start & 0xFF;
   while (*statusRegister & STATUS_SENDBSY);

   for (int i = 0; i < length; ++i) {
      while (*statusRegister & STATUS_RECVBSY);
      buffer[i] = *bufferRegister;
   }
}
