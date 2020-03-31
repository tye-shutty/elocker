/* 
	File: keypad.h
	Authors: Alexandre Moreira de Carvalho and Tye Shutty
	This module is an abstraction for the keypad. The module 
	implements a method get the key that was pressedand it
	debounces the input. The module ensures that only a single
	instance of the keypad is created.
*/
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
