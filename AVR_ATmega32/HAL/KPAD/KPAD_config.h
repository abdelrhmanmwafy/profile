/*
 * KPAD_config.h
 *
 *  Created on: Sep 5, 2025
 *      Author: mohamed.khaled
 */

#ifndef HAL_KPAD_KPAD_CONFIG_H_
#define HAL_KPAD_KPAD_CONFIG_H_


u8 KPAD_Au8Values[4][4] = {
		{'7','8','9', '/'},
		{'4', '5', '6', 'x'},
		{'1','2','3', '-'},
		{'C','0','=', '+'}
};


/*
 * options:
 * 1. DIO_PORTA
 * 2. DIO_PORTB
 * 3. DIO_PORTC
 * 4. DIO_PORTD
 * */
#define KPAD_PORT		DIO_PORTA

#define KPAD_ROW_INIT	DIO_PIN0
#define KPAD_ROW_END	DIO_PIN3

#define KPAD_COL_INIT	DIO_PIN4
#define KPAD_COL_END	DIO_PIN7


#define KPAD_R0		DIO_PIN0
#define KPAD_R1		DIO_PIN1
#define KPAD_R2		DIO_PIN2
#define KPAD_R3		DIO_PIN3

#define KPAD_C0		DIO_PIN4
#define KPAD_C1		DIO_PIN5
#define KPAD_C2		DIO_PIN6
#define KPAD_C3		DIO_PIN7

#endif /* HAL_KPAD_KPAD_CONFIG_H_ */
