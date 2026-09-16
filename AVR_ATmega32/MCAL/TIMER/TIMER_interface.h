/*
 * TIMER_interface.h
 *
 *  Created on: Sep 20, 2025
 *      Author: mohamed.khaled
 */

#ifndef MCAL_TIMER_TIMER_INTERFACE_H_
#define MCAL_TIMER_TIMER_INTERFACE_H_


void TIMER_voidInitT0 (void);
void TIMER_voidPreloadValT0 (u8 Copy_u8Preloadvalue);
void TIMER_voidSetComperMatchValT0 (u8 Copy_u8ComperMatchVal );



#define TIMER_T0_OVF  0
#define TIMER_T0_CTC  1  //COMPER
void TIMER_voidSetFullBack(u8 Copy_u8TimerMode,void (*pf) (void) );



/*****************************/
/************TIMER_1**********/

void TIMER_voidInitT1(void);
/*OCR1A_OCRB*  OUTPUT COMPARE REGISTER*/
void TIMER_voidsetComparMatchT1ChannalA (u16 Copy_u8CompareMatchValue );
void TIMER_voidsetComparMatchT1ChannalB (u16 Copy_u8CompareMatchValue );
/*ICRA_ICRB* INPUT CAPTURE REGISTER */
void TIMER_voidsetInputCaptureValue (u16 Copy_u8ISRValue );

#endif /* MCAL_TIMER_TIMER_INTERFACE_H_ */
