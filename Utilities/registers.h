/*
 * registers.h
 *
 * Created: 9/6/2022 2:24:45 PM
 *  Author: Hesham Ellethy
 */ 
//include types.h
#include "types.h"

#ifndef REGISTERS_H_
#define REGISTERS_H_

/************************************************************************/
/*                       DIO Registers                                  */
/************************************************************************/
//PORTA registers
#define PORTA (*((volatile uint8*)(0x3B))) // 8 bit register
#define DDRA (*((volatile uint8*)(0x3A))) // 8 bit register
#define PINA (*((volatile uint8*)(0x39))) // 8 bit register
//PORTB registers
#define PORTB (*((volatile uint8*)(0x38))) // 8 bit register
#define DDRB (*((volatile uint8*)(0x37))) // 8 bit register
#define PINB (*((volatile uint8*)(0x36))) // 8 bit register
//PORTC registers
#define PORTC (*((volatile uint8*)(0x35))) // 8 bit register
#define DDRC (*((volatile uint8*)(0x34))) // 8 bit register
#define PINC (*((volatile uint8*)(0x33))) // 8 bit register
//PORTD registers
#define PORTD (*((volatile uint8*)(0x32))) // 8 bit register
#define DDRD (*((volatile uint8*)(0x31))) // 8 bit register
#define PIND (*((volatile uint8*)(0x30))) // 8 bit register


/************************************************************************/
/*                       Timers Registers                               */
/************************************************************************/
//Timer0
#define OCR0 (*((volatile uint8*)(0x5C))) // 8 bit register
#define TIMSK (*((volatile uint8*)(0x59))) // 8 bit register
#define TIFR (*((volatile uint8*)(0x58))) // 8 bit register
#define TCCR0 (*((volatile uint8*)(0x53))) // 8 bit register
#define TCNT0 (*((volatile uint8*)(0x52))) // 8 bit register


/************************************************************************/
/*                External interrupts Registers                         */
/************************************************************************/
#define MCUCR (*((volatile uint8*)(0x55))) // 8 bit register
#define MCUCSR (*((volatile uint8*)(0x54))) // 8 bit register
#define GICR (*((volatile uint8*)(0x5B))) // 8 bit register
#define GIFR (*((volatile uint8*)(0x5A))) // 8 bit register
/************************************************************************/
/*                            ADC  Registers                            */
/************************************************************************/
#define ADMUX (*((volatile uint8*)(0x27))) // 8 bit register
#define ADCSRA (*((volatile uint8*)(0x26))) // 8 bit register
#define ADCH (*((volatile uint8*)(0x25))) // 8 bit register
#define ADCL (*((volatile uint8*)(0x24))) // 8 bit register
#define SFIOR (*((volatile uint8*)(0x50))) // 8 bit register

#endif /* REGISTERS_H_ */