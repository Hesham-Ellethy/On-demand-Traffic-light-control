/*
 * TimerService.c
 *
 * Created: 9/12/2022 12:08:31 AM
 *  Author: Hesham Ellethy
 */ 
//include .h
#include "TimerService.h"


void Delay_msec(uint16 Delay_value){
	uint16 overFlows=0;
	uint16 N_overFlow=((Delay_value)/262.144)+1;
	uint8 T_init_value=256-(((Delay_value)/1.024)/N_overFlow);
	Timer_init();
	Timer_set_initValue(T_init_value) ;
	Timer_start();
	while(overFlows<N_overFlow){
		Timer_OV_check();
		overFlows++;
	}
	//Timer_stop();
}
