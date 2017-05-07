/*
 * Timer.c
 *
 *  Created on: Apr 3, 2017
 *      Author: ahmed
 */
#include "Types.h"
#include "reg.h"
#include "Timer_cfg.h"
#include "MACROS.h"

void(*Gptr_OVF)(void);
void(*Gptr_CTC)(void);

void Timer0_Init (void)
{
	if (TIMER_MODE == OVF_MODE)
	{

	}
	else
	{


	}
}
/*------------------------------------------*/
void Timer0_COMP_VALUE (u_int8 value)
{
	Ass_PINS(OCR0,value);
}
/*------------------------------------------*/
u_int8 Timer0_OVF_Check (void)
{
	return GIT_BIT(TIFR,0);
}
/*------------------------------------------*/
u_int8 Timer0_CTC_Check (void)
{
	return GIT_BIT(TIFR,1);
}
/*------------------------------------------*/
void Timer0_OVF_Int_Call(void (*ptr_fn)(void))
{
	Gptr_OVF=ptr_fn;
}
/*------------------------------------------*/
void Timer0_CTC_Int_Call(void (*ptr_fn)(void))
{
	Gptr_CTC=ptr_fn;
}
/*------------------------------------------*/
ISR(TIMER0_COMP_vect)
{
	Gptr_CTC();
}
/*------------------------------------------*/
ISR(TIMER0_OVF_vect)
{
	Gptr_OVF();
}
