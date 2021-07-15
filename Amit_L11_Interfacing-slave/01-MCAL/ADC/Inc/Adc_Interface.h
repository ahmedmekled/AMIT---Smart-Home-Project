/********************************
 * File  	:  Adc.h
 * Date	 	:  Mar 23, 2021
 * Target	:  ATMEGA32
 * Author	:  Eng_Fawzi
 ********************************/

#ifndef ADC_H_
#define ADC_H_

#include "Std_Types.h"
#include "Bit_Math.h"
#include "Adc_Private.h"
#include "Adc_Types.h"
#define REF           		((u8) 1<<6)
#define AVCC5V_REF    			(1)
#define INTERNAL_REF  			(3)

#define ADC_LEFT_ADJUST_RESULT   ((u8)1<<5)     //ADC left adjust result

#define ADC_ENABLE				 ((u8)1<<7)     //ADC Enable
#define ADC_START_CONVERSION     ((u8)1<<6)     //ADC start conversion
#define ADC_INTERRUPT_ENABLE     ((u8)1<<3)     //ADC interrupt enable
/*					ADC prescaler			*/
/*ADC frequancy must be between 50KHZ and 200KHZ*/
#define ADCPS_2         (1)
#define ADCPS_4         (2)
#define ADCPS_8         (3)
#define ADCPS_16        (4)
#define ADCPS_32        (5)
#define ADCPS_64        (6)
#define ADCPS_128       (7)

#define ADIF_BIT_NO		(4)
#define ADSC_BIT_NO		(6)


void adcInit(void);
u16 adcRead(adc_ChannelID chnlNo);

#endif /* 01_SOURCE_MCAL_ADC_INC_ADC_H_ */
