#ifndef SOURCES_LOCKER_MODULE_KEYPAD_H_
#define SOURCES_LOCKER_MODULE_KEYPAD_H_

#include <stdlib.h>
#include "hardware_layer/gpio.h"

typedef struct keypad_struct {
	char (*get_key) ();
	char (*get_debounced_key) ();
} keypad_t;

keypad_t* get_keypad();


#endif /* SOURCES_LOCKER_MODULE_KEYPAD_H_ */
