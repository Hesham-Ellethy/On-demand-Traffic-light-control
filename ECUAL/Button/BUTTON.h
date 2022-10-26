/*
 * BUTTON.h
 *
 * Created: 9/7/2022 2:15:42 AM
 *  Author: Hesham Ellethy
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
#include "../../MCAL/DIO/DIO.h"



//BUTTON Functions Prototypes
EN_DIO_error_t BUTTON_init(uint8 buttonPort,uint8 buttonPin);//init button as input device

EN_DIO_error_t BUTTON_read(uint8 buttonPort,uint8 buttonPin,uint8* value);// read button pin



#endif /* BUTTON_H_ */