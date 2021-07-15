/************************************
 * Lcd.c
 *  Created on: May 8, 2021
 *  Author: Eng_Fawzi
 ************************************/

#include "Lcd_Interface.h"
u8 customChar[NO_CSTOM_CHAR][NO_CSTOM_CHAR_BYTES]=
{
		{0x0A,0x1F,0x1F,0x1F,0x1F,0x0E,0x04,0x00},	/* Heart symbol	 */
		{0x04,0x1F,0x11,0x11,0x11,0x11,0x11,0x1F},	/* Empty battery */
		{0x04,0x1F,0x11,0x11,0x11,0x11,0x1F,0x1F},	/*	20% battery  */
		{0x04,0x1F,0x11,0x11,0x11,0x1F,0x1F,0x1F},  /*	40% battery  */
		{0x04,0x1F,0x11,0x11,0x1F,0x1F,0x1F,0x1F},	/*	60% battery  */
		{0x04,0x1F,0x11,0x1F,0x1F,0x1F,0x1F,0x1F},	/*	80% battery  */
		{0x04,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F},	/*	100% battery */
		{0x00,0x00,0x01,0x01,0x05,0x05,0x15,0x15},	/*	Mobile Signal*/
};
static void Lcd_EnablePulse(void)
{
	Dio_WriteChannel(LCD_EN_PORT, LCD_EN_CHANNEL, STD_HIGH);
	_delay_ms(1);
	Dio_WriteChannel(LCD_EN_PORT, LCD_EN_CHANNEL, STD_LOW);
	_delay_ms(2);
}
static void Lcd_WriteCustom(void)
{
	u8 loc_ByteIndex=0;
	u8 loc_CharIndx=0;
	for (loc_CharIndx=0;loc_CharIndx<NO_CSTOM_CHAR;loc_CharIndx++)
	{
		Lcd_Cmd(_LCD_CGRAM_START_ADDRESS +(loc_CharIndx*8));
			for (loc_ByteIndex =0; loc_ByteIndex<NO_CSTOM_CHAR_BYTES;loc_ByteIndex++)
			{
				Lcd_DisplayChr(customChar[loc_CharIndx][loc_ByteIndex]);
			}
	}
}
void Lcd_Init(void)
{
	Dio_ConfigChannel(LCD_RS_PORT, LCD_RS_CHANNEL, OUTPUT);
	Dio_ConfigChannel(LCD_RW_PORT, LCD_RW_CHANNEL, OUTPUT);
	Dio_ConfigChannel(LCD_EN_PORT, LCD_EN_CHANNEL, OUTPUT);

	Dio_ConfigChannels(LCD_DATA_PORT, LCD_MASK, OUTPUT);
	Dio_WriteChannel(LCD_RW_PORT, LCD_RW_CHANNEL, STD_LOW);

	_delay_ms(15);
	Lcd_Cmd(0x03);
	_delay_ms(5);
	Lcd_Cmd(0x03);
	_delay_us(100);
	Lcd_Cmd(0x03);
	Lcd_Cmd(0x02);
	Lcd_Cmd(_LCD_4BIT_MODE);
	Lcd_WriteCustom();
	Lcd_GoToRowColumn(0, 0);
}
void Lcd_Cmd(LcdCmdType cmd)
{
	u8 loc_LowNibble = cmd<<4;
	u8 loc_HighNibble = cmd;
	Dio_WriteChannel(LCD_RS_PORT, LCD_RS_CHANNEL, STD_LOW); /* Send CMD */

	Dio_WriteChannels(LCD_DATA_PORT, loc_HighNibble, LCD_MASK);
	Lcd_EnablePulse();
	Dio_WriteChannels(LCD_DATA_PORT, loc_LowNibble, LCD_MASK);
	Lcd_EnablePulse();
}
void Lcd_Data(u8 data)
{
	u8 loc_LowNibble = data<<4;
	u8 loc_HighNibble = data;
	Dio_WriteChannel(LCD_RS_PORT, LCD_RS_CHANNEL, STD_HIGH); /* Send data */

	Dio_WriteChannels(LCD_DATA_PORT, loc_HighNibble, LCD_MASK);
	Lcd_EnablePulse();
	Dio_WriteChannels(LCD_DATA_PORT, loc_LowNibble, LCD_MASK);
	Lcd_EnablePulse();
}
void Lcd_GoToRowColumn(u8 row,u8 column)
{
	switch (row)
	{
	case 0:
		Lcd_Cmd(0x80+column);
		break;

	case 1:
		Lcd_Cmd(0xC0+column);
		break;
	}
}
void Lcd_DisplayChr(u8 chr)
{
	Lcd_Data(chr);
}
void Lcd_DisplayStr(u8* str)
{
	while (*str != '\0')
	{
		Lcd_DisplayChr(*str);
		str++;
	}
}
void Lcd_DisplayInt(s32 intNum)
{
	if (intNum<0)
	{
		Lcd_DisplayChr('-');
		intNum=intNum*-1;
	}
	else if (intNum == 0)
	{
		Lcd_DisplayChr('0');
		return;
	}
	else
	{
		/*	Do Nothing	*/
	}
	Lcd_DisplayChr(intNum/10000+'0');
	Lcd_DisplayChr(intNum%10000/1000+'0');
	Lcd_DisplayChr(intNum%10000%1000/100+'0');
	Lcd_DisplayChr(intNum%10000%1000%100/10+'0');
	Lcd_DisplayChr(intNum%10000%1000%100%10+'0');
}
