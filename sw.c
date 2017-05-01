
#include "Types.h"
#include "DIO.h"
#include "MACROS.h"

/********************************************************************/
void sw_Init (u_int8 pin_no,u_int8 mode)
{
	DIO_PinDirection(pin_no,INPUT); 	 // sw1 increment
	if (mode == PULL_UP)
		DIO_SetPin(pin_no,HIGH) ;
	else
		DIO_SetPin(pin_no,LOW) ;
}
/********************************************************************/
u_int8 sw_Read (u_int8 pin_no)
{
	return DIO_GetPin(pin_no) ;
}
