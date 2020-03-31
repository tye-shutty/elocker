/* 
	File: adc.c
	Authors: Alexandre Moreira de Carvalho and Tye Shutty
	Implementation of the adc.h header file
*/
#include "adc.h"
#include "fsl_device_registers.h"

void adc_init() {
	SIM_SCGC6 |= SIM_SCGC6_ADC0_MASK;
	SIM_SCGC5 |= SIM_SCGC5_PORTE(1);
	PORTE_PCR24 |= PORT_PCR_MUX(0);
}

uint8_t adc_read() {
	ADC0_SC1A &= ADC_SC1_ADCH(17);
    while(!(ADC0_SC1A & ADC_SC1_COCO_MASK));
    return ADC0_RA;
}
