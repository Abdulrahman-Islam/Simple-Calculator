/*
 * KPD.h
 *
 *  Created on: Aug 14, 2023
 *      Author: abdoe
 */

#ifndef _03_KPD_KPD_H_
#define _03_KPD_KPD_H_

#define KPD_PORT	DIO_PORTA

#define KPD_R1_PIN	DIO_PIN0
#define KPD_R2_PIN	DIO_PIN1
#define KPD_R3_PIN	DIO_PIN2
#define KPD_R4_PIN	DIO_PIN3

#define KPD_C1_PIN	DIO_PIN4
#define KPD_C2_PIN	DIO_PIN5
#define KPD_C3_PIN	DIO_PIN6
#define KPD_C4_PIN	DIO_PIN7


#define KPD_KEYS   {{'7', '8', '9', '/'},\
					{'4', '5', '6', '*'},\
					{'1', '2', '3', '-'},\
					{'N', '0', '=', '+'}}


#define KPD_CHECK 0xff





void KPD_Init_Vid(void);
u8_t KPD_PressedKey_U8(void);


#endif /* _03_KPD_KPD_H_ */
