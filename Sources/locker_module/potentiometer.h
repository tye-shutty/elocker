#ifndef SOURCES_LOCKER_MODULE_POTENTIOMETER_H_
#define SOURCES_LOCKER_MODULE_POTENTIOMETER_H_

#include <stdlib.h>
#include "hardware_layer/adc.h"

typedef struct pot_struct {
	uint8_t (*read_value) ();
} pot_t;

pot_t* get_pot();

#endif /* SOURCES_LOCKER_MODULE_POTENTIOMETER_H_ */
