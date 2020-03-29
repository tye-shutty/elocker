#ifndef SOURCES_LOCKER_MODULE_SPEAKER_H_
#define SOURCES_LOCKER_MODULE_SPEAKER_H_

#include <stdint.h>
#include "hardware_layer/dac.h"

#define FAIL 0
#define SUCCESS 1

typedef struct speaker_struct {
	void (*play) (int condition);
} speaker_t;

speaker_t* get_speaker();

#endif /* SOURCES_LOCKER_MODULE_SPEAKER_H_ */
