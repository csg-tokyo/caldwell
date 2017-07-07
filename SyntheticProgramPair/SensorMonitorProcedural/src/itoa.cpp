/*
 * itoa.cpp
 *
 *  Created on: Jul 7, 2017
 *      Author: Joe
 */

#include "itoa.h"

uint32_t itoa (int32_t data, char* stringbuffer, uint32_t length) {
   char negative = data < 0 ? 1 : 0;
   int32_t number = data;

   if (negative) {
      number = -data;
   }

   if (number == 0) {
      stringbuffer[0] = '\0';
      return 1;
   }

   int measuredLength = 0;
   int32_t originalNumber = number;
   while (number > 0) {
      measuredLength++;
      number /= 10;
   }

   if (negative)
      measuredLength++;

   if (measuredLength > length)
      return 0;

   int position = measuredLength;
   number = originalNumber;
   stringbuffer[position--] = '\0';

   while (number > 0) {
     int a = (number % 10);
     stringbuffer[position--] = a | '0';
     length++;
     number /= 10;
   }

   if (negative) {
      stringbuffer[0] = '-';
      length++;
   }

   return measuredLength;
}



