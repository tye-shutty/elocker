#ifndef SOURCES_ABSTRACTION_LAYER_DISPLAY_TIMER_H_
#define SOURCES_ABSTRACTION_LAYER_DISPLAY_TIMER_H_

#include <stdint.h>

typedef struct timer_struct {
	void (*delay) (int time);
} timer_t;

timer_t* get_timer();

#endif /* SOURCES_ABSTRACTION_LAYER_DISPLAY_TIMER_H_ */
