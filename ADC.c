/*
 * ADC.c
 *
 *  Created on: Apr 2, 2017
 *      Author: ahmed
 */

#include "MACROS.h"
#include "Types.h"
#include "ADC_private.h"
#include "DIO.h"
#include "ADC_cfg.h"
#include "avr/interrupt.h"

/*********************************************************************************/
static void (*Gptr) (void) ;
/*********************************************************************************/
void ADC_Init(void)
{
	//Set Pin as Input
	DIO_PinDirection(ADC_INIT_CHANNEL , INPUT) ;

	//ADC Enable
	SET_BIT(ADCSRA,7);

	//prescaler
	CLEAR_PINS(ADCSRA,0x07) ;
	SET_PINS(ADCSRA,ADC_PRESCALE);

	// Choose Channel
	CLEAR_PINS(ADMUX,0x1F);
	SET_PINS(ADMUX,ADC_INIT_CHANNEL);

	// Choose Reference
	CLEAR_PINS(ADMUX,0xC);
	SET_PINS(ADMUX,ADC_REF<<6);

    // Interrupt Enable
	if (ADC_INTERRUPT==TRUE)
		SET_BIT(ADCSRA,3);
	else
		CLEAR_BIT(ADCSRA,3);

	// TRigger Mode
	if (ADC_AUTO_TRIGGER == TRUE)
	{
		SET_BIT(ADCSRA,5);
		CLEAR_PINS(SFIOR,0xF0);
		SET_PINS(SFIOR,ADC_TRIGER_SOURCE);
	}
	else
		CLEAR_BIT(ADCSRA,5);

	// Reading Mode
	if (ADC_READ_Mode == MODE_16)
	{
		SET_BIT(ADMUX,5); // Left Adjusted Mode
	}
	else
	{
		CLEAR_BIT(ADMUX,5);
	}
}
/*********************************************************************************/
void ADC_StartConversion(void)
{
	SET_BIT(ADCSRA,6);
}
/*********************************************************************************/
u_int8 ADC_IsFinished(void)
{
	u_int8 value ;
	if(GET_BIT(ADCSRA,4)==TRUE)
	{
		value = TRUE ;
		// CLEAR INTERRUPT FLAG
		SET_BIT(ADCSRA,4);
	}
	else
		value = FALSE ;
	return value ;
}
/*********************************************************************************/
u_int16 ADC_GetResult(void)
{	u_int16 value ;
	if (ADC_READ_Mode == MODE_16)
		value = ADCLH ;
	else
		value = ADCH ;
	return value ;
}
/*********************************************************************************/
void ADC_ChannelSelection(u_int8 Channel)
{
    // ADMUX 0-->4
	CLEAR_PINS(ADMUX,0x1F);
	SET_PINS(ADMUX,Channel);
}
/*********************************************************************************/
void ADC_ISR (void(*ptr_fn)(void))
{
	Gptr = ptr_fn ;
}
/*********************************************************************************/
ISR(ADC_vect)
{
Gptr() ;
}
