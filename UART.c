#include "reg.h"
#include "Avr/interrupt.h"
#include "Types.h"
#include "MACROS.h"
#include "DIO.h"
#include "my_interrupt.h"
#include "UART_cfg.h"

// Pointer to function used in the call back function
 void(*Gptr_RX)(void);
 void(*Gptr_TX)(void);
 void(*Gptr_Empty)(void);

void UART_Init (void)
{
	// Baud Rate
	if (UART_BAUD_RATE < 0xFF)
	{
		//CLEAR_BIT(UBRRH,7);
		//CLEAR_PINS(UBRRH,0x0F);

		Ass_PINS(UBRRL,UART_BAUD_RATE);
	}
	else
	{
		//CLEAR_BIT(UBRRH,7);
		//CLEAR_PINS(UBRRH,0x0F);
		//SET_PINS(UBRRH,UART_BAUD_RATE>>8);

		Ass_PINS(UBRRL,UART_BAUD_RATE);
	}

	/*--------------------------------------------------------------*/

	/*
	// Interrupt Enable
	if (RX_Int_En || TX_Int_En || Data_Reg_Empty_Int_En)
		SET_BIT(SREG,7);
	// RX_Int_En
	if(RX_Int_En == TRUE)
		SET_BIT(UCSRB,7);
	else
		CLEAR_BIT(UCSRB,7);
	// TX_Int_En
	if(TX_Int_En == TRUE)
		SET_BIT(UCSRB,6);
	else
		CLEAR_BIT(UCSRB,6);
	// Data_Reg_Empty_Int_En
	if(Data_Reg_Empty_Int_En == TRUE)
		SET_BIT(UCSRB,5);
	else
		CLEAR_BIT(UCSRB,5);
	*/
	/*--------------------------------------------------------------*/
	// RX_EN
	if(RX_En == TRUE)
		SET_BIT(UCSRB,4);
	else
		CLEAR_BIT(UCSRB,4);
	// RX_EN
	if(TX_En == TRUE)
		SET_BIT(UCSRB,3);
	else
		CLEAR_BIT(UCSRB,3);
	/*--------------------------------------------------------------*/
	switch (UART_CHAR_SIZE)
	{
		case 5:
			CLEAR_BIT(UCSRB,2);
			SET_BIT(UCSRC,7);
			CLEAR_PINS(UCSRC,0x03);
			SET_PINS(UCSRC,UCSZ01_5BIT<<1);
			break;
		case 6:
			CLEAR_BIT(UCSRB,2);
			SET_BIT(UCSRC,7);
			CLEAR_PINS(UCSRC,0x03);
			SET_PINS(UCSRC,UCSZ01_6BIT<<1);
			break;
		case 7:
			CLEAR_BIT(UCSRB,2);
			SET_BIT(UCSRC,7);
			CLEAR_PINS(UCSRC,0x03);
			SET_PINS(UCSRC,UCSZ01_7BIT<<1);
			break;
		case 8:
			CLEAR_BIT(UCSRB,2);
			SET_BIT(UCSRC,7);
			CLEAR_PINS(UCSRC,0x03);
			SET_PINS(UCSRC,UCSZ01_8BIT<<1);
			break;
		case 9:
			SET_BIT(UCSRB,2);
			SET_BIT(UCSRC,7);
			CLEAR_PINS(UCSRC,0x03);
			SET_PINS(UCSRC,UCSZ01_9BIT<<1);
			break;
	}
	/*--------------------------------------------------------------*/
	// Double Speed Mode
	if (UART_2X_MODE == TRUE)
	{
		CLEAR_BIT(UCSRA,2);
		SET_BIT(UCSRA,1);
	}
	else
	{
		CLEAR_BIT(UCSRA,2);
		CLEAR_BIT(UCSRA,1);
	}
	/*--------------------------------------------------------------*/
	// Choose Mode ASYNCHRONOUS , SYNCHRONOUS
	if (UART_MODE == SYNCHRONOUS)
	{
		SET_BIT(UCSRC,7);
		SET_BIT(UCSRC,0);
		SET_BIT(UCSRC,6);
	}
	else
	{
		SET_BIT(UCSRC,7);
		CLEAR_BIT(UCSRC,0);
		CLEAR_BIT(UCSRC,6);
	}
	/*--------------------------------------------------------------*/
// stop
	SET_BIT(UCSRC,7);
	if (STOP_1BIT)
		SET_BIT(UCSRC,3);
	else
		CLEAR_BIT(UCSRC,3);
}
/*--------------------------------------------------------------*/
void UART_Write (u_int16 data)
{
	if (UART_CHAR_SIZE>8)
	{
		if (((data&0xFF00)>>8)==TRUE)
			SET_BIT(UCSRB,0);
		else
			CLEAR_BIT(UCSRB,0);
		Ass_PINS(UDR,(data<<1)>>1);
	}
	else
	Ass_PINS(UDR,data);
}
/*--------------------------------------------------------------*/
u_int16 UART_Read (void)
{
	u_int16 data ;
	if (UART_CHAR_SIZE>8)
		data = (GET_BIT(UCSRB,1)<<8)|GET_PINS(UDR,0xFF);
	else
		data = GET_PINS(UDR,0xFF);
	return data ;
}
/*--------------------------------------------------------------*/
u_int8 UART_Trasmision_Complete (void)
{
	return GET_BIT(UCSRA,6) ;
}
/*--------------------------------------------------------------*/
u_int8 UART_Receive_Complete (void)
{
	u_int8 state ;
	if (GET_BIT(UCSRA,4)||GET_BIT(UCSRA,2))
		state = FALSE ;
	else
		state = GET_BIT(UCSRA,7) ;
	return state  ;
}
/*--------------------------------------------------------------*/
u_int8 UART_Data_Reg_Empty_Complete (void)
{
	return GET_BIT(UCSRA,5) ;
}
/*--------------------------------------------------------------*/
void UART_RX_INT_call (void(*ptr_fn)(void))
{
	Gptr_RX = ptr_fn;
}
/*--------------------------------------------------------------*/
void UART_TX_INT_call (void(*ptr_fn)(void))
{
	Gptr_TX = ptr_fn;
}
/*--------------------------------------------------------------*/
void UART_Empty_INT_call (void(*ptr_fn)(void))
{
	Gptr_Empty = ptr_fn;
}
/*--------------------------------------------------------------*/
ISR(USART0_RX_vect)
{
	Gptr_RX();
}
/*--------------------------------------------------------------*/
ISR(USART0_TX_vect)
{
	Gptr_TX() ;
}
/*--------------------------------------------------------------*/
ISR(USART0_UDRE_vect)
{
	Gptr_Empty() ;
}
