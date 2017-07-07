/*
 * Sensor.h
 *
 *  Created on: Mar 27, 2017
 *      Author: Joe
 */

#ifndef SENSOR_H_
#define SENSOR_H_

#include <stdint.h>
#include "String.h"
#include "Field.h"
#include "List.h"

class Sensor {

   public:
      Sensor (String const& name, uint8_t address);

   public:
      void addField (Field* field);
      void update (uint8_t* buffer, uint16_t start, uint16_t length);

   public:
      inline uint8_t address () const { return m_address; }

   public:
      inline uint16_t fieldStart () const { return m_fieldStart; }
      inline uint16_t fieldLength () const { return m_fieldLength; }
      inline uint32_t fieldCount () const { return m_fields.size(); }
      inline Field const* operator[] (int index) const { return m_fields[index]; }

   private:
      String m_name;
      uint8_t m_address;
      uint16_t m_fieldStart;
      uint16_t m_fieldLength;
      List<Field*> m_fields;
};



#endif /* SENSOR_H_ */
