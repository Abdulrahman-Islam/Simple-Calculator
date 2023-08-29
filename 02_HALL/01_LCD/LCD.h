/*
 * LCD.h
 *
 *  Created on: Aug 13, 2023
 *      Author: abdoe
 */

#ifndef HALL_LCD_H_
#define HALL_LCD_H_

#define LCD_DATA_PORT DIO_PORTC
#define LCD_CMD_PORT  DIO_PORTD

#define RS DIO_PIN2
#define RW DIO_PIN1
#define EN DIO_PIN0

#define LCD_FUN_SET	0b00111000
#define LCD_ON_OFF 	0b00001111
#define LCD_CLEAR  	0b00000001

void LCD_SendCmd_Vid(u8_t Copy_u8Cmd);
void LCD_SendChar_Vid(u8_t Copy_u8Char);
void LCD_SendNumber_Vid(u16_t Copy_u16Num);
void LCD_Init_Vid(void);
void LCD_SendString_Vid(u8_t* Copy_u8Str);
void LCD_SetCursorLocation_Vid(u8_t Copy_u8Line, u8_t Copy_u8Coulmn);
void LCD_SaveSpecialChar_Vid(u8_t* Copy_u8Ptr, u8_t Copy_u8_SaveAddress);
void LCD_ClearDisplay_U8(void);

#endif /* 02_HALL_LCD_H_ */
