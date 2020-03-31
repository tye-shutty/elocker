/* 
	File: flexTimer.c
	Authors: Alexandre Moreira de Carvalho and Tye Shutty
	Implementation of the flexTimer.h header file
*/

#include "MK64F12.h"

float SYSTEM_CLOCK = 20971520.00f;

/*
 * Creates an output compare timer.
 */
void FTM3_OutComp_init() {
	// Clock Enable for FTM3
	SIM_SCGC3 |= SIM_SCGC3_FTM3_MASK;

	// Port and Pin Configuration - PTD0
	SIM_SCGC5 |= SIM_SCGC5_PORTD(1);
	PORTD_PCR0 |= PORT_PCR_MUX(4);

	float frequency = 1000.0f;
	int mod = SYSTEM_CLOCK / frequency;
	FTM3_MOD = mod;
	FTM3_CNTIN = 0x0;

	// Timer Configuration
	FTM3_SC |= 0x0008 ; // Use system clock prescaled by 1
	FTM3_C0SC |= (FTM_CnSC_ELSA(1) | FTM_CnSC_MSA(1));
}

void FTM3_OutComp_disable() {
	FTM3_CNT = 0;
	FTM3_SC |= FTM_SC_CLKS(0); // Disables clock
}

/*
 *  Creates a delay by time in milliseconds
 */
void my_delay(int time) {
	// Create Timer
	FTM3_OutComp_init();
	int counter = time;
	while (counter > 0) {
		// Wait for clock overflow.
		while(!(FTM3_SC & FTM_SC_TOF_MASK));
		counter--;
		int sc = FTM3_SC;
		FTM3_SC ^= FTM_SC_TOF_MASK;
	}
	FTM3_OutComp_disable();
	return;
}
