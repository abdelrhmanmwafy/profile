/*
 * UART_interface.h
 *
 *  Created on: ???/???/????
 *      Author: Mega
 */

#ifndef MCAL_UART_UART_INTERFACE_H_
#define MCAL_UART_UART_INTERFACE_H_

void UART_Init ();

void UART_SendByte (u8 copy_u8Data);
u8 UART_Receive ();



#endif /* MCAL_UART_UART_INTERFACE_H_ */
