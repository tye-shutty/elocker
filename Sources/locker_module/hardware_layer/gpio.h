/* 
	File: gpio.h
	Authors: Alexandre Moreira de Carvalho and Tye Shutty
	This module is responsible to initialize the GPIO pins
	PTC11, PTC10, PTB11 and PTB10 as input pins, and PTC9,
	PTC0, PTC7 and PTC5 as outputs to be used	by a 4x4 matrix
	keypad. It also initializes PTC2 and PTC3 as output pins
	to control the solenoid locks. The module permits pins 
  in port B and port C to be read, set or cleared, by providing
  the pin number as input.
*/

#ifndef SOURCES_LOCKER_MODULE_HARDWARE_LAYER_GPIO_H_
#define SOURCES_LOCKER_MODULE_HARDWARE_LAYER_GPIO_H_

void gpio_init();
void set_portb_output(int pin);
void set_portc_output(int pin);
void clear_portb_output(int pin);
void clear_portc_output(int pin);
int get_portb_input(int pin);
int get_portc_input(int pin);

#endif /* SOURCES_LOCKER_MODULE_HARDWARE_LAYER_GPIO_H_ */
