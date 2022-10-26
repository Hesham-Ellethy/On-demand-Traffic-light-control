/*
 * LED.c
 *
 * Created: 9/6/2022 10:10:59 PM
 *  Author: Hesham Ellethy
 */ 
//include .h
#include "LED.h"

//global Variables

//////functions definitions////////

//init led pin as output
EN_DIO_error_t LED_init(uint8 ledPort,uint8 ledPin){
	return DIO_init(ledPort, ledPin,OUT);//set led direction as output
}

//set led pin to high
EN_DIO_error_t LED_on(uint8 ledPort,uint8 ledPin){
	return DIO_write(ledPort, ledPin,HIGH);//set led pin to 1
}

//set led pin to low
EN_DIO_error_t LED_off(uint8 ledPort,uint8 ledPin){
	return DIO_write(ledPort, ledPin,LOW);//set led pin to 0
}

//toggle led pin
EN_DIO_error_t LED_toggle(uint8 ledPort,uint8 ledPin){
	return DIO_toggle( ledPort, ledPin);//toggle led pin 
}


