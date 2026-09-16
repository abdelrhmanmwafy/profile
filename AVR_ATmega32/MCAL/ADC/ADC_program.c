/*
 * ADC_program.c
 *
 *  Created on: Sep 13, 2025
 *      Author: mohamed.khaled
 */


#include "../../LIBS/STD_TYPES.h"
#include "../../LIBS/BIT_MATH.h"

#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"

void ADC_voidInit	(void)
{
	/*
	 * ref voltge = 5
	 * right adjust
	 * ADC0
	 * Enable ADC
	 * Disable PIE (( Polling ))
	 * prescaler / 128
	 * */
	ADMUX = 	0b01000000;
	ADCSRA = 	0b10010111;

}

u16 ADC_u16ConvertedValue	(u8 Copy_u8Channel)
{
	ADMUX = ADMUX & 0b11100000;
	ADMUX |= Copy_u8Channel;

	u16 Local_u16Conv = 0;
	// start conversion
	SET_BIT(ADCSRA, 6);

	// polling and wait until the conversion finish
	while(GET_BIT(ADCSRA, 4) == 0);

	// read converted data
	Local_u16Conv = ADCL | (ADCH << 8);

	// clear flag
	SET_BIT(ADCSRA, 4);

	return Local_u16Conv;

}
