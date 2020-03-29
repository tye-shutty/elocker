#include "lcd.h"

static lcd_t* this = 0;

void init_lcd() {
	uart_init();
}

void put_char(char character) {
    uart_put_char(character);
}

void print_line(char* string) {
    uart_put_string(string);
	// Sends the new line character
	uart_put_char('\r');
	uart_put_char('\n');
}

void print_string(char* string) {
    uart_put_string(string);
}

lcd_t* get_lcd() {
   if(this == 0) {
    	init_lcd();

    	this = (lcd_t*) malloc(sizeof(lcd_t));
        this -> put_char = &put_char;
        this -> print_line = &print_line;
        this -> print_string = &print_string;
    }
    return this;
}
