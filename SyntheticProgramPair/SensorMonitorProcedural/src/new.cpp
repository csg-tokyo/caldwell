/*
 * new.cpp
 *
 *  Created on: Mar 29, 2017
 *      Author: Joe
 */

#include "new.h"

uint8_t* g_heap_memory[8096];
uint32_t position;

void* malloc (size_t size) {
   uint32_t allocatedPosition = position;
   position += size;

   return (void*) g_heap_memory[allocatedPosition];
}

void* calloc (size_t num, size_t size) {
   return malloc(num * size);
}

void free (void* pointer) {
   // Do nothing! This platform can only allocate statically.
}


