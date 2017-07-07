/*
 * utility.cpp
 *
 *  Created on: Jul 7, 2017
 *      Author: Joe
 */

#include "utility.h"

String ConvertIntegerToString (int32_t data) {
   bool negative = data < 0;
   int32_t number = data;

   if (negative) {
      number = -data;
   }

   if (number == 0) {
      return String("0");
   }

   char buffer[12];
   int length = 0;

   buffer[11] = '\0';
   while (number > 0) {
     int a = (number % 10);
     buffer[10 - length] = a | '0';
     length++;
     number /= 10;
   }

   if (negative) {
      buffer[10 - length] = '-';
      length++;
   }

   char* characters = buffer + (11 - length);
   return String(characters);
}

String ConvertBoolToString (bool data, char const* t, char const* f) {
   return String(data ? t : f);
}
