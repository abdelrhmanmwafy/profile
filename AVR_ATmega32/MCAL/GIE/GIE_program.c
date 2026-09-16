/*
 * GIE_program.c
 *
 *  Created on: Sep 13, 2025
 *      Author: mohamed.khaled
 */


#include "../../LIBS/STD_TYPES.h"
#include "../../LIBS/BIT_MATH.h"

#include "GIE_interface.h"


void GIE_voidEnable		(void)
{
	/*Enable GIE*/
	SET_BIT(SREG, 7);
}
void GIE_voidDisable	(void)
{
	/*Disable GIE*/
	CLR_BIT(SREG, 7);
}
