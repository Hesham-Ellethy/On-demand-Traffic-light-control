/*
 * Application.c
 *
 * Created: 9/6/2022 11:32:18 PM
 *  Author: Hesham Ellethy
 */ 
//include .h
#include "Application.h"


uint8 volatile CarsTrafficLight_CurrentState=GREEN;
uint8 volatile CarsTrafficLight_NextState=GREEN;
uint8 volatile Pedestrians_passed=0;

//initiate all devices
void APP_init(void){

	/*/set BUTTON pin as input PORTD pin 2 /*/
	BUTTON_init(EXTERNAL_INT_BUTTON_PORT,EXTERNAL_INT_BUTTON_PIN);
	
	/*/set Cars Lights pin as Output/*/
	//car green light
	LED_init(Car_Green_PORT,Car_Green_PIN);
	//car yellow light
	LED_init(Car_Yellow_PORT,Car_Yellow_PIN);
	//car red light
	LED_init(Car_Red_PORT,Car_Red_PIN);
	
	/*/set Pedestrians Lights pin as Output/*/
	//Pedestrians green light
	LED_init(Pedestrians_Green_PORT,Pedestrians_Green_PIN);
	//Pedestrians yellow light
	LED_init(Pedestrians_Yellow_PORT,Pedestrians_Yellow_PIN);
	//Pedestrians red light
	LED_init(Pedestrians_Red_PORT,Pedestrians_Red_PIN);
	
	/*/set External INT/*/
	External_interrupt0_init();
	
	
	
}

//start application flowchart
void APP_start(void){
	while(1){
		
		normal_Mode();
		
		
	}
	
}

//blinking yellow led in 5 sec
void Blinking_Light_5s(uint8 Blinking_Port,uint8 Blinking_Pin){
		if (Pedestrians_passed==1){return;}
	LED_on(Blinking_Port,Blinking_Pin);//yellow light on
	Delay_msec(1000);
	LED_off(Blinking_Port,Blinking_Pin);//yellow light off
		if (Pedestrians_passed==1){return;}
	Delay_msec(1000);
		if (Pedestrians_passed==1){return;}
	LED_on(Blinking_Port,Blinking_Pin);//yellow light on
		
	Delay_msec(1000);
		
	LED_off(Blinking_Port,Blinking_Pin);//yellow light off
		if (Pedestrians_passed==1){return;}
	Delay_msec(1000);
		if (Pedestrians_passed==1){return;}
	LED_on(Blinking_Port,Blinking_Pin);//yellow light on
		
	Delay_msec(1000);
		
	LED_off(Blinking_Port,Blinking_Pin);//yellow light off
	
}

void normal_Mode(void){
		LED_off(Pedestrians_Green_PORT,Pedestrians_Green_PIN);///Pedestrians green light off
		LED_off(Pedestrians_Yellow_PORT,Pedestrians_Yellow_PIN);///Pedestrians Yellow light off
		LED_on(Pedestrians_Red_PORT,Pedestrians_Red_PIN);///Pedestrians Red light on
		switch(CarsTrafficLight_NextState){
			case GREEN:
				//****normal mode Starting from green
				Pedestrians_passed=0;
				CarsTrafficLight_CurrentState=GREEN;
				//green
				LED_on(Car_Green_PORT,Car_Green_PIN);//green light on
				Delay_msec(5000);
				LED_off(Car_Green_PORT,Car_Green_PIN);///green light off
				if (Pedestrians_passed==0)
				{CarsTrafficLight_NextState=YELLOW;
				}
				
			
				break;
			case YELLOW:
				//****normal mode Starting from Yellow
			
						switch(CarsTrafficLight_CurrentState){
							case GREEN:CarsTrafficLight_CurrentState=YELLOW;
										CarsTrafficLight_NextState=RED;
								break;
							case RED:CarsTrafficLight_CurrentState=YELLOW;
										CarsTrafficLight_NextState=GREEN;
								break;
							default://error Handling
								break;
							}
			
				//yellow
				Blinking_Light_5s(Car_Yellow_PORT,Car_Yellow_PIN);//Blinking yellow Light
				if (Pedestrians_passed==1){CarsTrafficLight_NextState=GREEN;}
				break;
				
			case RED:
				//****normal mode Starting from RED
				CarsTrafficLight_CurrentState=RED;
				//red
				LED_on(Car_Red_PORT,Car_Red_PIN);///red light on
				Delay_msec(5000);
				LED_off(Car_Red_PORT,Car_Red_PIN);//red light off
				if (Pedestrians_passed==0){
				CarsTrafficLight_NextState=YELLOW;
				}
				break;
			
			default://error handling
			break;
			
			
		}
}

void Pedestrians_Mode(void){
	switch(CarsTrafficLight_CurrentState){
			case GREEN:
			/****go to :1-Pedestrians_state_2
						2-Pedestrians_toNormalMode state
			*/
				Pedestrians_state_2();
				Pedestrians_toNormalMode();
								
				CarsTrafficLight_NextState=GREEN;	
			
				break;
			case YELLOW:
			/****go to :1-Pedestrians_state_2
						2-Pedestrians_toNormalMode state
			*/
				Pedestrians_state_2();
				Pedestrians_toNormalMode();
								
				CarsTrafficLight_NextState=GREEN;
			
				break;
			case RED:
			/****go to :1-Pedestrians_state_1
						2-Pedestrians_toNormalMode state
			*/
				Pedestrians_state_1();
					Pedestrians_passed=0;

								
			
				break;
		}
	}
	





