/* 
	File: uart.c
	Authors: Alexandre Moreira de Carvalho
	Implementation of the uart.h header file
*/
#include "MK64F12.h"
#include "fsl_device_registers.h"

void uart_init() {
	// Enabling clock for the UART
	SIM_SCGC4 |= SIM_SCGC4_UART0(1);

	// Enabling port B
	SIM_SCGC5 |= SIM_SCGC5_PORTB(1);

	// Configuring port E pins to UART alternate
	PORTB_PCR16 |= PORT_PCR_MUX(3); // Setting pin16 of PortB to UART0_TX
	PORTB_PCR17 |= PORT_PCR_MUX(3); // Setting pin17 of PortB to UART0_RX

	// Setting BAUD rate to 9600 bauds
	UART0_BDH = 0;
	UART0_BDL = 0x88;

	// Enabling transmit and receive
	UART0_C2 |= UART_C2_TE(1);
}

void uart_put_char(char c) {
	// Write the char to the UART0 data register
	while(!(UART0_S1 & UART_S1_TDRE_MASK));
	UART0_D = c;
	while(!(UART0_S1 & UART_S1_TDRE_MASK));
}

char uart_get_char() {
	// Wait until all bits are received
	while(!(UART0_S1 & UART_S1_RDRF_MASK));  //Receive Data Register Full Flag
	return UART0_D;
}

void uart_put_string(char * string) {
	char * currentChar = string;
	// Send one char at a time to the UART
	while(*currentChar){
		uart_put_char(*currentChar);
		currentChar++;
	}
}
