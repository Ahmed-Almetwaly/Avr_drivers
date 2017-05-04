/*
 * seven_seg.c
 *
 *  Created on: Mar 13, 2017
 *      Author: Ahmed Almetwaly
 *  ------------------------------------
 *  Function Name  : segment ()
 *	Input Argument : u_int8 Reg (Register value)
 *					 u_int8 number (desired to display on 7-seg)
 */
#include "MACROS.h"
#include "Types.h"
#include "segment_cfg.h"
#include "segment.h"
#include "DIO.h"
#include "reg.h"

void segment_Init(void)
{
	//Function of 7segs.
	//Assume you use the hole port
//set port output
DIO_PortDirection(PORT_NO, 0XFF,OUTPUT ) ;
if (MODE==COM_ANODE)
	DIO_SetPort(PORT_NO, 0XFF,HIGH ) ;
else //COM_CATHOD
	DIO_SetPort(PORT_NO, 0XFF,LOW ) ;
}
/********************************************************************/
void segment_Write(u_int8 number)
{
	u_int8 seg[10] = {ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
	if (MODE==COM_ANODE)
		DIO_AssPort(PORT_NO,~seg[number]);
	else //COM_CATHOD
		DIO_AssPort(PORT_NO,seg[number]);
}
/********************************************************************/
void segment_EnableInit(u_int8 pin_no)
{
	DIO_PinDirection(pin_no,OUTPUT);
	if (MODE==COM_ANODE)
		DIO_SetPin(pin_no,LOW);
	else //COM_CATHOD
		DIO_SetPin(pin_no,HIGH);
}
/********************************************************************/
void segment_EnableWrite(u_int8 pin_no)
{
	if (MODE==COM_ANODE)
		DIO_SetPin(pin_no,HIGH);
	else //COM_CATHOD
		DIO_SetPin(pin_no,LOW);
}
/********************************************************************/
void segment_DisableWrite(u_int8 pin_no)
{
	if (MODE==COM_ANODE)
		DIO_SetPin(pin_no,LOW);
	else //COM_CATHOD
		DIO_SetPin(pin_no,HIGH);
}
