/*
 * SEG.h
 *
 *  Created on: Aug 13, 2023
 *      Author: abdoe
 */

#ifndef _7SEGMENT_SEG_H_
#define _7SEGMENT_SEG_H_

#define ZERO 0x3f
#define ONE 0x06
#define TWO 0x5B
#define THREE 0x4f
#define FOUR 0x66
#define FIVE 0x6D
#define SIX 0x7D
#define SEVEN 0x07
#define EIGHT 0x7f
#define NINE 0x6f


void SEG_Init(u8_t Copy_u8Port);
void SEG_ShowNum_vid(u8_t Copy_u8Port, u8_t Copy_u8Num);






#endif /* 02_HALL_02_7SEGMENT_SEG_H_ */
