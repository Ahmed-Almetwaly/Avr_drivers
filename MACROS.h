/*
 * MACROS.h
 *
 *  Created on: Mar 12, 2017
 *      Author: ahmed
 */

#ifndef MACROS_H_
#define MACROS_H_

#define SET_BIT(R,Bit_number)    ((R)|=(1<<(Bit_number)))
#define CLEAR_BIT(R,Bit_number)  ((R)&=~(1<<(Bit_number)))
#define TOGGLE_BIT(R,Bit_number) ((R)^=(1<<(Bit_number)))
#define GET_BIT(R,Bit_number) 	 (((R)&(1<<(Bit_number)))>>(Bit_number))
#define SET_PINS(R,Pins)		 ((R)|= (Pins))
#define CLEAR_PINS(R,Pins)		 ((R)&= ~(Pins))
#define GET_PINS(R,Pins)		 ((R)&(Pins))
#define Ass_PINS(R,Pins)		 ((R)= (Pins))
#define TRUE  1
#define FALSE 0
#define INPUT 0
#define OUTPUT 1
#define HIGH 1
#define LOW 0
#define PULL_UP 1
#define PULL_DOWN 0

#endif /* MACROS_H_ */
