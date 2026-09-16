/*
 * ADC_private.h
 *
 *  Created on: Sep 13, 2025
 *      Author: mohamed.khaled
 */

#ifndef MCAL_ADC_ADC_PRIVATE_H_
#define MCAL_ADC_ADC_PRIVATE_H_

#define ADMUX		*((volatile u8*)0x27)
#define ADCSRA		*((volatile u8*)0x26)
#define ADCL		*((volatile u8*)0x24)
#define ADCH		*((volatile u8*)0x25)
#define SFIOR		*((volatile u8*)0x50)

#endif /* MCAL_ADC_ADC_PRIVATE_H_ */
