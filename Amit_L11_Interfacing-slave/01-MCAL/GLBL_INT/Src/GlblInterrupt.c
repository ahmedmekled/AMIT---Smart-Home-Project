/*
 * GlblInterrupt.c
 *
 *  Created on: May 28, 2021
 *      Author: Eng_Fawzi
 */
#include "GlblInterrupt_Interface.h"
void EnableAllInterrupts()
{
	SET_BIT(GLBLINT_SREG_REG,I_BIT_POS);
}
void DisableAllInterrupts()
{
	CLEAR_BIT(GLBLINT_SREG_REG,I_BIT_POS);
}
