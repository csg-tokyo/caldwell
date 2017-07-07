/*
 * Display.h
 *
 *  Created on: Mar 27, 2017
 *      Author: Joe
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_

#include "String.h"

class Display {

   public:
      static void show (String const& name, String const& value);

   private:
      static void send (String const& string);
};

#endif /* DISPLAY_H_ */
