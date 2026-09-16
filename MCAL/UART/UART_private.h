/*
 * UART_private.h
 *
 *  Created on: ???/???/????
 *      Author: Mega
 */

#ifndef MCAL_UART_UART_PRIVATE_H_
#define MCAL_UART_UART_PRIVATE_H_


#define  UDR_REG *((volatile u8*)0x2C)

#define  UCSRA_REG *((volatile u8*)0x2B)



#define  UCSRB_REG *((volatile u8*)0x2A)


#define  UCSRC_REG *((volatile u8*)0x40)
/*write 0b>>>>>>>  UCSRC NOT( SET AND CLR AND TOG) */
#define  UBRRL_REG *((volatile u8*)0x29)


#endif /* MCAL_UART_UART_PRIVATE_H_ */
