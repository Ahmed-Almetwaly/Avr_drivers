/*
 * DIO.c
 *
 *  Created on: Mar 21, 2017
 *      Author: ahmed
 */

#include"Types.h"
#include"reg.h"
#include"MACROS.h"

/********************************************************************/
void DIO_PinDirection( u_int8 pin_no,u_int8 direction )
{
	if(direction == OUTPUT)
		SET_BIT(*(&DDRA-3*(pin_no>>3)),pin_no&~0xF8) ;
	else
		CLEAR_BIT(*(&DDRA-3*(pin_no>>3)),pin_no&~0xF8) ;
}
/********************************************************************/
void DIO_SetPin( u_int8 pin_no,u_int8 state )
{
	if(state == HIGH)
		SET_BIT(*(&PORTA-3*(pin_no>>3)),pin_no&~0xF8) ;
	else
		CLEAR_BIT(*(&PORTA-3*(pin_no>>3)),pin_no&~0xF8) ;
}
/********************************************************************/
u_int8 DIO_GetPin( u_int8 pin_no )
{
	return GET_BIT(*(&PINA-3*(pin_no>>3)),pin_no&~0xF8);
}
/********************************************************************/
void DIO_PinMode(u_int8 pin_no,u_int8 mode )
{
	if(mode == PULL_UP)
		SET_BIT(*(&PORTA-3*(pin_no>>3)),pin_no&~0xF8) ;
	else
		CLEAR_BIT(*(&PORTA-3*(pin_no>>3)),pin_no&~0xF8) ;
}
/********************************************************************/
void DIO_PortDirection( u_int8 port_no, u_int8 pins_no,u_int8 direction )
{
	if(direction == OUTPUT)
		SET_PINS(*(&DDRA-3*port_no),pins_no) ;
	else
		CLEAR_PINS(*(&DDRA-3*port_no),pins_no) ;
}
/********************************************************************/
void DIO_SetPort(u_int8 port_no, u_int8 pins_no,u_int8 state)
{
	if(state == HIGH)
		SET_PINS(*(&PORTA-3*port_no),pins_no) ;
	else
		CLEAR_PINS(*(&PORTA-3*port_no),pins_no) ;
}
/********************************************************************/
void DIO_PortMode(u_int8 port_no, u_int8 pins_no,u_int8 mode)
{
	if(mode == PULL_UP)
		SET_PINS(*(&PORTA-3*port_no),pins_no) ;
	else
		CLEAR_PINS(*(&PORTA-3*port_no),pins_no) ;
}
/********************************************************************/
u_int8 DIO_GetPort(u_int8 port_no, u_int8 pins_no)
{
	return	GET_PINS(*(&PORTA-3*port_no),pins_no) ;
}
/********************************************************************/
void DIO_AssPort(u_int8 port_no,u_int8 value)
{
	Ass_PINS(*(&PORTA-3*port_no),value) ;
}
