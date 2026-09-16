/*
 * KPAD_interface.h
 *
 *  Created on: Sep 5, 2025
 *      Author: mohamed.khaled
 */

#ifndef HAL_KPAD_KPAD_INTERFACE_H_
#define HAL_KPAD_KPAD_INTERFACE_H_


#define KPAD_NOT_PRESSED	0xff

void KPAD_voidInit	(void);

u8 KPAD_u8GetPressed	(void);

#endif /* HAL_KPAD_KPAD_INTERFACE_H_ */
