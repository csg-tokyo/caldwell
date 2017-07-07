/*
 * SensorManager.cpp
 *
 *  Created on: Mar 27, 2017
 *      Author: Joe
 */

#include "SensorManager.h"

SensorManager::SensorManager () {

}

void SensorManager::addSensor(Sensor* sensor) {
   m_sensors.add(sensor);
}

void SensorManager::run () {
   uint8_t buffer[1024];

   while (true) {
      for (int i = 0; i < m_sensors.size(); ++i) {
         Sensor* sensor = m_sensors[i];
         uint8_t address = sensor->address();

         DataBus::read(buffer, address, sensor->fieldStart(), sensor->fieldLength());
         sensor->update(buffer, sensor->fieldStart(), sensor->fieldLength());
      }
   }
}


