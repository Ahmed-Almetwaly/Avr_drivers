#include "MACROS.h"
#include "segment.h"
#include "segment_cfg.h"
#include "counter.h"
#include <avr/delay.h>
#include "sw.h"
#include "counter_cfg.h"
#include "LCD.h"
#include "LCD_cfg.h"
/********************************************************************/
void counter_Init (void)
{
	// initializations
		segment_Init() ;
		sw_Init(SW1,PULL_UP); 	 // sw1 increment
		sw_Init(SW2,PULL_UP);	     // sw2 decrement
		segment_EnableInit(Seg1_EN);   // control signal for seg1
		segment_EnableInit(Seg2_EN);   // control signal for seg2
}
/********************************************************************/
void counter_Run (void)
{
	static u_int8 counter = 0 ;//seg_1 = 0, seg_2 = 0 ;
	//u_int8 x[3] ;
	if (sw_Read(SW1)==FALSE)
	{
		_delay_ms(100) ; // Nop
		if (counter == MAX_COUNT) // to avoid over flow
		{
			counter = MIN_COUNT ;
			//seg_1 = 0 ; seg_2 = 0 ;
		}
	/*	else if (seg_1 == 9) // if value exceed 9
		{
			seg_2 ++ ;
			counter ++ ;
			seg_1 = 0;
	    }	*/
		else
		{
			counter ++ ;
			//seg_1 ++ ;
		}
		while (sw_Read(SW1)==FALSE){}
	}
	if (sw_Read(SW2)==FALSE)
	{
		_delay_ms(100) ; // Nop
		if(counter == MIN_COUNT) // to avoid -ve
		{
			//seg_1 = 9 ; seg_2 = 9 ;
			counter = MAX_COUNT ;
		}
	/*	else if(seg_1 == MIN_COUNT)  // if value < 0
		{
			//seg_1 = 9 ;
			//seg_2 -- ;
			counter -- ;
		} */
		else
		{
			//seg_1 -- ;
			counter -- ;
		}
		while (sw_Read(SW2)==FALSE){}
	}
	//x = counter+'0' ;
	segment_DisableWrite(Seg1_EN);
	_delay_ms(10);
	segment_EnableWrite(Seg2_EN);
	_delay_ms(10);
	segment_Write(counter%10) ;
	_delay_ms(600);
	segment_DisableWrite(Seg2_EN);
	_delay_ms(10);
	segment_EnableWrite(Seg1_EN);
	_delay_ms(10);
	segment_Write(counter/10) ;
	//_delay_ms(200);
	LCD_GotoXY(10,1);
	LCD_SendData((counter/10)+'0');
	LCD_SendData((counter%10)+'0');
	//seg_1 = counter%10 ;
}
