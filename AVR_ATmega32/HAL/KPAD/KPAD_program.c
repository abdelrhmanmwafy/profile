/*
 * KPAD_program.c
 *
 *  Created on: Sep 5, 2025
 *      Author: mohamed.khaled
 */
#define F_CPU	8000000UL
#include "avr/delay.h"

#include "../../LIBS/STD_TYPES.h"
#include "../../LIBS/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "KPAD_interface.h"
#include "KPAD_private.h"
#include "KPAD_config.h"



void KPAD_voidInit	(void)
{
	/* Rows input + pull up*/
	DIO_voidSetPinDirection(KPAD_PORT, KPAD_R0, DIO_INPUT);
	DIO_voidSetPinDirection(KPAD_PORT, KPAD_R1, DIO_INPUT);
	DIO_voidSetPinDirection(KPAD_PORT, KPAD_R2, DIO_INPUT);
	DIO_voidSetPinDirection(KPAD_PORT, KPAD_R3, DIO_INPUT);

	for(u8 i = KPAD_ROW_INIT ; i < KPAD_ROW_END + 1 ; i++)
	{
		DIO_voidSetPinValue(KPAD_PORT, i, DIO_HIGH);
	}

	/* Cols output the default High */
	for(u8 i = KPAD_COL_INIT ; i < KPAD_COL_END + 1 ; i++)
	{
		DIO_voidSetPinDirection(KPAD_PORT, i , DIO_OUTPUT);
		DIO_voidSetPinValue(KPAD_PORT, i , DIO_HIGH);
	}
}

u8 KPAD_u8GetPressed	(void)
{
	u8 Local_u8ReturnedValue = KPAD_NOT_PRESSED;
	u8 Local_u8GetPressed;
	u8 Local_u8Col;
	u8 Local_u8Row;

	for(Local_u8Col = KPAD_COL_INIT ; Local_u8Col < KPAD_COL_END + 1 ; Local_u8Col++)
	{
		DIO_voidSetPinValue(KPAD_PORT, Local_u8Col, DIO_LOW);
		for(Local_u8Row = KPAD_ROW_INIT; Local_u8Row < KPAD_ROW_END +1 ; Local_u8Row++)
		{
			Local_u8GetPressed = DIO_u8GetPinValue(KPAD_PORT, Local_u8Row);

			if( Local_u8GetPressed == 0)
			{
				/*delay for debouncing*/
				_delay_ms(30);
				Local_u8GetPressed = DIO_u8GetPinValue(KPAD_PORT, Local_u8Row);
				if(Local_u8GetPressed == 0 )
				{
					Local_u8ReturnedValue = KPAD_Au8Values[Local_u8Row - KPAD_ROW_INIT][Local_u8Col - KPAD_COL_INIT];
				}

				while(Local_u8GetPressed == 0)
				{
					Local_u8GetPressed = DIO_u8GetPinValue(KPAD_PORT, Local_u8Row);
				}

			}
		}
		DIO_voidSetPinValue(KPAD_PORT, Local_u8Col, DIO_HIGH);
	}

	return Local_u8ReturnedValue;
}
