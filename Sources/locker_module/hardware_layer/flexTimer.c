/*
 * Author: Alexandre Moreira de Carvalho
 * ID: 3617182
 * Date: March 06, 2020
 * Description: This module can be used to initialize the Flex Timer module in the FRDM board
 *
 */

#include "MK64F12.h"

float SYSTEM_CLOCK = 20971520.00f;

/*
 * Creates an input capture timer on PTC1 pin.
 */
void InputCaptureTimer_Init() {
	// Clock Enable for FTM0
	SIM_SCGC6 |= SIM_SCGC6_FTM0_MASK;

	// Port and Pin Configuration - PTC1
	SIM_SCGC5 |= SIM_SCGC5_PORTC(1);
	PORTC_PCR1 |= PORT_PCR_MUX(4);

	/*
	 * Free Running Setup
	 * FTMEN = 1, QUADEN = 0, CPWMS = 0, CNTIN = 0x0000, MOD = 0xFFFF
	 */
	FTM0_MOD = 0xffff;
	FTM0_MODE |= FTM_MODE_FTMEN(1);

	// Timer Configuration
	FTM0_SC |= 0x000B ; // Use system clock prescaled by 8
	// Input Capture on Rising and Falling Edge
	FTM0_C0SC |= (FTM_CnSC_ELSA(1) | FTM_CnSC_ELSB(1));
	FTM0_CNTIN = 0x0;
}

void InputCaptureTimer_Disable() {
	FTM0_CNT = 0;
	FTM0_SC |= FTM_SC_CLKS(0); // Disables clock
	// need reset
}

/*
 * Creates an output compare timer on PTD0 pin.
 */
void FTM0_OutComp_init() {
	// Clock Enable for FTM0
	SIM_SCGC6 |= SIM_SCGC6_FTM0_MASK;
	SIM_SCGC5 |= SIM_SCGC5_PORTC(1);
	PORTC_PCR1 |= PORT_PCR_MUX(4);

	float frequency = 1000.0f;
	int mod = SYSTEM_CLOCK / frequency;
	FTM0_MOD = mod;
	FTM0_CNT = 0;
	FTM0_CNTIN = 0x0;
	// Timer Configuration
	FTM0_SC |= 0x0008 ; // Use system clock prescaled by 1
	FTM0_C0SC |= (FTM_CnSC_ELSA(1) | FTM_CnSC_MSA(1));
}

void FTM0_OutComp_disable() {
	FTM0_CNT = 0;
	FTM0_SC |= FTM_SC_CLKS(0); // Disables clock
}

void FTM0_wait() {
	while(!(FTM0_SC & FTM_SC_TOF_MASK));
	int sc = FTM0_SC;
	FTM0_SC ^= FTM_SC_TOF_MASK;
	return;
}

/*
 * Creates an output compare timer on PTD0 pin.
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
 *  Generates a 1kHz PWM signal on PTB18
 */
void PMWGenerator1kHZ() {
	// Clock Enable for FTM2
	SIM_SCGC6 |= SIM_SCGC6_FTM2_MASK;

	// Port and Pin Configuration - PTB18
	SIM_SCGC5 |= SIM_SCGC5_PORTB(1);
	PORTB_PCR18 |= PORT_PCR_MUX(3);
	GPIOB_PDDR |= 0x01 << 18;

	FTM2_CNTIN = 0x0;
	float frequency = 1000.0f;
	int mod = SYSTEM_CLOCK/128/frequency - 1;
	FTM2_MOD = mod;

	// Timer Configuration
	FTM2_SC |= 0x000F ; // Use system clock / 128
	FTM2_C0SC |= FTM_CnSC_ELSB(1) | FTM_CnSC_MSB(1);  // e pwm
	int Cnv = mod/2;
	FTM2_C0V = Cnv;
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

// Returns the pulse width in microseconds
float MeasurePulse() {
	// Wait for Rising edge event: Start of Pulse
	while(!(FTM0_C0SC & FTM_CnSC_CHF_MASK));
	FTM0_C0SC ^= FTM_CnSC_CHF_MASK;
	int start = FTM0_C0V;

	//FTM0_CNT |= 0x1;
	// Wait for falling edge event: End of Pulse
	while(!(FTM0_C0SC & FTM_CnSC_CHF_MASK));
	FTM0_C0SC ^= FTM_CnSC_CHF_MASK;
	int end = FTM0_C0V;
	float elapsed = (end-start) / (SYSTEM_CLOCK/(1e6* 8));
	return elapsed;
}

