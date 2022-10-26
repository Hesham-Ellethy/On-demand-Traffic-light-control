/*
 * Application.h
 *
 * Created: 9/6/2022 11:32:01 PM
 *  Author: Hesham Ellethy
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_
//include devices
#include "../ECUAL/LED/LED.h"
#include "../ECUAL/Button/BUTTON.h"
#include "../System_Services/Interrupt_service/Interrup_service.h"
#include "../System_Services/Timer_service/TimerService.h"



////Application Macros
//-----------Car Traffic lights------//
	//car green light
	#define Car_Green_PORT PORT_A
	#define Car_Green_PIN PIN0
	//car yellow light
	#define Car_Yellow_PORT PORT_A
	#define Car_Yellow_PIN PIN1
	//car red light
	#define Car_Red_PORT PORT_A
	#define Car_Red_PIN PIN2
//-----------pedestrians  Traffic lights------//
	//pedestrians  green light
	#define Pedestrians_Green_PORT PORT_B
	#define Pedestrians_Green_PIN PIN0
	//Pedestrians yellow light
	#define Pedestrians_Yellow_PORT PORT_B
	#define Pedestrians_Yellow_PIN PIN1
	//Pedestrians red light
	#define Pedestrians_Red_PORT PORT_B
	#define Pedestrians_Red_PIN PIN2

//-----------Button------//
#define EXTERNAL_INT_BUTTON_PORT PORT_D
#define EXTERNAL_INT_BUTTON_PIN PIN2

//-----------Lights Status------//
#define GREEN 0
#define YELLOW 1
#define RED 2



//APP functions declaration 
void APP_init(void);//initiate all devices
void APP_start(void);//start application flowchart
void Blinking_Light_5s(uint8 Blinking_Port,uint8 Blinking_Pin);//blinking yellow led in 5 sec
void normal_Mode(void);


void Pedestrians_Mode(void);
//Pedestrians states
void Pedestrians_state_1(void);
void Pedestrians_state_2(void);
void Pedestrians_toNormalMode(void);//transition state to normal mode:(Pedestrians green light on,Pedestrians and cars yellow light blinking) for 5 sec




#endif /* APPLICATION_H_ */