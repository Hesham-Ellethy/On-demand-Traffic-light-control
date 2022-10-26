/*
 * BUTTON.c
 *
 * Created: 9/7/2022 2:15:25 AM
 *  Author: Hesham Ellethy
 */ 

//include .h
#include"BUTTON.h"
//global Variables


//functions definitions

//init button as input device
EN_DIO_error_t BUTTON_init(uint8 buttonPort,uint8 buttonPin){
	int error=DIO_init(buttonPort,buttonPin,IN);//set as input pin for input device(button)
	
	return error;
}
// read button pin
EN_DIO_error_t BUTTON_read(uint8 buttonPort,uint8 buttonPin,uint8* value){
	return DIO_read(buttonPort,buttonPin,value);//read button bin value 0 or 1
	//error handling
	
	
}
