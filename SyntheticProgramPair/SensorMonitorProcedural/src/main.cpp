/*
 * main.cpp
 *
 *  Created on: Mar 30, 2017
 *      Author: Joe
 */
#include <stdint.h>
#include "databus.h"
#include "display.h"
#include "new.h"
#include "arm.h"
#include "itoa.h"

#define FIELD_TYPE_INTEGER 1
#define FIELD_TYPE_BOOL    2
#define FIELD_TYPE_ON_OFF  3
#define FIELD_TYPE_YES_NO  4
#define FIELD_TYPE_STRING  5

struct field_range {
   char const* name;
   uint8_t address;
   uint16_t start;
   uint16_t length;
};

struct field {
   char const* name;
   uint16_t address;
   uint8_t type;
   uint16_t length;
};

field_range* field_ranges;
uint16_t field_range_count;

field fields[][7] = {
      {
         { "ID", 0x1000, FIELD_TYPE_STRING, 4 },
         { "Phase 1", 0x1004, FIELD_TYPE_INTEGER, 4 },
         { "Phase 2", 0x1008, FIELD_TYPE_INTEGER, 4 },
         { "Peak", 0x100C, FIELD_TYPE_INTEGER, 4 },
         { "Overload", 0x1010, FIELD_TYPE_YES_NO, 1 },
         { "Filtering", 0x1011, FIELD_TYPE_ON_OFF, 1 },
         { 0, 0, 0 },
      }
};

void update_field (struct field* f, uint8_t* data) {

   char stringbuffer[8];
   char const* buffer = 0;
   char const* name = f->name;

   switch (f->type) {
      case FIELD_TYPE_INTEGER: {
         char stringbuffer[8];
         int32_t i = to_little_endian (*((int32_t*)data));
         itoa(i, stringbuffer, 8);
         buffer = stringbuffer;
         break;
      }

      case FIELD_TYPE_BOOL:
         if (data[0] == 0)
            buffer = "false";
         else
            buffer = "true";
         break;

      case FIELD_TYPE_ON_OFF:
         if (data[0] == 0)
            buffer = "on";
         else
            buffer = "off";
         break;

      case FIELD_TYPE_YES_NO:
         if (data[0] == 0)
            buffer = "yes";
         else
            buffer = "no";
         break;

      case FIELD_TYPE_STRING:
         buffer = (char const*) data;
         break;

      default:
         break;
   }

   show(name, stringbuffer);
}

void update_range (uint8_t* buffer, uint16_t sensorID, uint16_t start, uint16_t length) {
   int i = 0;
   uint16_t end = start + length;
   while(1) {
      struct field f = fields[sensorID][i];

      if (f.name == 0)
         break;

      if (f.address < start || f.address >= end)
         continue;

      uint8_t* address = buffer + (f.address - start);
      update_field(&f, address);
      i++;
   }
}

void main_loop () {

   while (true) {
      for (int i = 0; i < field_range_count; ++i) {
         uint8_t* data = read_databus(field_ranges[i].address, field_ranges[i].start, field_ranges[i].length);
         update_range(data, i, field_ranges[i].start, field_ranges[i].length);
      }
   }
}

int main () {
   field_range_count = 1;
   field_ranges = (field_range*) calloc(field_range_count, sizeof(field_range));

   field_ranges[0].name = "Current";
   field_ranges[0].address = 0x01;
   field_ranges[0].start = 0x1000;
   field_ranges[0].length = 13;

   main_loop();
}


