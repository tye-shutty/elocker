#ifndef SOURCES_LOCKER_MODULE_LCD_H_
#define SOURCES_LOCKER_MODULE_LCD_H_

#include <stdlib.h>
#include "hardware_layer/uart.h"

typedef struct lcd_struct {
	void (*put_char) (char character);
	void (*print_line) (char* string);
	void (*print_string) (char* string);
} lcd_t;

lcd_t* get_lcd();

#endif /* SOURCES_LOCKER_MODULE_LCD_H_ */
