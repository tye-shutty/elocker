/* 
	File: adc.h
  Authors: Alexandre Moreira de Carvalho and Tye Shutty
	This module is responsible to initialize the ADC0 at PTE24
	on channel 17 and enable calls to read the value in the ADC.
  The ADC is configured to operate in the single-ended 8-bit mode
*/

#include <stdint.h>

#ifndef SOURCES_LOCKER_MODULE_HARDWARE_LAYER_ADC_H_
#define SOURCES_LOCKER_MODULE_HARDWARE_LAYER_ADC_H_

void adc_init();
uint8_t adc_read();

#endif /* SOURCES_LOCKER_MODULE_HARDWARE_LAYER_ADC_H_ */
