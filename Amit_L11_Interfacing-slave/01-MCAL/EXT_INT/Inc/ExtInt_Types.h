/************************************
 * ExtInt_Types.h
 *  Created on: May 22, 2021
 *  Author: Eng_Fawzi
 ************************************/

#ifndef MCAL_EXT_INT_INC_EXTINT_TYPES_H_
#define MCAL_EXT_INT_INC_EXTINT_TYPES_H_

typedef enum
{
	INT0,
	INT1,
	INT2
}Int_ID;

typedef enum
{
	LOW_LEVEL_MODE,
	ANY_LEVEL_MODE,
	FAILING_EDGE_MODE,
	RISING_EDGE_MODE
}Sense_Mode_ID;
#endif /* MCAL_EXT_INT_INC_EXTINT_TYPES_H_ */
