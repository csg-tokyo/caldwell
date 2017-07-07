/*
 * Field.cpp
 *
 *  Created on: Mar 27, 2017
 *      Author: Joe
 */

#include "Field.h"
#include "Display.h"
#include "utility.h"

Field::Field(String const& name, FieldType type, uint16_t address, uint8_t length):
   m_name (name),
   m_type (type),
   m_address(address),
   m_length (length)
{

}

void Field::update(uint8_t* data) {
   for (int i = 0; i < this->m_length; ++i) {
      this->m_buffer[i] = data[i];
   }
}

String Field::toString() const {

   switch (this->m_type) {
      case FieldType::INTEGER: {
         int32_t data = ConvertToLittleEndian(*((int32_t*)this->m_buffer));
         return ConvertIntegerToString(data);
      }

      case FieldType::STRING: {
         return String((char const*) m_buffer);
      }

      case FieldType::BOOL: {
         return ConvertBoolToString(m_buffer[0] != 0);
      }

      case FieldType::YES_NO: {
         return ConvertBoolToString(m_buffer[0] != 0, "yes", "no");
      }

      case FieldType::ON_OFF: {
         return ConvertBoolToString(m_buffer[0] != 0, "on", "off");
      }

      default: {
         return String("");
      }
   }
}

