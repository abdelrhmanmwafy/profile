
#include "../../LIBS/STD_TYPES.h"
#include "../../LIBS/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "SSD_interface.h"

u8 SSD_Au8Numbers[10] = {ZERO, ONE, TWO , THREE , FOUR, FIVE, SIX, SEVEN, EIGHT, NINE };

void SSD_voidInit		(SSD_t* Copy_pstructSsd)
{
	/*set the port to be output*/
	DIO_voidSetPortDirection(Copy_pstructSsd->Port, DIO_OUTPUT);

	/*disable SSD */
	switch(Copy_pstructSsd->CommonState)
	{
	case SSD_COMMON_ANODE:
		DIO_voidSetPortValue(Copy_pstructSsd->Port, 0xff);
		break;
	case SSD_COMMON_CATHODE:
		DIO_voidSetPortValue(Copy_pstructSsd->Port, 0x00);
		break;
	default :
		break;
	}
}

void SSD_voidEnable		(SSD_t* Copy_pstructSsd, u8 Copy_u8Number)
{
	switch(Copy_pstructSsd->CommonState)
		{
		case SSD_COMMON_ANODE:
			DIO_voidSetPortValue(Copy_pstructSsd->Port, ~SSD_Au8Numbers[Copy_u8Number]);
			break;
		case SSD_COMMON_CATHODE:
			DIO_voidSetPortValue(Copy_pstructSsd->Port, SSD_Au8Numbers[Copy_u8Number]);
			break;
		default :
			break;
		}
}
void SSD_voidDisable	(SSD_t* Copy_pstructSsd)
{
	switch(Copy_pstructSsd->CommonState)
		{
		case SSD_COMMON_ANODE:
			DIO_voidSetPortValue(Copy_pstructSsd->Port, 0xff);
			break;
		case SSD_COMMON_CATHODE:
			DIO_voidSetPortValue(Copy_pstructSsd->Port, 0x00);
			break;
		default :
			break;
		}
}
