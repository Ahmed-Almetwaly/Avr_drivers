/*
 * seven_seg.h
 *
 *  Created on: Mar 13, 2017
 *      Author: ahmed
 */

#ifndef SEGMENT_H_
#define SEGMENT_H_

#include "MACROS.h"
#include "Types.h"
//MODE OF 7SEG
#define COM_ANODE 1
#define COM_CATHOD 0
//NUMBERS
#define ZERO    0x3F
#define ONE     0x06
#define TWO     0x5B
#define THREE   0x4F
#define FOUR    0x66
#define FIVE    0x6D
#define SIX     0x7D
#define SEVEN   0x07
#define EIGHT   0xFF
#define NINE    0x6F

//prototypes
void segment_Write(u_int8 number) ;
void segment_Init(void) ;
void segment_EnableInit(u_int8 pin_no);
void segment_EnableWrite(u_int8 pin_no);
void segment_DisableWrite(u_int8 pin_no) ;

#endif /* SEGMENT_H_ */
