/*
 * ADC_cfg.h
 *
 *  Created on: Apr 2, 2017
 *      Author: ahmed
 */

#ifndef ADC_CFG_H_
#define ADC_CFG_H_

#include "ADC_private.h"
#include "MACROS.h"

// AREF , AVCC , INTERNAL
#define ADC_REF AREF
#define ADC_INIT_CHANNEL CHANNEL_0

//TRUE , FALSE
#define ADC_READ_Mode MODE_16
/*
 * for MODE_16
 * #define ADC_LEFT_ADJUST TRUE
 * for MODE_8
 * #define ADC_LEFT_ADJUST FALSE
 *
*/
#define ADC_AUTO_TRIGGER TRUE
#define ADC_TRIGER_SOURCE FREE_RUN
#define ADC_INTERRUPT FALSE
#define ADC_PRESCALE DEV_64



#endif /* ADC_CFG_H_ */
