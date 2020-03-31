/* 
	File: gpio.c
	Authors: Alexandre Moreira de Carvalho and Tye Shutty
	Implementation of the gpio.h header file
*/

#include "gpio.h"
#include "fsl_device_registers.h"

void gpio_init() {
	SIM_SCGC5 |= SIM_SCGC5_PORTC(1);
	SIM_SCGC5 |= SIM_SCGC5_PORTB(1);

	// Solenoid pints
	PORTC_PCR3 |= PORT_PCR_MUX(1);
	GPIOC_PDDR |= 0x01 << 3;

	PORTC_PCR2 |= PORT_PCR_MUX(1);
	GPIOC_PDDR |= 0x01 << 2;

	// Keypad pins
	// Inputs
	PORTC_PCR11 |= PORT_PCR_MUX(1);
	PORTC_PCR10 |= PORT_PCR_MUX(1);
	PORTB_PCR11 |= PORT_PCR_MUX(1);
	PORTB_PCR10 |= PORT_PCR_MUX(1);

	//Outputs
	PORTC_PCR9 |= PORT_PCR_MUX(1);
	PORTC_PCR0 |= PORT_PCR_MUX(1);
	PORTC_PCR7 |= PORT_PCR_MUX(1);
	PORTC_PCR5 |= PORT_PCR_MUX(1);

	GPIOC_PDDR |= 0x01 << 9;
	GPIOC_PDDR |= 0x01 << 0;
	GPIOC_PDDR |= 0x01 << 7;
	GPIOC_PDDR |= 0x01 << 5;

};

void set_portb_output(int pin) {
	GPIOB_PSOR |= 0x01 << pin;
};

void set_portc_output(int pin) {
	GPIOC_PSOR |= 0x01 << pin;
};

void clear_portb_output(int pin) {
	GPIOB_PCOR |= 0x01 << pin;
};

void clear_portc_output(int pin) {
	GPIOC_PCOR |= 0x01 << pin;
};

int get_portb_input(int pin) {
	return GPIOB_PDIR & (1 << pin);
}

int get_portc_input(int pin) {
	return GPIOC_PDIR & (1 << pin);
}
