/********************************
 * File  	:  Timer_Private.h
 * Date	 	:  Mar 23, 2021
 * Target	:  ATMEGA32
 * Author	:  Eng_Fawzi
 ********************************/

#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

#include "Std_Types.h"

#define TIMER0_TCCR0_REG			(*(volatile u8*)0x53)
#define TIMER0_TCNT0_REG			(*(volatile u8*)0x52)
#define TIMER0_OCR0_REG				(*(volatile u8*)0x5C)
#define TIMER0_TIMSK_REG			(*(volatile u8*)0x59)
#define TIMER0_TIFR_REG				(*(volatile u8*)0x58)

#endif  /* TIMER0_PRIVATE_H_ */
