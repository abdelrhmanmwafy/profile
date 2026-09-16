/*
 * RTOS_private.h
 *
 *  Created on: Nov 21, 2025
 *      Author: yousef.ahmed
 */

#ifndef RTOS_PRIVATE_H_
#define RTOS_PRIVATE_H_

typedef struct
{
	u16 T_per;
	u16  T_Fd;
	void(*T_ptr)(void);
}TCB_t;


#endif /* RTOS_PRIVATE_H_ */
