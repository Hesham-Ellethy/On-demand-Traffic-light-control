/*
 * Interrupts.h
 *
 * Created: 9/9/2022 5:13:18 PM
 *  Author: Hesham Ellethy
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_
//includes
#include "../../Utilities/registers.h"
#include "../../Utilities/Bit_Macros.h"
/************************************************************************/
/*                   Interrupt Vectors                                  */
/************************************************************************/
//external interrupts Vectors

//external interrupt request 0
#define EXT_INT_0 __vector_1
//external interrupt request 0
#define EXT_INT_1 __vector_2
//external interrupt request 0
#define EXT_INT_2 __vector_3

//PINs
// register GICR pins
#define INT0 6
#define INT1 7
#define INT2 5
// register GIFR pins
#define INTF0 6
#define INTF1 7
#define INTF2 5
// register MCUCR pins
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3


//set I-bit to 1 in SREG(enable global interrupt)
#define sei() __asm__ __volatile__ ("sei" ::: "memory")
//Clr I-bit to 0 in SREG(disable global interrupt)
#define cli() __asm__ __volatile__ ("cli" ::: "memory")

//define ISR
#define ISR(INT_VECT) void INT_VECT(void)__attribute__ ((signal,used));\
void INT_VECT(void)

#endif /* INTERRUPTS_H_ */