void Pedestrians_state_1(void){
	
	LED_off(Pedestrians_Red_PORT,Pedestrians_Red_PIN);//Pedestrians green light off
	
	//car red led and Pedestrians green led on for 5s
	LED_on(Car_Red_PORT,Car_Red_PIN);//car red light on
	LED_on(Pedestrians_Green_PORT,Pedestrians_Green_PIN);//Pedestrians Green light on
	Delay_msec(5000);
	LED_off(Car_Red_PORT,Car_Red_PIN);//car red light off
	LED_off(Pedestrians_Green_PORT,Pedestrians_Green_PIN);//Pedestrians Green light off
	
}
void Pedestrians_state_2(void){
	//1-Pedestrians Red light on 
	LED_on(Pedestrians_Red_PORT,Pedestrians_Red_PIN);//Pedestrians Red light on
	
	LED_off(Pedestrians_Red_PORT,Pedestrians_Red_PIN);//Pedestrians Red light off
	//2-blinking yellow(Pedestrian,cars) (5ec) after closing car green led
		LED_off(Car_Green_PORT,Car_Green_PIN);//car green light off
		///blinking yellow for Pedestrians and cars leds
		LED_on(Pedestrians_Yellow_PORT,Pedestrians_Yellow_PIN);//Pedestrians yellow light on
		LED_on(Car_Yellow_PORT,Car_Yellow_PIN);//cars yellow light on
		Delay_msec(1000);
		LED_off(Pedestrians_Yellow_PORT,Pedestrians_Yellow_PIN);//Pedestrians yellow light off
		LED_off(Car_Yellow_PORT,Car_Yellow_PIN);//cars yellow light off
		Delay_msec(1000);
		LED_on(Pedestrians_Yellow_PORT,Pedestrians_Yellow_PIN);//Pedestrians yellow light on
		LED_on(Car_Yellow_PORT,Car_Yellow_PIN);//cars yellow light on
		Delay_msec(1000);
		LED_off(Pedestrians_Yellow_PORT,Pedestrians_Yellow_PIN);//Pedestrians yellow light off
		LED_off(Car_Yellow_PORT,Car_Yellow_PIN);//cars yellow light off
		Delay_msec(1000);
		LED_on(Pedestrians_Yellow_PORT,Pedestrians_Yellow_PIN);//Pedestrians yellow light on
		LED_on(Car_Yellow_PORT,Car_Yellow_PIN);//cars yellow light on
		Delay_msec(1000);
		LED_off(Pedestrians_Yellow_PORT,Pedestrians_Yellow_PIN);//Pedestrians yellow light off
		LED_off(Car_Yellow_PORT,Car_Yellow_PIN);//cars yellow light off
		///////////
	//3-car red led ,Pedestrians green led (5sec)
	LED_on(Pedestrians_Green_PORT,Pedestrians_Green_PIN);//Pedestrians Green light on
	LED_on(Car_Red_PORT,Car_Red_PIN);//cars Red light on
	Delay_msec(5000);
	LED_off(Pedestrians_Green_PORT,Pedestrians_Green_PORT);//Pedestrians Green light off
	LED_off(Car_Red_PORT,Car_Red_PIN);//cars Red light off
	
}
//transition state to normal mode for 5 sec
/*Pedestrians green light on
 *Pedestrians and cars yellow light blinking
*/ 	
void Pedestrians_toNormalMode(void){
	LED_on(Pedestrians_Green_PORT,Pedestrians_Green_PIN);//Pedestrians green light on
		///blinking yellow for Pedestrians and cars leds
		LED_on(Pedestrians_Yellow_PORT,Pedestrians_Yellow_PIN);//Pedestrians yellow light on
		LED_on(Car_Yellow_PORT,Car_Yellow_PIN);//cars yellow light on
		Delay_msec(1000);
		LED_off(Pedestrians_Yellow_PORT,Pedestrians_Yellow_PIN);//Pedestrians yellow light off
		LED_off(Car_Yellow_PORT,Car_Yellow_PIN);//cars yellow light off
		Delay_msec(1000);
		LED_on(Pedestrians_Yellow_PORT,Pedestrians_Yellow_PIN);//Pedestrians yellow light on
		LED_on(Car_Yellow_PORT,Car_Yellow_PIN);//cars yellow light on
		Delay_msec(1000);
		LED_off(Pedestrians_Yellow_PORT,Pedestrians_Yellow_PIN);//Pedestrians yellow light off
		LED_off(Car_Yellow_PORT,Car_Yellow_PIN);//cars yellow light off
		Delay_msec(1000);
		LED_on(Pedestrians_Yellow_PORT,Pedestrians_Yellow_PIN);//Pedestrians yellow light on
		LED_on(Car_Yellow_PORT,Car_Yellow_PIN);//cars yellow light on
		Delay_msec(1000);
		LED_off(Pedestrians_Yellow_PORT,Pedestrians_Yellow_PIN);//Pedestrians yellow light off
		LED_off(Car_Yellow_PORT,Car_Yellow_PIN);//cars yellow light off
		///////////
	LED_off(Pedestrians_Green_PORT,Pedestrians_Green_PIN);///Pedestrians green light off
}	

ISR(EXT_INT_0){
	Delay_msec(200);
	if (BIT_READ(PIND,EXTERNAL_INT_BUTTON_PIN))
	{return;
	}
	External_interrupt0_stop();
///////////////////////Body/////////////	
	Pedestrians_passed=1;
	Pedestrians_Mode();
	
////////////////////////////////////////
	
	External_interrupt0_start();
	
}