/*
 * LED_program.c
 *
 *  Created on: Aug 23, 2025
 *      Author: mohamed.khaled
 */

#include "../../LIBS/STD_TYPES.h"
#include "../../LIBS/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "LED_interface.h"


void LED_voidInit	(Led_t*	Copy_pstructLed)
{
	/*configure the pin to be output pin*/
	DIO_voidSetPinDirection(Copy_pstructLed->Port, Copy_pstructLed->Pin, DIO_OUTPUT);

	switch(Copy_pstructLed->State)
	{
	case LED_ACTIVE_HIGH :
		DIO_voidSetPinValue(Copy_pstructLed->Port, Copy_pstructLed->Pin, DIO_LOW);
		break;
	case LED_ACTIVE_LOW :
		DIO_voidSetPinValue(Copy_pstructLed->Port, Copy_pstructLed->Pin, DIO_HIGH);
		break;
	default :
		break;
	}
}
void LED_voidOn		(Led_t*	Copy_pstructLed)
{
	switch(Copy_pstructLed->State)
		{
		case LED_ACTIVE_HIGH :
			DIO_voidSetPinValue(Copy_pstructLed->Port, Copy_pstructLed->Pin, DIO_HIGH);
			break;
		case LED_ACTIVE_LOW :
			DIO_voidSetPinValue(Copy_pstructLed->Port, Copy_pstructLed->Pin, DIO_LOW);
			break;
		default :
			break;
		}
}


void LED_voidOff	(Led_t*	Copy_pstructLed)
{
	switch(Copy_pstructLed->State)
		{
		case LED_ACTIVE_HIGH :
			DIO_voidSetPinValue(Copy_pstructLed->Port, Copy_pstructLed->Pin, DIO_LOW);
			break;
		case LED_ACTIVE_LOW :
			DIO_voidSetPinValue(Copy_pstructLed->Port, Copy_pstructLed->Pin, DIO_HIGH);
			break;
		default :
			break;
		}
}
