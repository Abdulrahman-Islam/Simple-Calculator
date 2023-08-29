/*
 * SEG.c
 *
 *  Created on: Aug 13, 2023//init
 *      Author: abdoe
 */
#include "../../04_LIB/STD_TYP.h"
#include "../../04_LIB/BIT_MATH.h"
#include "SEG.h"
#include "../../03_MCAL/01_DIO/DIO.h"
#include <avr/io.h>

u8_t arr_seg[10] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};


void SEG_ShowNum_vid(u8_t Copy_u8Port, u8_t Copy_u8Num)
{
	DIO_SetPortValue_Vid(Copy_u8Port, arr_seg[Copy_u8Num]);
}

void SEG_Init(u8_t Copy_u8Port)
{
	DIO_SetPortDirection_Vid(Copy_u8Port, DIO_PORT_OUTPUT);
}









