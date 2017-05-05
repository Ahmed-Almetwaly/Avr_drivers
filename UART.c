#include "reg.h"
#include "Types.h"
#include "MACROS.h"
#include "DIO.h"
#include "my_interrupt.h"

 void(*Gptr_RX)(void);
 void(*Gptr_TX)(void);
 void(*Gptr_Empty)(void);

void UART_Init (void)
{


}
void UART_Write (u_int8 data)
{


}

u_int8 UART_Read (void)
{
	u_int8 data ;


	return data ;
}
void UART_RX_INT_call (void(*ptr_fn)(void))
{
	Gptr_RX = ptr_fn;
}
void UART_TX_INT_call (void(*ptr_fn)(void))
{
	Gptr_TX = ptr_fn;
}
void UART_Empty_INT_call (void(*ptr_fn)(void))
{
	Gptr_Empty = ptr_fn;
}
ISR(USART0_RX_vect)
{
	Gptr_RX();
}
ISR(USART0_TX_vect)
{
	Gptr_TX() ;
}
ISR(USART0_UDRE_vect)
{
	Gptr_Empty() ;
}
