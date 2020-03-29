#include "speaker.h"
#include "display_timer.h"
#include <stdlib.h>

static speaker_t* this = 0;

void init_speaker() {
	dac_init();
}

void successSound() {
	dac_out(261, 250000.00f);
}

void failSound() {
	timer_t* timer = get_timer();

	dac_out(698, 250000.00f);
	timer -> delay(250);
	dac_out(698, 250000.00f);
}

void play (int condition) {
	if (condition == SUCCESS) {
		successSound();
	} else {
		failSound();
	}
};


speaker_t* get_speaker() {
   if(this == 0) {
	   init_speaker();

    	this = (speaker_t*) malloc(sizeof(speaker_t));
        this -> play = &play;
    }
    return this;
}
