
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "Dio_Private.h"
#include "Dio_Interface.h"
#include "Spi_Private.h"
#include "Spi_Interface.h"
#define LED1_OFF (48)
#define LED1_ON  (49)

#define LED2_ON  (50)
#define LED2_OFF (51)
#define  F_CPU	16000000UL
#include "util/delay.h"


int main(void)
{
	
	u8 rdataSpi;
	/*The two led pins*/
	Dio_ConfigChannel(DIO_PORTD,DIO_CHANNEL3, OUTPUT);
	Dio_ConfigChannel(DIO_PORTC,DIO_CHANNEL2, OUTPUT);
	
	/*SPI init*/
	Spi_SlaveInit();
	while (1)
	{
		/*Receiving data from the Master MCU here*/
		rdataSpi = Spi_SlaveRead();
		
		/*Checking the received values from the Master MCU*/
		switch (rdataSpi)
		{
			case LED1_ON:
			Dio_WriteChannel(DIO_PORTD ,DIO_CHANNEL3 , STD_HIGH);
			break;
			case LED2_ON:
			Dio_WriteChannel(DIO_PORTC ,DIO_CHANNEL2 , STD_HIGH);
			break;
			case LED1_OFF:
			Dio_WriteChannel(DIO_PORTD ,DIO_CHANNEL3 , STD_LOW);
			break;
			case LED2_OFF:
			Dio_WriteChannel(DIO_PORTC ,DIO_CHANNEL2 , STD_LOW);
			break;
		}
		_delay_ms(50);
	}
}

