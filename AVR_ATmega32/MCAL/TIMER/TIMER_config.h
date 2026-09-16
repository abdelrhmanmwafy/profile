/*
 * TIMER_config.h
 *
 *  Created on: Sep 20, 2025
 *      Author: mohamed.khaled
 */

#ifndef MCAL_TIMER_TIMER_CONFIG_H_
#define MCAL_TIMER_TIMER_CONFIG_H_


#define TIMER_T0_OVF		 	 0
#define TIMER_T0_CTC			 1
#define TIMER_T0_FAST_PWM        2
#define TIMER_T0_FASE_CORRECT    3
#define TIMER_T0_MODE		TIMER_T0_FAST_PWM



#define TIMER_ENABLED  	1
#define TIMER_DISABLED 	0

#define TIMER_T0_OVF_INT 	 TIMER_DISABLED
#define TIMER_T0_CTC_INT  	 TIMER_DISABLED

#endif /* MCAL_TIMER_TIMER_CONFIG_H_ */
