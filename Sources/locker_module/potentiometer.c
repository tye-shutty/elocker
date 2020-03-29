#include "potentiometer.h"

static pot_t* this = 0;

void init_potentiometer() {
	adc_init();
}

uint8_t read_value() {
    return adc_read();
}

pot_t* get_pot() {
   if(this == 0) {
    	init_potentiometer();

    	this = (pot_t*) malloc(sizeof(pot_t));
        this -> read_value = &read_value;
    }
    return this;
}
