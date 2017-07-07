/*
 * DataBus.h
 *
 *  Created on: Mar 27, 2017
 *      Author: Joe
 */

#ifndef DATABUS_H_
#define DATABUS_H_

#include <stdint.h>

class DataBus {
   public:
      static void read (uint8_t* buffer, uint8_t address, uint16_t start, uint16_t length);
};



#endif /* DATABUS_H_ */
