#include "reg.h"
#include "MACROS.h"
#include "Types.h"
#include "SPI_cfg.h"
#include "SPI.h"
#include "avr/interrupt.h"

void (*Gptr_fn)(void);

void SPI_MAster_init (void)
{
	SET_PINS(SPCR,SPI_CLK);

	if (SPI_LEADING_EDGE == SAMPLE)
		CLEAR_BIT(SPCR,CPHA);
	else
		SET_BIT(SPCR,CPHA);

	if (SPI_IDEL == IDEL_HIGH)
		SET_BIT(SPCR,CPOL);
	else
		CLEAR_BIT(SPCR,CPOL);

	// Master - SLave Select
	SET_BIT(SPCR,MSTR);
	// Enable
	SET_BIT(SPCR,SPE);
	// Interrupt Enable
	if (SPI_INT == TRUE)
		SET_BIT(SPCR,SPIE);
	else
		CLEAR_BIT(SPCR,SPIE);
	// 2X SPEED
	if (SPI2X==TRUE)
		SET_BIT(SPSR,SPI2X);
	else
		CLEAR_BIT(SPSR,SPI2X);
}
/*---------------------------------------------------*/
void SPI_Slave_init (void)
{
	SET_PINS(SPCR,SPI_CLK);

	if (SPI_LEADING_EDGE == SAMPLE)
		CLEAR_BIT(SPCR,CPHA);
	else
		SET_BIT(SPCR,CPHA);

	if (SPI_IDEL == IDEL_HIGH)
		SET_BIT(SPCR,CPOL);
	else
		CLEAR_BIT(SPCR,CPOL);

	// Master - SLave Select
	CLEAR_BIT(SPCR,MSTR);
	// Enable
	SET_BIT(SPCR,SPE);
	// Interrupt Enable
	if (SPI_INT == TRUE)
		SET_BIT(SPCR,SPIE);
	else
		CLEAR_BIT(SPCR,SPIE);
	// 2X SPEED
	if (SPI2X==TRUE)
		SET_BIT(SPSR,SPI2X);
	else
		CLEAR_BIT(SPSR,SPI2X);
}
/*---------------------------------------------------*/
u_int8 SPI_Transfer (u_int8 data)
{
	SPDR = data;
	while (SPIF != TRUE );
	return SPDR;
}
/*-------------------------------------------------------*/
void SPI_INT_Call (void(*ptr_fn)(void))
{
	Gptr_fn = ptr_fn ;
}
/*-------------------------------------------------------*/
ISR(SPI_STC_vect)
{
	Gptr_fn();
}
