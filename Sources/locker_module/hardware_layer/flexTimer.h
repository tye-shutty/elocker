/*
  File: flexTimer.h
  Author: Alexandre Moreira de Carvalho
  This module is responsible to initialize the Flex Timer
	FTM3 and use it to create a software delay.
	The module permits the time in milliseconds to be entered
	to configure the delay time. 
 */
#ifndef SOURCES_LOCKER_MODULE_HARDWARE_LAYER_FLEXTIMER_H_
#define SOURCES_LOCKER_MODULE_HARDWARE_LAYER_FLEXTIMER_H_

void FTM0_OutComp_init();
void FTM0_OutComp_disable();
void FTM0_wait();

void FTM3_OutComp_init();
void FTM3_OutComp_disable();
void my_delay(int time);

#endif /* SOURCES_LOCKER_MODULE_HARDWARE_LAYER_FLEXTIMER_H_ */
