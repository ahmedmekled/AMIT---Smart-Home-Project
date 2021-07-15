/*
 * Dio_Interface.h
 *
 *  Created on: Apr 30, 2021
 *      Author: Eng_Fawzi
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "Std_Types.h"
#include "Dio_Types.h"
#include "Dio_Private.h"
#include "Bit_Math.h"

void Dio_ConfigChannel(Dio_Port port,Dio_Channel channel, Dio_Direction direction);
void Dio_WriteChannel(Dio_Port port,Dio_Channel channel, Dio_Level level);
void Dio_FlipChannel(Dio_Port port,Dio_Channel channel);
Dio_Level Dio_ReadChannel(Dio_Port port,Dio_Channel channel);
void Dio_WriteChannels(Dio_Port port,u8 value,u8 mask);
void Dio_ConfigChannels(Dio_Port port,u8 mask,Dio_Direction direction);
#endif /* DIO_INTERFACE_H_ */
