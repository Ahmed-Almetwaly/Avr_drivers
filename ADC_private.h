/*
 * ADC_private.h
 *
 *  Created on: Apr 29, 2017
 *      Author: ahmed
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

/*------------------------------------------------------------------------------------------------------------------*/

// #define ADCSRA *((volatile u_int8 *) 0x26)

/* ADCSRA
 * 0:2 --> prescale use 32
 *  3 -> ADC interrupt enable
 *  4 -> ADC interrupt flag  /// clear by write 1
 *  5 -> ADATE: ADC Auto Trigger Enable
 *  6 -> ADSC: ADC Start Conversion
 *  7 -> ADCEN -> Enable ADC
 * */

//prescaler selection
#define DEV_2   0X01
#define DEV_4   0X02
#define DEV_8   0X03
#define DEV_16  0X04
#define DEV_32  0X05
#define DEV_64  0X06
#define DEV_128 0X07

/*------------------------------------------------------------------------------------------------------------------*/
// #define ADMUX  *((volatile u_int8 *) 0x27)

/*
 * ADMUX
 * pin 6,7  // Reference Selection
 * pin5 ---> ADLAR = 1(set) left adjusted Result
 * pins 0:4 -->   choose channel
 *
 */

// ADMUX pin 6,7
#define AREF     (0X00) // AREF, Internal Vref turned off
#define AVCC     (0X01) // AVCC with external capacitor at AREF pin
#define INTERNAL (0X03) // Internal 2.56V Voltage Reference with external capacitor at AREF pin

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
// #define ADLAR  *((volatile u_int8 *) 0x26)

// ADLAR pin 4
#define LEFT_ADJUSTED  1
#define RIGHT_ADJUSTED 0

/*----------------------------------------------------------------------------------------------------*/

// #define ADCL   *((volatile u_int8 *) 0x24)
// #define ADCH   *((volatile u_int8 *) 0x25)
// #define ADCLH  *((volatile u_int16 *) 0x24)

/*----------------------------------------------------------------------------------------------------*/

// SFIOR � Special Function IO Register Bits 7:5 ADC Auto Trigger Source p281
// #define SFIOR *((volatile u_int8 *) 0x50)

/*
 * FROM PIN 5-->7 TO SELECT TRIGGER SOURCE
 *  YOU MUST CLEAR PIN 4
 * */

#define FREE_RUN 0X00
#define ANALOGE_COMP  0X01
#define EXTERNAL_INT0 0X02
#define TIMER0_COMP 0X03
#define TIMER0_OVF 0X04
#define TIMER1_COMP 0X05
#define TIMER1_OVF 0X06
#define TIMER1_CAP_EVENT 0X07

/*-----------------------------------------------------------------------------------------------------------------------*/
// Modes of reading

#define MODE_16 TRUE
#define MODE_8 FALSE

#endif /* ADC_PRIVATE_H_ */
