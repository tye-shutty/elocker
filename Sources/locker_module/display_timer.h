/* 
	File: display_timer.h
	Authors: Alexandre Moreira de Carvalho and Tye Shutty
	This module is an abstraction for the flextimer module 
	and is used to represent a delay timer to be used by the 
	system. Delay times are given in milliseconds. The 
	module ensures that only a single	instance of the timer
	is created.
*/

#ifndef SOURCES_ABSTRACTION_LAYER_DISPLAY_TIMER_H_
#define SOURCES_ABSTRACTION_LAYER_DISPLAY_TIMER_H_

#include <stdint.h>

typedef struct timer_struct {
	void (*delay) (int time);
} timer_t;

timer_t* get_timer();

#endif /* SOURCES_ABSTRACTION_LAYER_DISPLAY_TIMER_H_ */
