/*
 * Interrup_service.h
 *
 * Created: 9/13/2022 7:42:45 PM
 *  Author: Hesham Ellethy
 */ 


#ifndef INTERRUP_SERVICE_H_
#define INTERRUP_SERVICE_H_
//includes
#include "../../MCAL/interrupt lib/Interrupts.h"




//Interrup_service functions declaration 

//initiate global and External INT0
void External_interrupt0_init(void);

void External_interrupt0_start(void);
//stop external interrupt 0
void External_interrupt0_stop(void);

//stop all interrupt
void Global_interrup_stop(void);


#endif /* INTERRUP_SERVICE_H_ */