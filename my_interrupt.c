
#include "MACROS.h"
#include "avr/interrupt.h"
#include "Types.h"
#include "DIO.h"
#include "my_interrupt_private.h"
#include "my_interrupt_cfg.h"
/**********************************************************/
static void(*ptr_INT0)(void);
static void(*ptr_INT1)(void);
static void(*ptr_INT2)(void);
/**********************************************************/
void interrupt_Init (u_int8 INT_Number)
{
	// GLOBAL INTERRUPT ENABLE
	SET_BIT(SREG,7);

	// SET PINS AS INPUT
	if (INT_Number == INT0)
	{
		DIO_PinDirection(INT0_PIN,INPUT);
		SET_BIT(GICR,6);
		CLEAR_PINS(MCUCR,0x03);
		SET_PINS(MCUCR,INT0_MODE);
	}
	else if (INT_Number == INT1)
	{
		DIO_PinDirection(INT1_PIN,INPUT);
		SET_BIT(GICR,7);
		CLEAR_PINS(MCUCR,0x0C);
		SET_PINS(MCUCR,INT1_MODE<<2);
	}
	else if (INT_Number == INT2)
	{
		DIO_PinDirection(INT2_PIN,INPUT);
		SET_BIT(GICR,5);
		if (INT2_MODE == FALLING_EDGE2 )
			CLEAR_BIT(MCUCSR,6);
		else
			SET_BIT(MCUCSR,6);
	}
}
/**********************************************************/
void clear_INT_FLag (u_int8 INT_Number)
{
	if (INT_Number == INT0)
		SET_BIT(GIFR,6);
	else if (INT_Number == INT1)
		SET_BIT(GIFR,7);
	else if (INT_Number == INT2)
		SET_BIT(GIFR,5);
}
/**********************************************************/
void my_interrupt_INT0_Call(void(*ptr_fn)(void))
{
	ptr_fn = ptr_INT0;
}
/**********************************************************/
void my_interrupt_INT1_Call(void(*ptr_fn)(void))
{
	ptr_fn = ptr_INT1;
}
/**********************************************************/
void my_interrupt_INT2_Call(void(*ptr_fn)(void))
{
	ptr_fn = ptr_INT2;
}
/**********************************************************/
ISR(INT0_vect)
{
	ptr_INT0();
}
/**********************************************************/
ISR(INT1_vect)
{
	ptr_INT1();
}
/**********************************************************/
ISR(INT2_vect)
{
	ptr_INT2();
}
