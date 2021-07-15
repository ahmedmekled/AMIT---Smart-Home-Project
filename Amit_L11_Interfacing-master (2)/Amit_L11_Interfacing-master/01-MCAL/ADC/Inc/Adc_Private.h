/********************************
 * File  	:  Adc_Private.h
 * Date	 	:  Mar 23, 2021
 * Target	:  ATMEGA32
 * Author	:  Eng_Fawzi
 ********************************/

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define ADC_ADMUX_REG       (*(volatile u8*)0x27)
#define ADC_ADCSRA_REG		(*(volatile u8*)0x26)
#define ADC_ADCH_REG		(*(volatile u8*)0x25)
#define ADC_ADCL_REG		(*(volatile u8*)0x24)

#endif /* 01_SOURCE_MCAL_ADC_INC_ADC_PRIVATE_H_ */
