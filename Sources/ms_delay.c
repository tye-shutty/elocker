//Author: Tye Shutty
#include "fsl_device_registers.h"
#include "MK64F12.h"
#include <stdint.h>

//Delays program execution for the period of time in ms passed in.
//The maximum delay is 2^32-1 ms (50 days).
//Assumes clock frequency of 21MHz
void ms_delay(uint32_t delay){
    //SIM_SCGC6: bit25 = if 1 FTM1 enabled
    SIM_SCGC6 |= (1 << 25);
    //Mod is frequency in ms^-1 (number of increments/ms)
    FTM1_MOD |= 21000; //not precise!!!! FIX
    //output compare with compare value set to 0 has no effect
    FTM1_C0SC |= 0b10100;
    //start clock
    FTM1_SC |= (1 << 3);
    while(delay){
        if(FTM1_SC & (1 << 7)){
            delay--;
            FTM1_SC &= ~(1 << 7);
        }
    }
    //turn off clock
    FTM1_SC &= ~(1 << 3);
}
