/*
 * SSD_interface.h
 *
 *  Created on: Aug 29, 2025
 *      Author: mohamed.khaled
 */

#ifndef HAL_SSD_SSD_INTERFACE_H_
#define HAL_SSD_SSD_INTERFACE_H_

typedef struct
{
	u8 Port;
	u8 CommonState;
}SSD_t;

#define SSD_COMMON_ANODE		1
#define SSD_COMMON_CATHODE		0

#define ZERO	0b00111111
#define ONE		0b00000110
#define TWO		0b01011011
#define THREE	0b01001111
#define FOUR	0b01100110
#define FIVE	0b01101101
#define SIX		0b01111101
#define SEVEN	0b00000111
#define EIGHT	0b01111111
#define NINE	0b01101111


void SSD_voidInit		(SSD_t* Copy_pstructSsd);
void SSD_voidEnable		(SSD_t* Copy_pstructSsd, u8 Copy_u8Number);
void SSD_voidDisable	(SSD_t* Copy_pstructSsd);

#endif /* HAL_SSD_SSD_INTERFACE_H_ */
