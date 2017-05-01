/*
 * ADC.h
 *
 *  Created on: Apr 2, 2017
 *      Author: ahmed
 */

#ifndef ADC_H_
#define ADC_H_
#include "Types.h"

// ADMUX pin 0 : 4
#define CHANNEL_0 0x00
#define CHANNEL_1 0x01
#define CHANNEL_2 0x02
#define CHANNEL_3 0x03
#define CHANNEL_4 0x04
#define CHANNEL_5 0x05
#define CHANNEL_6 0x06
#define CHANNEL_7 0x07

// ADLAR pin 4
#define LEFT_ADJUSTED  1
#define RIGHT_ADJUSTED 0

void ADC_Init(void);
u_int8 ADC_IsFinished(void);
u_int8 ADC_GetResult(void);
void ADC_StartConversion(void);
void ADC_ChannelSelection(u_int8 Channel);
void ADC_ISR (void (*ptr_fn)(void));

#endif /* ADC_H_ */
