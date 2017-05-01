/*
 * main.c
 * 
 *  Created on: Mar 12, 20 17 MAX_COUNT 
 *  Author:  Ahmed Almetwaly 
 *  Assignement no : 1 
 *  Mechatronics Track 
 *
 */
#undef F_CPU
#define F_CPU 1000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include "Types.h"
#include <util/delay.h>
#include "MACROS.h"
#include "counter.h"
#include "DIO.h"
#include "LCD.h"
#include "LCD_cfg.h"
#include "Timer.h"
#include "my_interrupt.h"
/*
 * Mapping
 *
 *
 *
 * */
volatile u_int8 counter ;
//  ((ptr_fn) 0x50) = &ISR ;
int main (void)
{	
	int state = FALSE ;
	SET_BIT(SREG,7) ;

	TCCR0=0x05;
	TIMSK=0x01;
	/*
	SET_PINS(TCCR0,0x05);
	SET_BIT(TIMSK,0) ;
    */
    DIO_PinDirection(7,OUTPUT) ;
	while (TRUE)
	{
		if (counter == 4)
		{
			state=!state ;
			DIO_SetPin(7,state);
			counter = 0 ;
		}

	}
/*	u_int8 x[11] = "Counter = ";

	counter_Init();
	LCD_Init();
	while(TRUE)
	{
	LCD_Clear();
	LCD_SendString_XY(x,0,0) ;
	counter_Run() ;
	_delay_ms(1000);
	}
	return FALSE;
}
ISR (INT0_vect)
{
	;
*/

}
/*
ISR (INT1_vect)
{
	;

}
*/
ISR (TIMER0_OVF_vect)
{
     counter++ ;
}
