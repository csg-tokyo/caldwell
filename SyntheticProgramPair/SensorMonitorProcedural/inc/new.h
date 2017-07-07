/*
 * new.h
 *
 *  Created on: Jul 7, 2017
 *      Author: Joe
 */

#ifndef INC_NEW_H_
#define INC_NEW_H_

#include <stdint.h>
typedef int32_t size_t;

void* malloc (size_t size);
void* calloc (size_t num, size_t size);
void free (void* pointer);



#endif /* INC_NEW_H_ */
