/*
 * SensorManager.h
 *
 *  Created on: Mar 27, 2017
 *      Author: Joe
 */

#ifndef SENSORMANAGER_H_
#define SENSORMANAGER_H_

#include "Sensor.h"
#include "Display.h"
#include "DataBus.h"

class SensorManager {

   public:
      SensorManager ();

   public:
      void addSensor (Sensor* sensor);
      void run ();

   private:
      void updateAll();

   private:
      List<Sensor*> m_sensors;
      Display* m_display;
};

#endif /* SENSORMANAGER_H_ */
