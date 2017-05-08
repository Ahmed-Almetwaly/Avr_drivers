/*
 * Hw_Reg.h
 *
 *  Created on: Mar 19, 2017
 *      Author: Dark
 */

#include "Types.h"

#ifndef HW_REG_H_
#define HW_REG_H_

#define DDRA *((volatile u_int8*) 0x3A)
#define DDRB *((volatile u_int8*) 0x37)
#define DDRC *((volatile u_int8*) 0x34)
#define DDRD *((volatile u_int8*) 0x31)
#define DDR  ((volatile u_int8*) 0x3A)
#define PORTA *((volatile u_int8*) 0x3B)
#define PORTB *((volatile u_int8*) 0x38)
#define PORTC *((volatile u_int8*) 0x35)
#define PORTD *((volatile u_int8*) 0x32)
#define PORT ((volatile u_int8*) 0x3B)
#define PINA *((volatile u_int8*) 0x39)
#define PINB *((volatile u_int8*) 0x36)
#define PINC *((volatile u_int8*) 0x33)
#define PIND *((volatile u_int8*) 0x30)
#define PIN ((volatile u_int8*) 0x39)
#define MCUCR *((volatile u_int8*) 0x55)
#define GICR *((volatile u_int8*) 0x5B)

#undef SREG

#define SREG *((volatile u_int8*) 0x3F)
#define ADMUX *((volatile u_int8*) 0x27)
#define ADCSRA *((volatile u_int8*) 0x26)
#define ADCH *((volatile u_int8*) 0x25)
#define ADCL *((volatile u_int8*) 0x24)
#define ADCLH *((volatile u_int16*) 0x24)
#define SFIOR *((volatile u_int8*) 0x50)
#define OCR0  *((volatile u_int8*) 0x5C)
#define TCCR0 *((volatile u_int8*) 0x53)
#define TCNT0 *((volatile u_int8*) 0x52)
#define TIMSK *((volatile u_int8*) 0x59)
#define TIFR *((volatile u_int8*) 0x58)
#define TCCR1A *((volatile u_int8*) x04F)
#define TCCR1B *((volatile u_int8*) x04E)
#define OCCR1ALH *((volatile u_int16*) 0x4A)
#define ICR1LH *((volatile u_int16*) 0x46)
#define TCCR2 *((volatile u_int8*) 0x45)
//UART REG
#define UCSRA *((volatile u_int8*) 0x2B)
#define UCSRB *((volatile u_int8*) 0x2A)
#define UBRRL *((volatile u_int8*) 0x29)
#define UBRRH *((volatile u_int8*) 0x40)
#define UCSRC *((volatile u_int8*) 0x40)
#define UDR   *((volatile u_int8*) 0x2C)
// SPI
#define SPDR  *((volatile u_int8*) 0x2F)
#define SPSR  *((volatile u_int8*) 0x2E)
#define SPCR  *((volatile u_int8*) 0x2D)


#endif /* HW_REG_H_ */
