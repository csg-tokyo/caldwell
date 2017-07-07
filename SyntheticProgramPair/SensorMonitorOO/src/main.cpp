/*
 * main.cpp
 *
 *  Created on: Mar 27, 2017
 *      Author: Joe
 */

#include "SensorManager.h"
#include "Sensor.h"
#include "Field.h"

int main () {

   Sensor currentSensor ("Current", 1);
   currentSensor.addField(new Field("ID",        FieldType::STRING,  0x1000, 4));
   currentSensor.addField(new Field("Phase 1",   FieldType::INTEGER, 0x1004, 4));
   currentSensor.addField(new Field("Phase 2",   FieldType::INTEGER, 0x1008, 4));
   currentSensor.addField(new Field("Peak",      FieldType::INTEGER, 0x100C, 4));
   currentSensor.addField(new Field("Overload",  FieldType::YES_NO,  0x1010, 1));
   currentSensor.addField(new Field("Filtering", FieldType::ON_OFF,  0x1011, 1));

   SensorManager manager;
   manager.addSensor(&currentSensor);

   manager.run();

   return 0;
}


