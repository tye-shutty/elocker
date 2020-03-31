/* 
	File: display_timer.c
	Authors: Alexandre Moreira de Carvalho and Tye Shutty
	Implementation of the display_timer.h header file
*/

#include <stdlib.h>
#include "display_timer.h"
#include "hardware_layer/flexTimer.h"

static timer_t* this = 0;

void delay(int time) {
    return my_delay(time);
}

timer_t* get_timer() {
   if(this == 0) {
    	this = (timer_t*) malloc(sizeof(timer_t));
      this -> delay = &delay;
    }
    return this;
}
