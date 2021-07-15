

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "Dio_Private.h"
#include "Dio_Interface.h"
#include "Uart_Private.h"
#include "Uart_Interface.h"
#include "Spi_Private.h"
#include "Spi_Interface.h"
#include "Spi_Cfg.h"
#define  F_CPU	16000000UL
#include "util/delay.h"
#define LED1_OFF (48)
#define LED1_ON  (49)

#define LED2_ON  (50)
#define LED2_OFF (51)

int main(void)
{
	/*UART RX pin*/
	Dio_ConfigChannel(DIO_PORTD,DIO_CHANNEL0, INPUT);
	/*UART TX pin*/
	Dio_ConfigChannel(DIO_PORTD,DIO_CHANNEL1, OUTPUT);
	/*UART INIT*/
    UART_Init(UART_BAUDRATE_9600);
	/*SPI INIT*/
	Spi_MasterInit();

	/*Variable contains received data from UART*/
	u8 rdataUart = 1;
	/*Two leds to check UART is working*/
	Dio_ConfigChannel(DIO_PORTD,DIO_CHANNEL3, OUTPUT);
	Dio_ConfigChannel(DIO_PORTC,DIO_CHANNEL2, OUTPUT);
    while (1) 
    {
		
	
		rdataUart = UART_ReceiveChr();
		Dio_WriteChannel(SPI_SS_PORT, SPI_SS_CHANNEL, STD_LOW);
		Spi_MasterWrite(rdataUart);
		/*Checking data received from UART*/
		switch (rdataUart)
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
	return 0;
}

