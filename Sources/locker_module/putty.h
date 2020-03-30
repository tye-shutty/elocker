#ifndef SOURCES_LOCKER_MODULE_PUTTY_H_
#define SOURCES_LOCKER_MODULE_PUTTY_H_

#include <stdlib.h>
#include "hardware_layer/uart.h"

typedef struct putty_struct {
	void (*put_char) (char character);
	void (*print_line) (char* string);
	void (*print_string) (char* string);
} putty_t;

putty_t* get_putty();

#endif /* SOURCES_LOCKER_MODULE_PUTTY_H_ */
