/*
 * RTOS_program.c
 *
 *  Created on: Nov 21, 2025
 *      Author: yousef.ahmed
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER0_inerface.h"
#include "GI_interface.h"
#include "RTOS_interface.h"
#include "RTOS_config.h"
#include "RTOS_private.h"
#include "TIMER0_private.h"


TCB_t ArrTask[MAX_TASK_NUM];//Index is priority

void RTOS_CreateTask(u8 TaskPrioity, u16 TaskPriodicity, u16 TaskFirstDelay
		,void (*ptrFunc)(void))
{
	ArrTask[TaskPrioity].T_per=TaskPriodicity;
	ArrTask[TaskPrioity].T_ptr=ptrFunc;
}
void RTOS_StartScheduler()
{
	/*static u32 Counter=0;
	Counter++;
	for(u8 i=0;i<MAX_TASK_NUM;i++)
	{
		if((Counter%ArrTask[i].T_per)==0)
		{
			//Invoke task
			ArrTask[i].T_ptr();
		}

	}*/for (u8 i =0; i<MAX_TASK_NUM;i++){
		if(ArrTask[i].T_Fd==0){
			ArrTask[i].T_ptr();
			ArrTask[i].T_Fd=ArrTask[i].T_per-1;

		}else{
			ArrTask[i].T_Fd--;
		}
	}

}
void RTOS_Init()
{

	TIMER0_Init();
	TIMER0_SetCompareValue(125);
	TIMER0_SetCallBackCTC(RTOS_StartScheduler);
	GI_Enable();
}
void RTOS_Pause(void)
{
    CLR_BIT(TIMSK, TIMSK_OCIE0);   // Disable CTC Interrupt -> Pause Scheduler
}

void RTOS_Resume(void)
{
    SET_BIT(TIMSK, TIMSK_OCIE0);   // Enable CTC Interrupt -> Resume Scheduler
}

