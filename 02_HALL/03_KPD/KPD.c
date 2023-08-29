/*
 * KPD.c
 *
 *  Created on: Aug 14, 2023
 *      Author: abdoe
 */

#include "../../04_LIB/STD_TYP.h"
#include "../../04_LIB/BIT_MATH.h"
#include "../../03_MCAL/01_DIO/DIO.h"
#include <avr/io.h>
#include <avr/delay.h>
#include "KPD.h"




u8_t KPD_u8Keys[4][4] = KPD_KEYS;

u8_t KPD_u8RowPins[4] = {KPD_R1_PIN, KPD_R2_PIN, KPD_R3_PIN, KPD_R4_PIN};

u8_t KPD_u8ColPins[4] = {KPD_C1_PIN, KPD_C2_PIN, KPD_C3_PIN, KPD_C4_PIN};



void KPD_Init_Vid(void)
{
	DIO_SetPortDirection_Vid(KPD_PORT, 0x0f);
	DIO_SetPortValue_Vid(KPD_PORT, 0xff);
}

u8_t KPD_PressedKey_U8(void)
{
	u8_t Local_u8CtrR = 0;
	u8_t Local_u8CtrC = 0;
	u8_t Local_u8Pressed = 0;
	u8_t Local_u8_retVal = KPD_CHECK;
	u8_t Local_u8Flag = 0;
	for(Local_u8CtrR = 0; Local_u8CtrR < 4; Local_u8CtrR++)
	{
		DIO_SetPinValue_Vid(KPD_PORT, Local_u8CtrR, DIO_LOW);
		for(Local_u8CtrC = 0;Local_u8CtrC < 4; Local_u8CtrC++)
		{
			Local_u8Pressed = DIO_GetPinValue_u8(KPD_PORT, KPD_u8ColPins[Local_u8CtrC]);
			if(Local_u8Pressed == DIO_LOW)
			{
				_delay_ms(20);
				while(Local_u8Pressed == DIO_LOW)
				{
					Local_u8Pressed = DIO_GetPinValue_u8(KPD_PORT, KPD_u8ColPins[Local_u8CtrC]);
				}
				Local_u8_retVal = KPD_u8Keys[Local_u8CtrR][Local_u8CtrC];
				Local_u8Flag = 1;
				break;
			}
		}
		DIO_SetPinValue_Vid(KPD_PORT,KPD_u8RowPins[Local_u8CtrR],DIO_HIGH);
		if(Local_u8Flag == 1)
		{
			break;
		}
	}
	return (Local_u8_retVal);
}










