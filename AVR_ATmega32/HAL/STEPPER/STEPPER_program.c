
#define F_CPU	8000000UL
#include "../../LIBS/STD_TYPES.h"
#include "../../LIBS/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_Interface.h"

#include "STEPPER_interface.h"
#include "STEPPER_config.h"
#include "STEPPER_private.h"
#include <util/delay.h>

void STEPPER_voidInit( void ){
	DIO_voidSetPinDirection(STEPPER_PORT , STEPPER_BLUE_PIN , DIO_OUTPUT);
	DIO_voidSetPinDirection(STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_OUTPUT);
	DIO_voidSetPinDirection(STEPPER_PORT , STEPPER_PINK_PIN , DIO_OUTPUT);
	DIO_voidSetPinDirection(STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_OUTPUT);

	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_LOW );
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_LOW );
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PINK_PIN   , DIO_LOW );
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_LOW );

}
void STEPPER_voidOn ( u8 Copy_u8StepType , u8 Copy_u8Direction , u8 Copy_u8Speed , u16 Copy_u16Degree ){
u32 LOC_u8Iterator = 0 ;

if(Copy_u8StepType == STEPPER_FULL_STEP){
	if(Copy_u8Direction == STEPPER_CLOCK_WISE){

		for(LOC_u8Iterator = 0 ; LOC_u8Iterator < (( Copy_u16Degree * 256 ) / 45 ) / 4 ; LOC_u8Iterator++){
				DIO_voidSetPinValue(STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_LOW );
				DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PINK_PIN   , DIO_LOW );
				DIO_voidSetPinValue(STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_LOW );
				DIO_voidSetPinValue(STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_HIGH );
				_delay_ms( Copy_u8Speed );
				DIO_voidSetPinValue(STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_LOW );
				DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PINK_PIN   , DIO_LOW );
				DIO_voidSetPinValue(STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_HIGH );
				DIO_voidSetPinValue(STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_LOW );
				_delay_ms( Copy_u8Speed );
				DIO_voidSetPinValue(STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_LOW );
				DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PINK_PIN   , DIO_HIGH );
				DIO_voidSetPinValue(STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_LOW );
				DIO_voidSetPinValue(STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_LOW );
				_delay_ms( Copy_u8Speed );
				DIO_voidSetPinValue(STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_HIGH );
				DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PINK_PIN   , DIO_LOW );
				DIO_voidSetPinValue(STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_LOW );
				DIO_voidSetPinValue(STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_LOW );
				_delay_ms( Copy_u8Speed );
			}

	}
	else if(Copy_u8Direction == STEPPER_COUNTER_CLOCK_WISE){
		for(LOC_u8Iterator = 0 ; LOC_u8Iterator < (( Copy_u16Degree * 256 ) / 45 ) / 4 ; LOC_u8Iterator++){

					DIO_voidSetPinValue(STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_HIGH );
					DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PINK_PIN   , DIO_LOW );
					DIO_voidSetPinValue(STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_LOW );
					DIO_voidSetPinValue(STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_LOW );
					_delay_ms( Copy_u8Speed );

					DIO_voidSetPinValue(STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_LOW );
					DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PINK_PIN   , DIO_HIGH );
					DIO_voidSetPinValue(STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_LOW );
					DIO_voidSetPinValue(STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_LOW );
					_delay_ms( Copy_u8Speed );

					DIO_voidSetPinValue(STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_LOW );
					DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PINK_PIN   , DIO_LOW );
					DIO_voidSetPinValue(STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_HIGH );
					DIO_voidSetPinValue(STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_LOW );
					_delay_ms( Copy_u8Speed );

					DIO_voidSetPinValue(STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_LOW );
					DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PINK_PIN   , DIO_LOW );
					DIO_voidSetPinValue(STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_LOW );
					DIO_voidSetPinValue(STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_HIGH );
					_delay_ms( Copy_u8Speed );


				}
		}
}
else if(Copy_u8StepType == STEPPER_HALF_STEP){
	if(Copy_u8Direction == STEPPER_CLOCK_WISE){
		for(LOC_u8Iterator = 0 ; LOC_u8Iterator < ( ( (Copy_u16Degree *512) /45 ) / 8 ) ; LOC_u8Iterator++){
			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_LOW );
			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PINK_PIN   , DIO_LOW );
			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_LOW );
			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_HIGH );
			_delay_ms( Copy_u8Speed );

			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_LOW );
			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PINK_PIN   , DIO_LOW );
			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_HIGH );
			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_HIGH );
			_delay_ms( Copy_u8Speed );
			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_LOW );
			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PINK_PIN   , DIO_LOW );
			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_HIGH );
			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_LOW );
			_delay_ms( Copy_u8Speed );

			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_LOW );
			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PINK_PIN   , DIO_HIGH );
			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_HIGH );
			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_LOW );
			_delay_ms( Copy_u8Speed );

			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_LOW );
			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PINK_PIN   , DIO_HIGH );
			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_LOW );
			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_LOW );
			_delay_ms( Copy_u8Speed );
			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_HIGH );
			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PINK_PIN   , DIO_HIGH );
			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_LOW );
			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_LOW );
			_delay_ms( Copy_u8Speed );
			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_HIGH );
			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PINK_PIN   , DIO_LOW );
			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_LOW );
			DIO_voidSetPinValue(STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_LOW );
			_delay_ms( Copy_u8Speed );
		}

	}
	else if(Copy_u8Direction == STEPPER_COUNTER_CLOCK_WISE){
		for(LOC_u8Iterator = 0 ; LOC_u8Iterator < ( ( (Copy_u16Degree *512) /45 ) / 8 ) ; LOC_u8Iterator++){

		DIO_voidSetPinValue(STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_HIGH );
		DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PINK_PIN   , DIO_LOW );
		DIO_voidSetPinValue(STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_LOW );
		DIO_voidSetPinValue(STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_LOW );
		_delay_ms( Copy_u8Speed );

		DIO_voidSetPinValue(STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_HIGH );
		DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PINK_PIN   , DIO_HIGH );
		DIO_voidSetPinValue(STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_LOW );
		DIO_voidSetPinValue(STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_LOW );
		_delay_ms( Copy_u8Speed );
		DIO_voidSetPinValue(STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_LOW );
		DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PINK_PIN   , DIO_HIGH );
		DIO_voidSetPinValue(STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_LOW );
		DIO_voidSetPinValue(STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_LOW );
		_delay_ms( Copy_u8Speed );

		DIO_voidSetPinValue(STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_LOW );
		DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PINK_PIN   , DIO_HIGH );
		DIO_voidSetPinValue(STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_HIGH );
		DIO_voidSetPinValue(STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_LOW );
		_delay_ms( Copy_u8Speed );

		DIO_voidSetPinValue(STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_LOW );
		DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PINK_PIN   , DIO_LOW );
		DIO_voidSetPinValue(STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_HIGH );
		DIO_voidSetPinValue(STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_LOW );
		_delay_ms( Copy_u8Speed );
		DIO_voidSetPinValue(STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_LOW );
		DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PINK_PIN   , DIO_LOW );
		DIO_voidSetPinValue(STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_HIGH );
		DIO_voidSetPinValue(STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_HIGH );
		_delay_ms( Copy_u8Speed );
		DIO_voidSetPinValue(STEPPER_PORT , STEPPER_BLUE_PIN   , DIO_LOW );
		DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PINK_PIN   , DIO_LOW );
		DIO_voidSetPinValue(STEPPER_PORT , STEPPER_ORANGE_PIN , DIO_LOW );
		DIO_voidSetPinValue(STEPPER_PORT , STEPPER_YELLOW_PIN , DIO_HIGH );
		_delay_ms( Copy_u8Speed );
	}}
}




}
void STEPPER_voidOff( void ){
	DIO_voidSetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_LOW);
	DIO_voidSetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_LOW);
	DIO_voidSetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, DIO_LOW);
	DIO_voidSetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_LOW);


}
