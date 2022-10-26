/*
 * DIO.c
 *
 * Created: 9/6/2022 8:40:39 PM
 *  Author: Hesham Ellethy
 */ 

// include .h
#include "DIO.h"

//global Variables
//functions definitions

//set DIO direction
EN_DIO_error_t DIO_init(uint8 portNum,uint8 pinNum,uint8 direction){
	//error handling
	if(pinNum<0 ||pinNum>7){
		return DIO_WRONG_PIN_NUMBER;
	}
	switch(portNum){
		case PORT_A:if (direction== IN){
						CLR_BIT(DDRA,pinNum);
						}
					else if(direction== OUT){
						SET_BIT(DDRA,pinNum);
						}
					else{//error handling
						return DIO_WRONG_DIRECTION;
						}
					break;	
		case PORT_B:if (direction== IN)
					{
						CLR_BIT(DDRB,pinNum);
					}
					else if(direction== OUT){
						SET_BIT(DDRB,pinNum);
					}
					else{//error handling
						return DIO_WRONG_DIRECTION;
					}
					break;
		case PORT_C:if (direction== IN)
					{
						CLR_BIT(DDRC,pinNum);
						}
					else if(direction== OUT){
						SET_BIT(DDRC,pinNum);
					}
					else{//error handling
						return DIO_WRONG_DIRECTION;
					}
					break;
		case PORT_D:if (direction== IN){
						CLR_BIT(DDRD,pinNum);
					}
					else if(direction== OUT){
						SET_BIT(DDRD,pinNum);
					}
					else{//error handling
						return DIO_WRONG_DIRECTION;
					}
					break;
		default:return DIO_WRONG_PORT_NUMBER;//error handling					
					
	}
	return DIO_OK;
}
//write Data on DIO
EN_DIO_error_t DIO_write(uint8 portNum,uint8 pinNum,uint8 value){
	//error handling
	if(pinNum<0 ||pinNum>7){
		return DIO_WRONG_PIN_NUMBER;
	}
	switch(portNum){
		case PORT_A:if (value== LOW){
			CLR_BIT(PORTA,pinNum);
		}
		else if(value== HIGH){
			SET_BIT(PORTA,pinNum);
		}
		else{//error handling
			return DIO_WRONG_VALUE;
		}
		break;
		case PORT_B:if (value== LOW)
		{
			CLR_BIT(PORTB,pinNum);
		}
		else if(value== HIGH){
			SET_BIT(PORTB,pinNum);
		}
		else{//error handling
			return DIO_WRONG_VALUE;
		}
		break;
		case PORT_C:if (value== LOW)
		{
			CLR_BIT(PORTC,pinNum);
		}
		else if(value== HIGH){
			SET_BIT(PORTC,pinNum);
		}
		else{//error handling
			return DIO_WRONG_VALUE;
		}
		break;
		case PORT_D:if (value== LOW){
			CLR_BIT(PORTD,pinNum);
		}
		else if(value== HIGH){
			SET_BIT(PORTD,pinNum);
		}
		else{//error handling
			return DIO_WRONG_VALUE;
		}
		break;
		default:return DIO_WRONG_PORT_NUMBER;//error handling
		
	}
	return DIO_OK;
}

//change DIO status (toggle)
EN_DIO_error_t DIO_toggle(uint8 portNum,uint8 pinNum){
	//error handling
	if(pinNum<0 ||pinNum>7){
		return DIO_WRONG_PIN_NUMBER;
	}
	switch(portNum){
					case PORT_A:TOGGLE_BIT(PORTA,pinNum);
					break;
					case PORT_B:TOGGLE_BIT(PORTB,pinNum);
					break;
					case PORT_C:TOGGLE_BIT(PORTC,pinNum);
					break;
					case PORT_D:TOGGLE_BIT(PORTD,pinNum);
					break;
					default:return DIO_WRONG_PORT_NUMBER;
					break;
	}
	return DIO_OK;
}
//read DIO
EN_DIO_error_t DIO_read(uint8 portNum,uint8 pinNum,uint8* value){
	//error handling
	if(pinNum<0 ||pinNum>7){
		return DIO_WRONG_PIN_NUMBER;
	}
	switch(portNum){
		case PORT_A:
					*value=BIT_READ(PINA,pinNum);
		break;
		case PORT_B:
					*value=BIT_READ(PINB,pinNum);
		break;
		case PORT_C:
					*value=BIT_READ(PINC,pinNum);
		break;
		case PORT_D:
					*value=BIT_READ(PIND,pinNum);
		break;
		default://error handling
		return DIO_WRONG_PORT_NUMBER;
	}
	return DIO_OK;
}