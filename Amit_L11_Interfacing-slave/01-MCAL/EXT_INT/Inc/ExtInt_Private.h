/********************************
 * ExtInt_Private.h
 * Created on: May 22, 2021
 * Author: Eng_Fawzi
 ***********************************/

#ifndef MCAL_EXT_INT_INC_EXTINT_PRIVATE_H_
#define MCAL_EXT_INT_INC_EXTINT_PRIVATE_H_

#define EXTINT_GICR_REG			(*((volatile u8*)0x5B))
#define EXTINT_MCUCR_REG		(*((volatile u8*)0x55))
#define EXTINT_MCUCSR_REG		(*((volatile u8*)0x54))

#define EXT_INT0_EN_BIT			(6)
#define EXT_INT1_EN_BIT			(7)
#define EXT_INT2_EN_BIT			(5)

#define EXT_INT0_SENSE_BIT		(0)
#define EXT_INT1_SENSE_BIT		(2)
#define EXT_INT2_SENSE_BIT		(6)

#endif /* MCAL_EXT_INT_INC_EXTINT_PRIVATE_H_ */
