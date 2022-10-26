/*
 * Error_Handler.h
 *
 * Created: 10/8/2022 4:58:02 PM
 *  Author: Hesham Ellethy
 */ 


#ifndef ERROR_HANDLER_H_
#define ERROR_HANDLER_H_

typedef enum EN_DIO_error_t{
	DIO_OK,
	DIO_WRONG_PIN_NUMBER,
	DIO_WRONG_PORT_NUMBER,
	DIO_WRONG_DIRECTION,
	DIO_WRONG_VALUE,
	
	} EN_DIO_error_t;
	
typedef enum EN_TIMER_error_t{
	TIMER_0_OK,
	TIMER_WRONG_INIT_VALUE
	
} EN_TIMER_error_t;
typedef enum BUTTON_error_t{
	BUTTON_OK,
	BUTTON_WRONG_INIT,
	BUTTON_WRONG_READ
	
} BUTTON_error_t;



#endif /* ERROR_HANDLER_H_ */