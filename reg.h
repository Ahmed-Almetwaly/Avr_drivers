/*
 * reg.h
 *
 *  Created on: Mar 19, 2017
 *      Author: ahmed
 */

#ifndef REG_H_
#define REG_H_

#include "Types.h"

#define DDRA    *((volatile u_int8 *) 0x3A)
#define DDRB	*((volatile u_int8 *) 0x37)
#define DDRC	*((volatile u_int8 *) 0x34)
#define DDRD	*((volatile u_int8 *) 0x31)
#define PORTA   *((volatile u_int8 *) 0x3B)
#define PORTB   *((volatile u_int8 *) 0x38)
#define PORTC   *((volatile u_int8 *) 0x35)
#define PORTD   *((volatile u_int8 *) 0x32)
#define PINA    *((volatile u_int8 *) 0x39)
#define PINB    *((volatile u_int8 *) 0x36)
#define PINC    *((volatile u_int8 *) 0x33)
#define PIND    *((volatile u_int8 *) 0x30)

#endif /* REG_H_ */
