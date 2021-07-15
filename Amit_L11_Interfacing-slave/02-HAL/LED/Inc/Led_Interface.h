/*
 * Led_Interface.h
 *
 *  Created on: Apr 30, 2021
 *      Author: Eng_Fawzi
 */

#ifndef HAL_LED_INC_LED_INTERFACE_H_
#define HAL_LED_INC_LED_INTERFACE_H_
#include "Led_types.h"
#include "Dio_Interface.h"
#include "Led_Cfg.h"

void Led_Init(void);
void Led_ON(Led_ID led);
void Led_OFF(Led_ID led);
void Led_Toggle(Led_ID led);
#endif /* HAL_LED_INC_LED_INTERFACE_H_ */
