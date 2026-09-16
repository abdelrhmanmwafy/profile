/*
 * GIE_interface.h
 *
 *  Created on: Sep 13, 2025
 *      Author: mohamed.khaled
 */

#ifndef MCAL_GIE_GIE_INTERFACE_H_
#define MCAL_GIE_GIE_INTERFACE_H_

/*GIE*/
#define SREG		*((volatile u8*)0x5F)

void GIE_voidEnable		(void);
void GIE_voidDisable	(void);


#endif /* MCAL_GIE_GIE_INTERFACE_H_ */
