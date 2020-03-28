//author: Tye Shutty
//To enter the RS-232 mode, both R1 and R2 jumpers should be open (default).
//The RS-232 signal must be 5V TTL compatible
//Communication format is 8-bit data, 1 Stop bit, no parity, no handshaking.
//Default BAUD rate is 9600
//All delays must take 3 to 5 volt logic converter into account (maximum 18ns
//between -55 C and 125 C)

#include "fsl_device_registers.h"
#include "MK64F12.h"
#include "ms_delay.c"

//0.1 ms Display Character Write execution time
//0x20 to 0x7F displays the standard set of characters
void uart0_putstring(char* start){
	while(*start != NULL){
		while(!(UART0_S1 & 1<<7));  //Transmit Data Register Empty Flag
		UART0_D = *start;
		ms_delay(1);
		start++;
	}
}

//1.5 ms execution time
void cursor_home(){
	char temp[] = {0xFE, 0x46, 0};
	uart0_putstring(temp);
}
//0.1 ms execution time
void move_cursor_right(){
	char temp[] = {0xFE, 0x4A, 0};
	uart0_putstring(temp);
}
//1.5 ms execution time
void clear_screen(){
	char temp[] = {0xFE, 0x51, 0};
	uart0_putstring(temp);
}

//Each message must be less than 33 characters (not including null)
//and null terminated.
//0.1 ms Display Character Write execution time
//0x20 to 0x7F displays the standard set of characters
void led_print_string(char *char_ptr){
	clear_screen();
	ms_delay(2);
	cursor_home();
	ms_delay(2);
	while(*char_ptr != NULL){
		while(!(UART0_S1 & 1<<7));  //Transmit Data Register Empty Flag
		UART0_D = *char_ptr;
		char_ptr++;
		ms_delay(1);
		while(!(UART0_S1 & 1<<7));
		move_cursor_right();
		ms_delay(1);
	}
}

void led_uart0_interface_init(){
	SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK | SIM_SCGC5_PORTA_MASK;
	SIM_SCGC4 |= SIM_SCGC4_UART0_MASK;  //Enable UART0 clock
	PORTA_PCR2 |= PORT_PCR_MUX(2);  //Enable UART0 TX: A2 has a pin header
	UART0_C2 &= ~(UART_C2_TE_MASK | UART_C2_RE_MASK);  //disable I/O
	UART0_BDH = 0x00;
	UART0_BDL = 0x88;  //9600 Baud
	UART0_C2 |= UART_C2_TE_MASK;  //enable Output
	char temp[] = {0xFE, 0x41, 0};  //LED on
	uart0_putstring(temp);
	char temp2[] = "Initializing...";
	led_print_string(temp2);
}
