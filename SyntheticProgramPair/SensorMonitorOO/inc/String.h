/*
 * String.h
 *
 *  Created on: Mar 27, 2017
 *      Author: Joe
 */

#ifndef STRING_H_
#define STRING_H_

#include <stdint.h>

class String {

   public:
      String (char const* characters);
      String (char const* characters, uint32_t length);

   public:
      inline uint32_t length () const { return m_length; }

   public:
      inline char operator[] (uint32_t index) const { return m_characters[index]; }

   private:
      uint8_t* m_characters;
      uint32_t m_length;
};



#endif /* STRING_H_ */
