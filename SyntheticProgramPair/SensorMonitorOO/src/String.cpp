/*
 * String.cpp
 *
 *  Created on: Mar 27, 2017
 *      Author: Joe
 */

#include "String.h"

String::String (char const* characters) {
   int i = 0;
   while (characters[i++]);

   m_length = i;
   m_characters = new uint8_t[i];

   i = 0;
   while ((m_characters[i] = characters[i++]));
}

String::String (char const* characters, uint32_t length) {

   m_length = length;
   m_characters = new uint8_t[length];

   for(int i = 0; i < length; ++i) {
      m_characters[i] = characters[i++];
   }
}
