#include "MACROS.h"
#include "LCD_cfg.h"
#include "DIO.h"
#include "Types.h"
#include <avr/delay.h>
#include "LCD_private.h"
#include "reg.h"
/********************************************************************/
void LCD_Send_Command(u_int8 cmd)
{
	//initialization
	DIO_SetPin(LCD_RS,LOW);

	//Write command on Port
	DIO_SetPort(LCD_PORT,0XF0,LOW);
	DIO_SetPort(LCD_PORT,cmd&0XF0,HIGH);
/*
 * ()|(Data&0xF0)
 *   =(Data<<4)
 * */
	// sending half command
	DIO_SetPin(LCD_EN,HIGH);
	_delay_ms(1) ;
	DIO_SetPin(LCD_EN,LOW);

	// writing the 2nd half
	DIO_SetPort(LCD_PORT,0XF0,LOW);
	DIO_SetPort(LCD_PORT,(cmd<<4)&0xF0,HIGH);

	// sending the 2nd half
	DIO_SetPin(LCD_EN,HIGH);
	_delay_ms(1) ;
	DIO_SetPin(LCD_EN,LOW);
}
/********************************************************************/
void LCD_Clear(void)
{
	// Clear command 0x01
	//initialization
	DIO_SetPin(LCD_RS,LOW);

	//Write command on Port
	DIO_SetPort(LCD_PORT,0XF0,LOW);
	DIO_SetPort(LCD_PORT,LCD_CLEAR&0XF0,HIGH);
/*
 * ()|(Data&0xF0)
 *   =(Data<<4)
 * */
	// sending half command
	DIO_SetPin(LCD_EN,HIGH);
	_delay_ms(1) ;
	DIO_SetPin(LCD_EN,LOW);

	// writing the 2nd half
	DIO_SetPort(LCD_PORT,0XF0,LOW);
	DIO_SetPort(LCD_PORT,(LCD_CLEAR<<4)&0xF0,HIGH);

	// sending the 2nd half
	DIO_SetPin(LCD_EN,HIGH);
	_delay_ms(1) ;
	DIO_SetPin(LCD_EN,LOW);
}
/********************************************************************/
void LCD_Init (void)
{
	//Set Data/command port output
	DIO_PortDirection(LCD_PORT,0xF0,OUTPUT);
	DIO_SetPort(LCD_PORT,0xF0,LOW);

	// set RS and EN output
	DIO_PinDirection(LCD_RS,OUTPUT);
	DIO_PinDirection(LCD_EN,OUTPUT);

	// initalization command
	LCD_Send_Command(LCD_4BIT_0) ;
	LCD_Send_Command(LCD_4BIT_1) ;
	LCD_Send_Command(LCD_4BIT_2) ; // Enable 4bit Mode  / 0x38-->8bit Mode
	LCD_Send_Command(LCD_CURSOR) ; // Auto increment , LCD on , Cursor off

	//clear LCD
	LCD_Clear();
}
/********************************************************************/

void LCD_SendData(u_int8 data)
{
	//initialization
	DIO_SetPin(LCD_RS,HIGH);

	//Write data on Port
	DIO_SetPort(LCD_PORT,0XF0,LOW);
	DIO_SetPort(LCD_PORT,data&0XF0,HIGH);

	// sending half data
	DIO_SetPin(LCD_EN,HIGH);
	_delay_ms(1) ;
	DIO_SetPin(LCD_EN,LOW);

	// writing the 2nd half
	DIO_SetPort(LCD_PORT,0XF0,LOW);
	DIO_SetPort(LCD_PORT,(data<<4)&0xF0,HIGH);

	// sending the 2nd half
	DIO_SetPin(LCD_EN,HIGH);
	_delay_ms(1) ;
	DIO_SetPin(LCD_EN,LOW);
}
/********************************************************************/

void LCD_GotoXY(u_int8 x, u_int8 y)
{
	if(y==0)
		LCD_Send_Command(0x80 + x) ;
	else // note DDRAM start from 0x80 and 2nd row starts from 0xC0
		LCD_Send_Command(0x80 + 0x40 + x) ;
}
/********************************************************************/
void LCD_SendString(u_int8 *str)
{
	while (*str != '\0') // NULL
	{
		LCD_SendData(*str);
		str++ ;
	}
}
/********************************************************************/
void LCD_SendString_XY(u_int8 *str, u_int8 x, u_int8 y)
{
	LCD_GotoXY(x,y);
	LCD_SendString(str);
}
