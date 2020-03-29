/*
 * flexTimer.h
 *
 *  Created on: Mar 24, 2020
 *      Author: Alexandre
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
