/* 
	File: solenoid_lock.h
	Authors: Alexandre Moreira de Carvalho and Tye Shutty
	This module is an abstraction for the solenoids. 
	The module implements two functions: open and close, to 
	indicate the action required by the lock. It uses the
	gpio module, and only two instances are allowed to be
	created: one for the locker 1 and one for the locker 2.
*/
#ifndef SOURCES_LOCKER_MODULE_SOLENOID_LOCK_H_
#define SOURCES_LOCKER_MODULE_SOLENOID_LOCK_H_

#include "hardware_layer/gpio.h"

typedef struct lock_struct {
	void (*open) ();
	void (*close) ();
} lock_t;

lock_t* get_solenoid_lock(int lock_number);


#endif /* SOURCES_LOCKER_MODULE_SOLENOID_LOCK_H_ */
