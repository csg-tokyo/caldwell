/*
 * Sensor.cpp
 *
 *  Created on: Mar 27, 2017
 *      Author: Joe
 */

#include "Sensor.h"
#include "Display.h"

Sensor::Sensor (String const& name, uint8_t address): m_name(name), m_address (address) {

}

void Sensor::addField (Field* field) {
   m_fields.add(field);

   if (field->address() < m_fieldStart || m_fieldLength == 0) {
      m_fieldStart = field->address();
   }

   if (field->address() + field->length() > m_fieldStart + m_fieldLength) {
      m_fieldLength = field->address() + field->length() - m_fieldStart;
   }
}

void Sensor::update (uint8_t* buffer, uint16_t start, uint16_t length) {
   for (int i = 0; i < m_fields.size(); ++i) {
      Field* field = m_fields[i];

      if (field->address() < start || field->address() >= start + length)
         continue;

      uint8_t* address = buffer + (field->address() - start);
      field->update(address);
      Display::show(field->name(), field->toString());
   }
}
