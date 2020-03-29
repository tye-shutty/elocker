#ifndef SOURCES_LOCKER_MODULE_SOLENOID_LOCK_H_
#define SOURCES_LOCKER_MODULE_SOLENOID_LOCK_H_

#include "hardware_layer/gpio.h"

typedef struct lock_struct {
	void (*open) ();
	void (*close) ();
} lock_t;

lock_t* get_solenoid_lock(int lock_number);


#endif /* SOURCES_LOCKER_MODULE_SOLENOID_LOCK_H_ */
