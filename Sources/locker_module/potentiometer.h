/* 
	File: potentiometer.h
	Authors: Alexandre Moreira de Carvalho and Tye Shutty
	This module is an abstraction for the potentiometer. The module 
	utilizes the adc module to retrieve the current value of
	the potentiometer.The module ensures that only a single
	instance of the potentiometer is created.
*/

#ifndef SOURCES_LOCKER_MODULE_POTENTIOMETER_H_
#define SOURCES_LOCKER_MODULE_POTENTIOMETER_H_

#include <stdlib.h>
#include "hardware_layer/adc.h"

typedef struct pot_struct {
	uint8_t (*read_value) ();
} pot_t;

pot_t* get_pot();

#endif /* SOURCES_LOCKER_MODULE_POTENTIOMETER_H_ */
