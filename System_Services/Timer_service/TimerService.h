/*
 * TimerService.h
 *
 * Created: 9/12/2022 12:08:45 AM
 *  Author: Hesham Ellethy
 */ 


#ifndef TIMERSERVICE_H_
#define TIMERSERVICE_H_

//includes
#include "../../MCAL/Timer/Timer.h"
//
//macros	
#define T_tick 1.024f 
#define T_max_delat 262.144f 

// Functions Prototypes

//generate delay in msec 
void Delay_msec(uint16 Delay_value);

#endif /* TIMERSERVICE_H_ */