/*
 * LCD.c
 *
 *  Created on: Aug 13, 2023
 *      Author: abdoe
 */

#include "../../04_LIB/STD_TYP.h"
#include "../../04_LIB/BIT_MATH.h"
#include "../../03_MCAL/01_DIO/DIO.h"
#include "LCD.h"
#include <avr/delay.h>



void LCD_SendCmd_Vid(u8_t Copy_u8Cmd)
{
	DIO_SetPinValue_Vid(LCD_CMD_PORT, RS, DIO_LOW);
	DIO_SetPinValue_Vid(LCD_CMD_PORT, RW, DIO_LOW);
	DIO_SetPortValue_Vid(LCD_DATA_PORT, Copy_u8Cmd);
	DIO_SetPinValue_Vid(LCD_CMD_PORT, EN, DIO_HIGH);
	_delay_ms(1);
	DIO_SetPinValue_Vid(LCD_CMD_PORT, EN, DIO_LOW);
}

void LCD_SendChar_Vid(u8_t Copy_u8Char)
{
	DIO_SetPinValue_Vid(LCD_CMD_PORT, RS, DIO_HIGH);
	DIO_SetPinValue_Vid(LCD_CMD_PORT, RW, DIO_LOW);
	DIO_SetPortValue_Vid(LCD_DATA_PORT, Copy_u8Char);
	DIO_SetPinValue_Vid(LCD_CMD_PORT, EN, DIO_HIGH);
	_delay_ms(1);
	DIO_SetPinValue_Vid(LCD_CMD_PORT, EN, DIO_LOW);
}

void LCD_Init_Vid(void)
{
	DIO_SetPortDirection_Vid(LCD_DATA_PORT, DIO_PORT_OUTPUT);
	DIO_SetPinDirection_Vid(LCD_CMD_PORT, RS, DIO_PIN_OUTPUT);
	DIO_SetPinDirection_Vid(LCD_CMD_PORT, RW, DIO_PIN_OUTPUT);
	DIO_SetPinDirection_Vid(LCD_CMD_PORT, EN, DIO_PIN_OUTPUT);
	_delay_ms(35);
	LCD_SendCmd_Vid(LCD_FUN_SET);
	_delay_ms(1);
	LCD_SendCmd_Vid(LCD_ON_OFF);
	_delay_ms(1);
	LCD_SendCmd_Vid(LCD_CLEAR);
	_delay_ms(2);
}

void LCD_SendNumber_Vid(u16_t Copy_u16Num)
{
	u8_t temp_arr[5] = {0,0,0,0,0};
	s8_t ctr = 0;
	while(Copy_u16Num > 9)
	{
		temp_arr[ctr] = Copy_u16Num % 10;
		Copy_u16Num /= 10;
		ctr++;
	}
	temp_arr[ctr] = Copy_u16Num;
	ctr++;
	ctr--;
	for(; ctr >= 0; ctr--)
	{
		LCD_SendChar_Vid(48 + temp_arr[ctr]);
	}
}

void LCD_SendString_Vid(u8_t* Copy_u8Str)
{
	while(*Copy_u8Str != '\0')
	{
		LCD_SendChar_Vid(*Copy_u8Str++);
	}
}

void LCD_SetCursorLocation_Vid(u8_t Copy_u8Line, u8_t Copy_u8Coulmn)
{
	switch(Copy_u8Line){
	case 0:
		LCD_SendCmd_Vid(0x80 + Copy_u8Coulmn);
		break;
	case 1:
		LCD_SendCmd_Vid(0xC0 + Copy_u8Coulmn);
		break;
	}
}

void LCD_SaveSpecialChar_Vid(u8_t* Copy_u8Ptr, u8_t Copy_u8_SaveAddress)
{
	u8_t Copy_u8Ctr = 0;
	LCD_SendCmd_Vid(0x40 + (Copy_u8_SaveAddress * 8));
	for(Copy_u8Ctr = 0;Copy_u8Ctr < 8; Copy_u8Ctr++)
	{
		LCD_SendChar_Vid(*Copy_u8Ptr++);
	}
	LCD_SendCmd_Vid(0x80);
}

void LCD_ClearDisplay_U8(void)
{
	u8_t arr_spaces = "                ";
	LCD_SetCursorLocation_Vid(0, 0);
	LCD_SendString_Vid(arr_spaces);
	LCD_SetCursorLocation_Vid(1, 0);
	LCD_SendString_Vid(arr_spaces);
	LCD_SetCursorLocation_Vid(0, 0);
}












