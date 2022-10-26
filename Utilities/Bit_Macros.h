/*
 * Bit_Macros.h
 *
 * Created: 9/6/2022 10:50:34 PM
 *  Author: Hesham Ellethy
 */ 


#ifndef BIT_MACROS_H_
#define BIT_MACROS_H_

// Set specific bit in  register 
#define SET_BIT(REG,BIT) (REG|=(1<<BIT))

// clear specific bit in  register 
#define CLR_BIT(REG,BIT) (REG&=(~(1<<BIT)))

// toggle specific bit in  register 
#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))
// read a specific bit in  register
#define BIT_READ(REG,BIT) (( REG & (1<<BIT))>>BIT)

// Check if a specific bit is set to 1
#define BIT_IS_SET(REG,BIT) ( REG & (1<<BIT) )

// Check if a specific bit  is set to 0
#define BIT_IS_CLEAR(REG,BIT) ( !(REG & (1<<BIT)) )



#endif /* BIT_MACROS_H_ */