/************************************
 * Lcd_Interface.h
 *  Created on: May 8, 2021
 *  Author: Eng_Fawzi
 ************************************/

#ifndef HAL_LCD_INC_LCD_INTERFACE_H_
#define HAL_LCD_INC_LCD_INTERFACE_H_
#define F_CPU 16000000UL
#include "Std_Types.h"
#include "Lcd_Types.h"
#include "Lcd_Cfg.h"
#include "Dio_Interface.h"
#include "util/delay.h"

void Lcd_Init(void);
void Lcd_Cmd(LcdCmdType cmd);
void Lcd_Data(u8 data);
void Lcd_DisplayChr(u8 chr);
void Lcd_DisplayStr(u8* str);
void Lcd_GoToRowColumn(u8 row,u8 column);
void Lcd_DisplayInt(s32 num);
#endif /* HAL_LCD_INC_LCD_INTERFACE_H_ */
