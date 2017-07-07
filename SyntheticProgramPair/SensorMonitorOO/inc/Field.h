/*
 * Field.h
 *
 *  Created on: Mar 27, 2017
 *      Author: Joe
 */

#ifndef FIELD_H_
#define FIELD_H_

#include <stdint.h>
#include "FieldType.h"
#include "String.h"

class Field {

   public:
      Field (String const& name, FieldType type, uint16_t address, uint8_t length);

   public:
      inline uint16_t address () const { return m_address; }
      inline uint8_t length () const { return m_length; }
      inline String const& name () const { return m_name; }

   public:
      void update (uint8_t* data);
      String toString() const;

   private:
      String m_name;
      FieldType m_type;
      uint16_t m_address;
      uint8_t m_length;
      uint8_t m_buffer[8];
};



#endif /* FIELD_H_ */
