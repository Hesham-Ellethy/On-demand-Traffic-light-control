/*
 * LED.h
 *
 * Created: 9/6/2022 10:11:14 PM
 *  Author: Hesham Ellethy
 */ 


#ifndef LED_H_
#define LED_H_
//include DIO.h
#include "../../MCAL/DIO/DIO.h"

//LED typedefs

//LED Macros

//LED Functions Prototypes
EN_DIO_error_t LED_init(uint8 ledPort,uint8 ledPin);//init led pin as output
EN_DIO_error_t LED_on(uint8 ledPort,uint8 ledPin);//set led pin to high
EN_DIO_error_t LED_off(uint8 ledPort,uint8 ledPin);//set led pin to low
EN_DIO_error_t LED_toggle(uint8 ledPort,uint8 ledPin);//toggle led pin



#endif /* LED_H_ */