#ifndef SOURCES_LOCKER_MODULE_HARDWARE_LAYER_GPIO_H_
#define SOURCES_LOCKER_MODULE_HARDWARE_LAYER_GPIO_H_

void gpio_init();
void set_portb_output(int pin);
void set_portc_output(int pin);
void clear_portb_output(int pin);
void clear_portc_output(int pin);
int get_portb_input(int pin);
int get_portc_input(int pin);

#endif /* SOURCES_LOCKER_MODULE_HARDWARE_LAYER_GPIO_H_ */
