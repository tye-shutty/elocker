#ifndef SOURCES_LOCKER_MODULE_HARDWARE_LAYER_UART_H_
#define SOURCES_LOCKER_MODULE_HARDWARE_LAYER_UART_H_

void uart_init();
void uart_put_char(char c);
char uart_get_char();
void uart_put_string(char * string);


#endif /* SOURCES_LOCKER_MODULE_HARDWARE_LAYER_UART_H_ */
