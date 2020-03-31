/* 
	File: solenoid_lock.c
	Authors: Alexandre Moreira de Carvalho and Tye Shutty
	Implementation of the solenoid_lock.h header file
*/

#include "solenoid_lock.h"
#include <stdlib.h>

static lock_t* lock1 = 0;
static lock_t* lock2 = 0;

void open1() {
	set_portc_output(3);
}

void close1() {
	clear_portc_output(3);
}

void open2() {
	set_portc_output(2);
}

void close2() {
	clear_portc_output(2);
}

lock_t* get_solenoid_lock(int number) {
	if (number == 1) {
		if(lock1 == 0) {
			lock1 = (lock_t*) malloc(sizeof(lock_t));
			lock1 -> open = &open1;
			lock1 -> close = &close1;
		}
		return lock1;
   } else {
		if(lock2 == 0) {
			lock2 = (lock_t*) malloc(sizeof(lock_t));
			lock2 -> open = &open2;
			lock2 -> close = &close2;
		}
		return lock2;
   }
}
