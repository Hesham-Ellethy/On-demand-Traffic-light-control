/*
 * Interrpt_service.c
 *
 * Created: 9/13/2022 7:42:14 PM
 *  Author: Hesham Ellethy
 */ 
// include.h
#include "Interrup_service.h"



//initiate global and External INT0
void External_interrupt0_init(void){
	//1-enable global interrupt in SREG register
	sei();
	//2-choose External interrupt 0,raising edge
	MCUCR|=(1<<0)|(1<<1);
	//3-enable external interrupt 0-INT0
	SET_BIT(GICR,INT0);
	
}
void External_interrupt0_start(void){
	//4-Enable external interrupt 0-INT0
	SET_BIT(GICR,INT0);
	
}
void External_interrupt0_stop(void){
	//5-disable external interrupt 0-INT0
	CLR_BIT(GICR,INT0);
	
}

//stop all interrupt
void Global_interrup_stop(void){
	//disable global interrupt
	cli();
}

/************************************************************************/
/*                            ISRs                                      */
/************************************************************************/
