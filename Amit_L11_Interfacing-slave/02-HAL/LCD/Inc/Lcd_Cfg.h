/************************************
 * Lcd_Cfg.h
 * Created on: May 8, 2021
 * Author: Eng_Fawzi
 **********************************/

#ifndef HAL_LCD_INC_LCD_CFG_H_
#define HAL_LCD_INC_LCD_CFG_H_

#define LCD_RS_PORT				DIO_PORTB
#define LCD_RS_CHANNEL			DIO_CHANNEL1

#define LCD_RW_PORT				DIO_PORTB
#define LCD_RW_CHANNEL			DIO_CHANNEL2

#define LCD_EN_PORT				DIO_PORTB
#define LCD_EN_CHANNEL			DIO_CHANNEL3

#define LCD_DATA_PORT			DIO_PORTA
#define LCD_MASK				(0xF0)

#define NO_CSTOM_CHAR		(8)
#define NO_CSTOM_CHAR_BYTES (8)
#endif /* HAL_LCD_INC_LCD_CFG_H_ */
