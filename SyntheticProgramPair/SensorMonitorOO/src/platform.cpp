/*
 * new.cpp
 *
 *  Created on: Mar 29, 2017
 *      Author: Joe
 */

#include <stdint.h>
typedef unsigned int size_t;

uint8_t* g_heap_memory[8096];
uint32_t position;

void* operator new (size_t size) {
   uint32_t allocatedPosition = position;
   position += size;

   return (void*) g_heap_memory[allocatedPosition];
}

void* operator new[] (size_t size) {
   return operator new(size);
}

void operator delete (void* pointer) {
   // Do nothing! This platform can only allocate statically.
}

