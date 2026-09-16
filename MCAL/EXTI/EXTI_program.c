/*
 * EXTI_program.c
 *
 *  Created on: Sep 13, 2025
 *      Author: mohamed.khaled
 */

#include "../../LIBS/STD_TYPES.h"
#include "../../LIBS/BIT_MATH.h"


#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"


static void (*Global_pFInt0 ) (void) = NULL;
static void (*Global_pFInt1 ) (void) = NULL;
static void (*Global_pFInt2 ) (void) = NULL;

void EXTI_voidInit	(void)
{
	/*config Sense control*/
#if EXTI_INT0_SENSE_CONTROL == EXTI_FALLING_EDGE
	CLR_BIT(MCUCR, 0);
	SET_BIT(MCUCR, 1);
#elif EXTI_INT0_SENSE_CONTROL == EXTI_RAISING_EDGE
	SET_BIT(MCUCR, 0);
	SET_BIT(MCUCR, 1);
#elif EXTI_INT0_SENSE_CONTROL == EXTI_LOW_LEVEL
	CLR_BIT(MCUCR, 0);
	CLR_BIT(MCUCR, 1);
#elif EXTI_INT0_SENSE_CONTROL == EXTI_ON_CHANGE
	SET_BIT(MCUCR, 0);
	CLR_BIT(MCUCR, 1);
#endif


#if EXTI_INT0_EN == EXTI_ENABLE
	/*enable PIE*/
	SET_BIT(GICR, INT0_BIT);
#elif EXTI_INT0_EN == EXTI_DISABLE
	CLR_BIT(GICR, INT0_BIT);
#endif

#if EXTI_INT1_EN == EXTI_ENABLE
	/*enable PIE*/
	SET_BIT(GICR, INT1_BIT);
#elif EXTI_INT1_EN == EXTI_DISABLE
	CLR_BIT(GICR, INT1_BIT);
#endif
}

void EXTI_voidEnable	(u8 Copy_u8IntId)
{
	switch(Copy_u8IntId)
	{
	case EXTI_INT0:
		SET_BIT(GICR, INT0_BIT);
		break;
	case EXTI_INT1:
		SET_BIT(GICR, INT1_BIT);
			break;
	case EXTI_INT2:
		SET_BIT(GICR, INT2_BIT);
			break;
	default:
		break;
	}
}
void EXTI_voidDisable	(u8 Copy_u8IntId)
{
	switch (Copy_u8IntId) {
	case EXTI_INT0:
		CLR_BIT(GICR, INT0_BIT);
		break;
	case EXTI_INT1:
		CLR_BIT(GICR, INT1_BIT);
		break;
	case EXTI_INT2:
		CLR_BIT(GICR, INT2_BIT);
		break;
	default:
		break;
	}
}

void EXTI_voidChangeSenseControl	(u8 Copy_u8IntId, u8 Copy_u8SenseControl)
{
	switch (Copy_u8IntId) {
	case EXTI_INT0:
		switch (Copy_u8SenseControl) {
		case EXTI_RAISING_EDGE:
			SET_BIT(MCUCR, 0);
			SET_BIT(MCUCR, 1);
			break;
		case EXTI_FALLING_EDGE:
			CLR_BIT(MCUCR, 0);
			SET_BIT(MCUCR, 1);
			break;
		case EXTI_LOW_LEVEL:
			CLR_BIT(MCUCR, 0);
			CLR_BIT(MCUCR, 1);
			break;
		case EXTI_ON_CHANGE:
			SET_BIT(MCUCR, 0);
			CLR_BIT(MCUCR, 1);
			break;
		default:
			break;
		}
		break;
	case EXTI_INT1:
		switch (Copy_u8SenseControl) {
		case EXTI_RAISING_EDGE:
			SET_BIT(MCUCR, 2);
			SET_BIT(MCUCR, 3);
			break;
		case EXTI_FALLING_EDGE:
			CLR_BIT(MCUCR, 2);
			SET_BIT(MCUCR, 3);
			break;
		case EXTI_LOW_LEVEL:
			CLR_BIT(MCUCR, 2);
			CLR_BIT(MCUCR, 3);
			break;
		case EXTI_ON_CHANGE:
			SET_BIT(MCUCR, 2);
			CLR_BIT(MCUCR, 3);
			break;
		default:
			break;
		}
		break;
	case EXTI_INT2:
		switch(Copy_u8SenseControl)
		{
		case EXTI_RAISING_EDGE:
			SET_BIT(MCUCSR, 6);
			break;
		case EXTI_FALLING_EDGE:
			CLR_BIT(MCUCSR, 6);
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

void EXTI_voidSetCallBack	(u8 Copy_u8IntId, void (*pf) (void))
{
	switch(Copy_u8IntId)
	{
	case EXTI_INT0 :
		Global_pFInt0 = pf;
		break;
	case EXTI_INT1:
		Global_pFInt1 = pf;
		break;
	case EXTI_INT2:
		Global_pFInt2 = pf;
		break;
	default:
		break;
	}
}




/* ISR */
void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
	if(Global_pFInt0 != NULL)
	{
		Global_pFInt0();
		/* clear the flag */
		SET_BIT(GIFR,6);

	}
}

void __vector_2 (void) __attribute__((signal));
void __vector_2 (void)
{
	if(Global_pFInt1 != NULL)
	{
		Global_pFInt1();

	}
}


void __vector_3 (void) __attribute__((signal));
void __vector_3 (void)
{
	if(Global_pFInt2 != NULL)
	{
		Global_pFInt2();

	}
}
