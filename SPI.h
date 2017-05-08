#ifndef SPI_H_
#define SPI_H_

//SPCR
#define SPR1_0 0
#define CPHA 2
#define CPOL 3
#define MSTR 4
#define DORD 5
#define SPE 6
#define SPIE 7

// Bit 0,1
#define SPI_DIV_4   0
#define SPI_DIV_16  1
#define SPI_DIV_64  2
#define SPI_DIV_128 3
// Bit 2
#define SAMPLE 0
#define RECIEVE 1
// Bit3
#define IDEL_HIGH 1
#define IDEL_LOW 0



// SPSR
#define SPIF 7
#define WCOL 6
#define SPI2X 0

// SPDR DATA

void SPI_INT_Call (void(*ptr_fn)(void)) ;
u_int8 SPI_Transfer (u_int8 data);
void SPI_Slave_init (void);
void SPI_MAster_init (void);




#endif
