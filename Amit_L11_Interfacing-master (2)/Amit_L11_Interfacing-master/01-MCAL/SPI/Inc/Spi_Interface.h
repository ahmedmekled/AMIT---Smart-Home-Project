 /*************************************************
 *  File		: Spi.h
 *	Module		: SPI
 *	Target		: ATMEGA32
 *	Author		: mFawzi
 *  Description	:
 **************************************************/
#ifndef SPI_H
#define SPI_H

#include "Std_Types.h"
#include "Bit_Math.h"
#include "Spi_Cfg.h"
#include "Spi_Private.h"
#include "Dio_Interface.h"

#define SPI_SCK_FREQ_FCPU_DIV_4			(0<<0)
#define SPI_SCK_FREQ_FCPU_DIV_16		(1<<0)
#define SPI_SCK_FREQ_FCPU_DIV_64		(2<<0)
#define SPI_SCK_FREQ_FCPU_DIV_128		(3<<0)

void Spi_MasterInit(void);
void Spi_SlaveInit(void);
void Spi_MasterWrite(u8 data);
u8 Spi_MasterRead(void);
u8 Spi_SlaveRead(void);
#endif  /* UART_H */
