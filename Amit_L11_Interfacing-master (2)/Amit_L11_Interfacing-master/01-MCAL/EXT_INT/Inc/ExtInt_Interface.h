/**************************************
 * ExtInt_Interface.h
 *  Created on: May 22, 2021
 *  Author: Eng_Fawzi
 ***************************************/

#ifndef MCAL_EXT_INT_INC_EXTINT_INTERFACE_H_
#define MCAL_EXT_INT_INC_EXTINT_INTERFACE_H_
#include "ExtInt_Private.h"
#include "ExtInt_Types.h"
#include "Std_Types.h"
#include "Bit_Math.h"

void ExtInt_Enable(Int_ID);
void ExtInt_Disable(Int_ID);
void ExtInt_SnsCtrlSet(Int_ID,Sense_Mode_ID);

#endif /* MCAL_EXT_INT_INC_EXTINT_INTERFACE_H_ */
