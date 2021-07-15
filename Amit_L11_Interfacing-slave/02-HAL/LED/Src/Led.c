/*********************************
 * Led.c
 *
 *  Created on: Apr 30, 2021
 *  Author: Eng_Fawzi
 **********************************/

#include "Led_Interface.h"

void Led_Init(void)
{
	Dio_ConfigChannel(LED0_PORT, LED0_CHANNEL, OUTPUT);
	Dio_ConfigChannel(LED1_PORT, LED1_CHANNEL, OUTPUT);
	Dio_ConfigChannel(LED2_PORT, LED2_CHANNEL, OUTPUT);
}
void Led_ON(Led_ID led)
{
	switch (led)
	{
	case LED0:
#if (LED0_CONNECTION == FORWARD)
		Dio_WriteChannel(LED0_PORT,LED0_CHANNEL,STD_HIGH);
#elif (LED0_CONNECTION == REVERSE)
		Dio_WriteChannel(LED0_PORT,LED0_CHANNEL,STD_LOW);
#endif
		break;
	case LED1:
#if (LED1_CONNECTION == FORWARD)
		Dio_WriteChannel(LED1_PORT,LED1_CHANNEL,STD_HIGH);
#elif (LED1_CONNECTION == REVERSE)
		Dio_WriteChannel(LED1_PORT,LED1_CHANNEL,STD_LOW);
#endif
		break;
	case LED2:
#if (LED2_CONNECTION == FORWARD)
		Dio_WriteChannel(LED2_PORT,LED2_CHANNEL,STD_HIGH);
#elif (LED2_CONNECTION == REVERSE)
		Dio_WriteChannel(LED2_PORT,LED2_CHANNEL,STD_LOW);
#endif
		break;
	}
}
void Led_OFF(Led_ID led)
{
	switch (led)
	{
	case LED0:
#if (LED0_CONNECTION == FORWARD)
		Dio_WriteChannel(LED0_PORT,LED0_CHANNEL,STD_LOW);
#elif (LED0_CONNECTION == REVERSE)
		Dio_WriteChannel(LED0_PORT,LED0_CHANNEL,STD_HIGH);
#endif

		break;
	case LED1:
#if (LED1_CONNECTION == FORWARD)
		Dio_WriteChannel(LED1_PORT,LED1_CHANNEL,STD_LOW);
#elif (LED1_CONNECTION == REVERSE)
		Dio_WriteChannel(LED1_PORT,LED1_CHANNEL,STD_HIGH);
#endif
		break;
	case LED2:
#if (LED2_CONNECTION == FORWARD)
		Dio_WriteChannel(LED2_PORT,LED2_CHANNEL,STD_LOW);
#elif (LED2_CONNECTION == REVERSE)
		Dio_WriteChannel(LED2_PORT,LED2_CHANNEL,STD_HIGH);
#endif
		break;
	}
}
void Led_Toggle(Led_ID led)
{
	switch (led)
	{
	case LED0:
		Dio_FlipChannel(LED0_PORT,LED0_CHANNEL);
		break;
	case LED1:
		Dio_FlipChannel(LED1_PORT,LED1_CHANNEL);
		break;
	case LED2:
		Dio_FlipChannel(LED2_PORT,LED2_CHANNEL);
		break;
	}
}
