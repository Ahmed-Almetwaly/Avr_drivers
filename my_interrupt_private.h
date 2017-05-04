/*
 * my_interrupt_PRIVATE_.h
 *
 *  Created on: Apr 2, 2017
 *      Author: ahmed almetwaly
 */
#ifndef MY_INTERRUPT_PRIVATE_H_
#define MY_INTERRUPT_PRIVATE_H_

#define INT0_PIN 26
#define INT1_PIN 27
#define INT2_PIN 10

// to enable interrupt set pin 7 SREG
//#define SREG   *((volatile u_int8 *) 0x5F)

// External Interrupt Flag INTF1 , INTF0, INTF2 ---> pins 7,6,5
// #define GIFR *((volatile u_int8 *) 0x5A)

/*
 *  set MODE (low level , fallimg edge,....)
 *  MCUCR 0,1 --- INT0
 *  MCUCR 2,3 --- INT1
*/
// #define MCUCR  *((volatile u_int8 *) 0x55)


/*
 * to enable interrupt2
 * 1- clear INT2 enbale from GICR (5)
 * 2- set the ISC2 in MCUCSR (6)
 * 3- clear interrupt flag by writting a logical 1 in INTF2 (GIFR) pin 5
 * 4- set INT2 enbale from GICR
 *
 */
// INT0 ---> 7 , INT1 ---> 6 , INT2 ---> 5
// #define GICR *((volatile u_int8 *) 0x5B)

// #define MCUCSR *((volatile u_int8 *) 0x54)


#endif /* MY_INTERRUPT_PRIVATE_H_ */
