/*
 * Timer.h
 *
 * Created: 9/11/2022 10:57:57 PM
 *  Author: Hesham Ellethy
 */ 


#ifndef TIMER_H_
#define TIMER_H_


//includes
#include "../../Utilities/registers.h"
#include "../../Utilities/Bit_Macros.h"
#include "../../Utilities/Error_Handler.h"
//Timer typedefs
//Timer Macros

//PINs
#define TOV0 0
//Timer Functions Prototypes
EN_TIMER_error_t Timer_init(void);
EN_TIMER_error_t Timer_set_initValue(uint8 init_value);
EN_TIMER_error_t Timer_start(void);
EN_TIMER_error_t Timer_stop(void);
EN_TIMER_error_t Timer_OV_check(void);

#endif /* TIMER_H_ */