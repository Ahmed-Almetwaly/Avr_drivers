#ifndef HW_UART_H_
#define HW_UART_H_

#include "Types.h"
#include "reg.h"

// UDR   ---->	USART Transmit / Receive Data Buffer

/*
 * UCSRA ---->  USART Control and Status Register A
 * bit7(RXC)  ---->  USART Receive Complete
 * bit6(TXC)  ----> USART Transmit Complete
 * bit5(UDRE) ----> USART Data Register Empty (Transmitter is ready)
 * bit4(FE)   ----> Frame Error i.e., when the
	first stop bit of the next character in the receive buffer is zero
 * bit3(DOR) ----> Data OverRun receive buffer is full (two characters)
 	 Always set this bit to zero when writing to UCSRA
 * Bit2(PE) -----> Parity Error set this bit to zero when writing to UCSRA
 * Bit1 (U2X)  ----> Double the USART Transmission Speed
 * Bit0 (MPCM) ----> Multi-processor Communication Mode
 */

/*
 * UCSRB ---> USART Control and Status Register B
 * Bit 7 – RXCIE: RX Complete Interrupt Enable
 * Bit 6 – TXCIE: TX Complete Interrupt Enable
 * Bit 5 – UDRIE: USART Data Register Empty Interrupt Enable
 * Bit 4 – RXEN: Receiver Enable
 * Bit 3 – TXEN: Transmitter Enable
 * Bit 2 – UCSZ2: Character Size
 * Bit 1 – RXB8: Receive Data Bit 8 Must be read before reading the low bits from UDR
 * Bit 0 – TXB8: Transmit Data Bit 8 Must be written before writing the low bits to UDR.
 *
 */
#define UCSZ2_8BIT 0
#define UCSZ2_9BIT 1
/*
 * UCSRC – USART Control and Status Register C
 * Bit 7 – URSEL: Register Select accessing the UCSRC or the UBRRH Register
   It is read as one when reading UCSRC. The URSEL must be one when writing the UCSRC
 * Bit 6 – UMSEL: Mode Select Asynchronous 0 and Synchronous 1 mode of operation
 * Bits 5:4 – UPMn: Parity Mode [n = 1:0]
 * Bit 3 – USBS: Stop Bit Select
 * Bits 2:1 – UCSZn: Character Size [n = 1:0]
   Bit 1 – UCSZ0 - Bit 2 – UCSZ1
 * Bit 0 – UCPOL: Clock Polarity
   UCPOL bit sets the relationship between data output change and data input sample, and the
   synchronous clock (XCK)
 */
// Bit6,0
#define ASYNCHRONOUS 0
#define SYNCHRONOUS  1
// Bits 4,5
#define PAIRTY_DISABLE 0X00
#define PAIRTY_EVEN 0X02
#define PAIRTY_ODD 0X03
// Bit3
#define STOP_1BIT 0
#define STOP_2BIT 1
// Bit2,1
#define UCSZ01_5BIT 0x00
#define UCSZ01_6BIT 0x01
#define UCSZ01_7BIT 0x02
#define UCSZ01_8BIT 0x03
#define UCSZ01_9BIT 0x03

/*// Bit 0
#define XCK_ASYNCRONOUS 0
#define XCK_SYNCRONOUS  1
*/

/*
 * UBRRL – USART Baud Rate Register Low
   UBRRL contains the eight least significant bits of the USART baud rate
 */

/*
 * UBRRH – USART Baud Rate Register High
 * Bit 7 – URSEL: Register Select accessing the UBRRH or the UCSRC Register. It is read as zero when reading UBRRH.
 	 	   The URSEL must be zero when writing the UBRRH.
 * Bits 3:0 – UBRR[3:0]: USART Baud Rate Register [n = 11:8]
 */
// get baud rate from data sheet

//prototypes
void UART_Init (void) ;
void UART_Write (u_int8 data);
u_int8 UART_Read (void);
void UART_RX_INT_call (void(*ptr_fn)(void));
void UART_TX_INT_call (void(*ptr_fn)(void));
void UART_Empty_INT_call (void(*ptr_fn)(void));
u_int8 UART_Receive_Complete (void);
u_int8 UART_Trasmision_Complete (void);
u_int8 UART_Data_Reg_Empty_Complete (void);


#endif
