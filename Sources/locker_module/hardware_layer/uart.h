/* 
	File: uart.h
	Authors: Alexandre Moreira de Carvalho
	This module is responsible to initialize the UART0 at
	pins PTB16 and PTB17. The UART transmission rate is set to
	9600 BAUD in a 8-bit data format with start + stop bit. No
	parity bit is configured. Transmission and reception of
	data is controlled by checks on the respective flags.
	The module permits a single char or a full string to be
	transmitted	via the UART.
*/
#ifndef SOURCES_LOCKER_MODULE_HARDWARE_LAYER_UART_H_
#define SOURCES_LOCKER_MODULE_HARDWARE_LAYER_UART_H_

void uart_init();
void uart_put_char(char c);
char uart_get_char();
void uart_put_string(char * string);


#endif /* SOURCES_LOCKER_MODULE_HARDWARE_LAYER_UART_H_ */
