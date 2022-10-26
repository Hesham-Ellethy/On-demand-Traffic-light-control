/*
 * CFile1.c
 *
 * Created: 9/11/2022 10:57:23 PM
 *  Author: Hesham Ellethy
 */ 
//include .h
#include "Timer.h"


//initiate Timer 0 in normal mode without choosing prescaler (timer not started):

EN_TIMER_error_t Timer_init(void){
	
	//choose timer mode
	TCCR0=0x00; //normal mode
	//set timer initial value
	TCNT0=0x00; //start initially from zero
	return TIMER_0_OK;
	}

//set initial value to Timer register TCNTO
EN_TIMER_error_t Timer_set_initValue(uint8 init_value){
	//error handling
	if(init_value<0 ||init_value>255){
		return TIMER_WRONG_INIT_VALUE;
	}
	TCNT0=init_value;
	return TIMER_0_OK;
}

//timer start by setting clock source prescaler 1024
EN_TIMER_error_t Timer_start(void){
	TCCR0|=(1<<0)|(1<<2);
	return TIMER_0_OK;
}

//stop timer from counting by choosing no clock source
EN_TIMER_error_t Timer_stop(void){
	TCCR0=0x00;
	return TIMER_0_OK;
}

//waiting function until overflow occur 
EN_TIMER_error_t Timer_OV_check(void){
	while(BIT_IS_SET(TIFR,TOV0)==0);
	SET_BIT(TIFR,TOV0);
	return TIMER_0_OK;
}