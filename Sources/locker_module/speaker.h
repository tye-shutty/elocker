/* 
	File: speaker.h
	Authors: Alexandre Moreira de Carvalho and Tye Shutty
	This module implement the speaker function play. Two types
	of sounds are programmed: success and fail. The success sound
	is a single beep at 261Hz, while the fail sound is a double beep
	at 698 Hz. The module ensures that only a single	instance of
	the speaker	is created.
*/

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
