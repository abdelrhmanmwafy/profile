/*
 * RTOS_interface.h
 *
 *  Created on: Nov 21, 2025
 *      Author: yousef.ahmed
 */

#ifndef RTOS_INTERFACE_H_
#define RTOS_INTERFACE_H_


void RTOS_CreateTask(u8 TaskPrioity, u16 TaskPriodicity, u16 TaskFirstDelay
		,void (*ptrFunc)(void));
void RTOS_StartScheduler();
void RTOS_Init();
void RTOS_Pause(void);
void RTOS_Resume(void);


#endif /* RTOS_INTERFACE_H_ */
