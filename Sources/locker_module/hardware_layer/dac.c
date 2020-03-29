#include "dac.h"
#include "MK64F12.h"

float sysClock = 20971520.00f;

/*
 * This module initializes the DAC0 and the PIT0
 */
void dac_init() {
	SIM_SCGC2 |= SIM_SCGC2_DAC0_MASK;
	SIM_SCGC6 |= SIM_SCGC6_PIT_MASK;
	DAC0_C0 |= DAC_C0_DACEN_MASK;
	DAC0_C0 |= DAC_C0_DACRFS_MASK;
}

/*
 * The combined DAC and PIT generates a sine wave at the
 * frequency passed in Hz that lasts for the passed in time
 * in microseconds.
 */
void dac_out(int frequency, float time) {
	uint16_t index = 0;
	PIT_MCR= 0x00;
	float delay = (1000000.00f / frequency) / 1024.00f;
	float clockPeriod = 1000000000.00f / sysClock;
	PIT_LDVAL0 = (delay * 1000.00f) / clockPeriod - 1;
	PIT_TCTRL0 |= PIT_TCTRL_TIE_MASK;
	PIT_TCTRL0 |= PIT_TCTRL_TEN_MASK;

	while(time > 0) {
		while(PIT_TFLG(0) == 0); // wait for the interrupt
		DAC0_DATL(0) = 0xFF & dac_data[index];
		DAC0_DATH(0) = dac_data[index] >> 8;
		index++;
		if(index == 1024) index = 0;
		time = time - delay;
		PIT_TFLG0 |= PIT_TFLG_TIF_MASK; // clear interrupt flag
	};
	PIT_TCTRL0 ^= PIT_TCTRL_TEN_MASK; // disable the timer
}

