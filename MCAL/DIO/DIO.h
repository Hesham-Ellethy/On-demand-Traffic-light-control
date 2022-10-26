/*
 * DIO.h
 *
 * Created: 9/6/2022 8:41:30 PM
 *  Author: Hesham Ellethy
 */ 


#ifndef DIO_H_
#define DIO_H_
//include Utilities
#include "../../Utilities/registers.h"
#include "../../Utilities/Bit_Macros.h"
#include "../../Utilities/Error_Handler.h"

//DIO typedefs

//DIO Macros
//ports
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'
//PINs
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7
//directions
#define IN 0
#define OUT 1
//Write Values
#define HIGH 1
#define LOW  0

//DIO Functions Prototypes
EN_DIO_error_t DIO_init(uint8 portNum,uint8 pinNum,uint8 direction);//set DIO direction
EN_DIO_error_t DIO_write(uint8 portNum,uint8 pinNum,uint8 value);//write Data on DIO
EN_DIO_error_t DIO_toggle(uint8 portNum,uint8 pinNum);//change DIO status (toggle)
EN_DIO_error_t DIO_read(uint8 portNum,uint8 pinNum,uint8* value);//read DIO 


#endif /* DIO_H_ */