/*
 * UART_program.c
 *
 *  Created on: ???/???/????
 *      Author: Mega
 */
#include "../../LIBS/STD_TYPES.h"
#include "../../LIBS/BIT_MATH.h"

#include "UART_config.h"
#include "UART_private.h"
#include "UART_interface.h"

void UART_Init (){
	//char 8 bit
	//no parity
	//one stop bit
	// speed (baud rate  9600 ubrrl
	//full duplex  tx and rx enable
SET_BIT(UCSRB_REG,4);
SET_BIT(UCSRB_REG,3);
CLR_BIT(UCSRB_REG,2);

UCSRC_REG=0b10000110;
UBRRL_REG=51;

}

void UART_SendByte(u8 copy_u8Data ){
	//UDRA  >> 1
	while (GET_BIT(UCSRA_REG,5 )==0);

 UDR_REG= copy_u8Data;
}

u8 UART_Receive (){
	while (GET_BIT(UCSRA_REG,7)==0);
	return UDR_REG;
}
