/**************************************
 * Dio_Types.h
 * Created on: Apr 30, 2021
 * Author: Eng_Fawzi
 **************************************/

#ifndef DIO_TYPES_H_
#define DIO_TYPES_H_

 typedef enum{
 DIO_PORTA,
 DIO_PORTB,
 DIO_PORTC,
 DIO_PORTD
 }Dio_Port;

 typedef enum{
 DIO_CHANNEL0,
 DIO_CHANNEL1,
 DIO_CHANNEL2,
 DIO_CHANNEL3,
 DIO_CHANNEL4,
 DIO_CHANNEL5,
 DIO_CHANNEL6,
 DIO_CHANNEL7
 }Dio_Channel;

 typedef enum{
 INPUT,
 OUTPUT
 }Dio_Direction;

 typedef enum{
 STD_LOW,
 STD_HIGH
 }Dio_Level;

#endif /* DIO_TYPES_H_ */
