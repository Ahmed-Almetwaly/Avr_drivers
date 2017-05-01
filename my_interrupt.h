/*
 * interrupt.h
 *
 *  Created on: Apr 2, 2017
 *      Author: ahmed
 */

#ifndef MY_INTERRUPT_H_
#define MY_INTERRUPT_H_

/*
 * INT0 --> 26
 * INT1 --> 27
 * INT2 --> 10
*/

#define INT0 0
#define INT1 1
#define INT2 2



// Modes of Interrupt MCUCR
/*
 *  set MODE (low level , fallimg edge,....)
 *  MCUCR 0,1 --- INT0
 *  MCUCR 2,3 --- INT1
*/
#define LOW_LEVEL      0X00
#define ANY_CHANGE     0X01
#define FALLING_EDGE   0X02
#define RISING_EDGE    0X03

// Modes of Interrupt MCUSCR pin 6

#define FALLING_EDGE2   0
#define RISING_EDGE2    1

void interrupt_Init (u_int8 INT_Number);
void my_interrupt_INT0_Call(void(*ptr_fn)(void));
void my_interrupt_INT1_Call(void(*ptr_fn)(void));
void my_interrupt_INT2_Call(void(*ptr_fn)(void));


#endif /* MY_INTERRUPT_H_ */
