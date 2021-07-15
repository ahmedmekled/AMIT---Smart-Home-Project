/*
 * Dio.c
 *
 *  Created on: Apr 30, 2021
 *      Author: Eng_Fawzi
 */

#include "Dio_Interface.h"

void Dio_ConfigChannel(Dio_Port port,Dio_Channel channel, Dio_Direction direction)
{
	switch (port)
	{
	case DIO_PORTA:
		if (direction == INPUT)
		{
			CLEAR_BIT(DIO_DDRA_REG,channel);
		}
		else
		{
			SET_BIT(DIO_DDRA_REG,channel);
		}
		break;
	case DIO_PORTB:
		if (direction == INPUT)
		{
			CLEAR_BIT(DIO_DDRB_REG,channel);
		}
		else
		{
			SET_BIT(DIO_DDRB_REG,channel);
		}
		break;
	case DIO_PORTC:
		if (direction == INPUT)
		{
			CLEAR_BIT(DIO_DDRC_REG,channel);
		}
		else
		{
			SET_BIT(DIO_DDRC_REG,channel);
		}
		break;
	case DIO_PORTD:
		if (direction == INPUT)
		{
			CLEAR_BIT(DIO_DDRD_REG,channel);
		}
		else
		{
			SET_BIT(DIO_DDRD_REG,channel);
		}
		break;
	}
}
void Dio_WriteChannel(Dio_Port port,Dio_Channel channel, Dio_Level level)
{
	switch (port)
	{
	case DIO_PORTA:
		if (level == STD_LOW)
		{
			CLEAR_BIT(DIO_PORTA_REG,channel);
		}
		else
		{
			SET_BIT(DIO_PORTA_REG,channel);
		}
		break;
	case DIO_PORTB:
		if (level == STD_LOW)
		{
			CLEAR_BIT(DIO_PORTB_REG,channel);
		}
		else
		{
			SET_BIT(DIO_PORTB_REG,channel);
		}
		break;
	case DIO_PORTC:
		if (level == STD_LOW)
		{
			CLEAR_BIT(DIO_PORTC_REG,channel);
		}
		else
		{
			SET_BIT(DIO_PORTC_REG,channel);
		}
		break;
	case DIO_PORTD:
		if (level == STD_LOW)
		{
			CLEAR_BIT(DIO_PORTD_REG,channel);
		}
		else
		{
			SET_BIT(DIO_PORTD_REG,channel);
		}
		break;
	}
}
void Dio_FlipChannel(Dio_Port port,Dio_Channel channel)
{
	switch (port)
	{
	case DIO_PORTA:
		TOGGLE_BIT(DIO_PORTA_REG,channel);
		break;
	case DIO_PORTB:
		TOGGLE_BIT(DIO_PORTB_REG,channel);
		break;
	case DIO_PORTC:
		TOGGLE_BIT(DIO_PORTC_REG,channel);
		break;
	case DIO_PORTD:
		TOGGLE_BIT(DIO_PORTD_REG,channel);
		break;
	}
}
Dio_Level Dio_ReadChannel(Dio_Port port,Dio_Channel channel)
{
	Dio_Level ret_level = STD_LOW;
	switch (port)
	{
	case DIO_PORTA:
		ret_level = CHECK_BIT(DIO_PINA_REG,channel);
		break;
	case DIO_PORTB:
		ret_level = CHECK_BIT(DIO_PINB_REG,channel);
		break;
	case DIO_PORTC:
		ret_level = CHECK_BIT(DIO_PINC_REG,channel);
		break;
	case DIO_PORTD:
		ret_level = CHECK_BIT(DIO_PIND_REG,channel);
		break;
	}
	return ret_level;
}
void Dio_WriteChannels(Dio_Port port,u8 value,u8 mask)
{
	switch (port)
	{
	case DIO_PORTA:
		DIO_PORTA_REG= (DIO_PORTA_REG & ~mask)|(value & mask);
		break;
	case DIO_PORTB:
		DIO_PORTB_REG= (DIO_PORTB_REG & ~mask)|(value & mask);
		break;
	case DIO_PORTC:
		DIO_PORTC_REG= (DIO_PORTC_REG & ~mask)|(value & mask);
		break;
	case DIO_PORTD:
		DIO_PORTD_REG= (DIO_PORTD_REG & ~mask)|(value & mask);
		break;
	}
}
void Dio_ConfigChannels(Dio_Port port,u8 mask,Dio_Direction direction)
{
	switch (port)
	{
	case DIO_PORTA:
		if (direction == INPUT)
		{
			DIO_DDRA_REG= (DIO_DDRA_REG & ~mask);
		}
		else
		{
			DIO_DDRA_REG |= mask;
		}
		break;
	case DIO_PORTB:
		if (direction == INPUT)
		{
			DIO_DDRB_REG= (DIO_DDRB_REG & ~mask);
		}
		else
		{
			DIO_DDRB_REG |= mask;
		}
		break;
	case DIO_PORTC:
		if (direction == INPUT)
		{
			DIO_DDRC_REG= (DIO_DDRC_REG & ~mask);
		}
		else
		{
			DIO_DDRC_REG |= mask;
		}
		break;
	case DIO_PORTD:
		if (direction == INPUT)
		{
			DIO_DDRD_REG= (DIO_DDRD_REG & ~mask);
		}
		else
		{
			DIO_DDRD_REG |= mask;
		}
		break;
	}
}
