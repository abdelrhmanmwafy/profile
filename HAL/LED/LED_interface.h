/*
 * LED_interface.h
 *
 *  Created on: Aug 23, 2025
 *      Author: mohamed.khaled
 */

#ifndef HAL_LED_LED_INTERFACE_H_
#define HAL_LED_LED_INTERFACE_H_


typedef struct
{
	u8 Port;
	u8 Pin;
	u8 State;
}Led_t;

#define LED_ACTIVE_HIGH		1
#define LED_ACTIVE_LOW		0

void LED_voidInit	(Led_t*	Copy_pstructLed);
void LED_voidOn		(Led_t*	Copy_pstructLed);
void LED_voidOff	(Led_t*	Copy_pstructLed);

#endif /* HAL_LED_LED_INTERFACE_H_ */
