/*************************************
 * ExtInt.c
 *  Created on: May 22, 2021
 *  Author: Eng_Fawzi
 *************************************/

#include "ExtInt_Interface.h"
void ExtInt_Enable(Int_ID extIntID)
{
	switch (extIntID)
	{
	case INT0:
		SET_BIT(EXTINT_GICR_REG,EXT_INT0_EN_BIT);
		break;

	case INT1:
		SET_BIT(EXTINT_GICR_REG,EXT_INT1_EN_BIT);
		break;

	case INT2:
		SET_BIT(EXTINT_GICR_REG,EXT_INT2_EN_BIT);
		break;
	}
}
void ExtInt_Disable(Int_ID extIntID)
{
	switch (extIntID)
	{
	case INT0:
		CLEAR_BIT(EXTINT_GICR_REG,EXT_INT0_EN_BIT);
		break;

	case INT1:
		CLEAR_BIT(EXTINT_GICR_REG,EXT_INT1_EN_BIT);
		break;

	case INT2:
		CLEAR_BIT(EXTINT_GICR_REG,EXT_INT2_EN_BIT);
		break;
	}
}
void ExtInt_SnsCtrlSet(Int_ID extIntID,Sense_Mode_ID intSense)
{
	switch (extIntID)
	{
	case INT0:
		EXTINT_MCUCR_REG|=intSense<<EXT_INT0_SENSE_BIT;
		break;

	case INT1:
		EXTINT_MCUCR_REG|=intSense<<EXT_INT1_SENSE_BIT;
		break;

	case INT2:
		if (intSense == FAILING_EDGE_MODE)
		{
			CLEAR_BIT(EXTINT_MCUCSR_REG,EXT_INT2_SENSE_BIT);
		}
		else if (intSense == RISING_EDGE_MODE)
		{
			SET_BIT(EXTINT_MCUCSR_REG,EXT_INT2_SENSE_BIT);
		}
		else
		{
			/*	Do Nothing	*/
		}
		break;
	}
}
