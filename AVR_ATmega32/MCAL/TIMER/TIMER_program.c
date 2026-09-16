/*
 * TIMER_program.c
 *
 *  Created on: Sep 20, 2025
 *      Author: mohamed.khaled
 */

#include "../../LIBS/STD_TYPES.h"
#include "../../LIBS/BIT_MATH.h"

#include "TIMER_interface.h"
#include "TIMER_private.h"
#include "TIMER_config.h"


void (*pf_NotificationOVFT0) (void) = NULL ;
void (*pf_NotificationCTCT0) (void) = NULL ;

/*TCCR0 REG_ MODE AND INT*/
void TIMER_voidInitT0 (void)
{
#if TIMER_T0_MODE == TIMER_T0_OVF
	CLR_BIT(TCCR0_REG,6);
	CLR_BIT(TCCR0_REG,3);
#elif TIMER_T0_MODE == TIMER_T0_CTC
	CLR_BIT(TCCR0_REG,6);
	SET_BIT(TCCR0_REG,3);

#elif TIMER_T0_MODE ==	TIMER_T0_FAST_PWM
	SET_BIT(TCCR0_REG,6);
	SET_BIT(TCCR0_REG,3);

#elif TIMER_T0_MODE ==	TIMER_T0_PHASE_CORRECT
	SET_BIT(TCCR0_REG,6);
	CLR_BIT(TCCR0_REG,3);
#endif

#if TIMER_T0_OVF_INT ==TIMER_ENABLED
	SET_BIT(TIMSK_REG,0);

#elif TIMER_T0_CTC_INT == TIMER_ENABLED
	SET_BIT(TIMSK_REG,1);
#endif

/*TOG OC0 COmpare MAtch */
SET_BIT(TCCR0_REG,5);
CLR_BIT(TCCR0_REG,4);
	/*Enable prescaler reg TCCR0*/
	CLR_BIT(TCCR0_REG,0);
	SET_BIT(TCCR0_REG,1);
	CLR_BIT(TCCR0_REG,2);
}
/*TCNT0 REG*/
void TIMER_voidPreloadValT0 (u8 Copy_u8Preloadvalue)
{
TCNT0_REG= Copy_u8Preloadvalue;
}
/*OCR0_REG COMPARE */
void TIMER_voidSetComperMatchValT0 (u8 Copy_u8ComperMatchVal )
{
OCR0_REG =Copy_u8ComperMatchVal;
}


void TIMER_voidSetFullBack(u8 Copy_u8TimerMode,void (*pf) (void) )
{
	switch (Copy_u8TimerMode)
	{
	case TIMER_T0_OVF :
		if(pf != NULL )
		{
			pf_NotificationOVFT0 = pf;
		}
		break;
	case TIMER_T0_CTC :
		if(pf != NULL )
				{
					pf_NotificationCTCT0 = pf;
				}
		break;

	}


}
/*void (*pf) (void) say timer0  get call on ISR   use global pointer to fun  */
/*ISR ENA ................OVFT0.............*/
/*ISR ENA ................OVFT0.............*/
void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
    if (pf_NotificationOVFT0 != NULL )
    {
        pf_NotificationOVFT0();
    }
}

/*.................CTCT0.................*/
void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
    if (pf_NotificationCTCT0 != NULL )
    {
        pf_NotificationCTCT0();
    }
}
/**************************************/
/*________________________TIMER1_________________*/
void TIMER_voidInitT1(void)
{
	//channal A NONinverting FAST_PWM
	SET_BIT(TCCR1A_REG,7);
	CLR_BIT(TCCR1A_REG,6);
	/*wave genertaion FAST PWM MODE 14*/
	CLR_BIT(TCCR1A_REG, 0);
	SET_BIT(TCCR1A_REG,1);
	SET_BIT(TCCR1B_REG,3);
	SET_BIT(TCCR1B_REG,4);

	/*prescaler 8*/
	CLR_BIT(TCCR1B_REG,0);
	SET_BIT(TCCR1B_REG,1);
	CLR_BIT(TCCR1B_REG,2);

}
void TIMER_voidsetComparMatchT1ChannalA (u16 Copy_u8CompareMatchValue )
{
OCR1A_REG=Copy_u8CompareMatchValue;
}
void TIMER_voidsetComparMatchT1ChannalB (u16 Copy_u8CompareMatchValue )
{
	OCR1B_REG=Copy_u8CompareMatchValue;
}
void TIMER_voidsetInputCaptureValue (u16 Copy_u8ISRValue )
{
	ICR1_REG = Copy_u8ISRValue;
}


