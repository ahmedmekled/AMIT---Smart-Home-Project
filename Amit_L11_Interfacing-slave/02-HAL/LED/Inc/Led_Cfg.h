/************************************
 * Led_Cfg.h
 *
 *  Created on: Apr 30, 2021
 *  Author: Eng_Fawzi
 ************************************/

#ifndef HAL_LED_INC_LED_CFG_H_
#define HAL_LED_INC_LED_CFG_H_

/*	LEDs HW Channels Mapping	*/
#define LED0_PORT		DIO_PORTC
#define LED0_CHANNEL	DIO_CHANNEL2

#define LED1_PORT		DIO_PORTC
#define LED1_CHANNEL	DIO_CHANNEL7

#define LED2_PORT		DIO_PORTD
#define LED2_CHANNEL	DIO_CHANNEL3

/*	LEDs HW Connection	*/
#define FORWARD      	(0)
#define REVERSE			(1)

#define LED0_CONNECTION	FORWARD
#define LED1_CONNECTION	FORWARD
#define LED2_CONNECTION	FORWARD
#endif /* HAL_LED_INC_LED_CFG_H_ */
