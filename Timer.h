/*
 * Timer.h
 *
 *  Created on: Apr 3, 2017
 *      Author: ahmed
 */

#ifndef TIMER_H_
#define TIMER_H_


/*
 * TCCR0 – Timer/Counter Control Register
 * Bit 7 – FOC0: Force Output Compare (NO use up till now)
 * Bit 6 – WGM00: Waveform Generation Mode
 * Bit 3 – WGM01: Waveform Generation Mode
 * Bits 5:4 – COM0n: Compare Match Output Mode [n = 1:0] (Non PWM Mode)
 * Bits 2:0 – CS0n: Clock Select [n = 2:0]
 */

// Bit 3,6 TCCR0
#define NORMAL_MODE_WGM00 0
#define NOR_ModeMAL_MODE_WGM01 0
#define CTC_MODE_WGM00 0
#define CTC_MODE_WGM01 1

// Bits 5:4 - OC0 pin control On Compare Match
#define OC0_DISCONNECTED 0X00
#define OC0_TOGGLE 		 0X01
#define OC0_CLEAR 		 0X02
#define OC0_SET			 0X03

// Bit2:0 - Prescaller select
#define DEV_1       0X01
#define DEV_8       0X02
#define DEV_64      0X03
#define DEV_256     0X04
#define DEV_1024    0X05
#define EXT_FALL    0X06
#define EXT_FALL    0X07
/*
 * If external pin modes are used for the Timer/Counter0, transitions on the T0 pin will clock the counter
even if the pin is configured as an output. This feature allows software control of the counting.
 */

// TCNT0 - (My counter to check value in pooling)

/*
 * OCR0 – Output Compare Register (continuously compared with the counter value (TCNT0))
 *	compare match mode
 */

/*
 *TIMSK – Timer/Counter Interrupt Mask Register
 * Bit 1 – OCIE0: Timer/CounterTimer/Counter0 Output Compare Match Interrupt Enable
 * Bit 0 – TOIE0: Timer/CounterTimer/Counter0 Overflow Interrupt Enable
 */

/*
 * TIFR – Timer/Counter Interrupt Flag Register
 * Bit 1 – OCF0: Output Compare Flag 0
 * Bit 0 – TOV0: Timer/Counter0 Overflow Flag
 */


#endif /* TIMER_H_ */
