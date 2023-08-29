#include <avr/io.h>
#include <avr/delay.h>
#include "../04_LIB/STD_TYP.h"
#include "../04_LIB/BIT_MATH.h"
#include "../03_MCAL/01_DIO/DIO.h"
#include "../02_HALL/01_LCD/LCD.h"
#include "../02_HALL/03_KPD/KPD.h"



void main(void)
{
	u8_t retKey = KPD_CHECK;
	u8_t num1 = 0;
	u8_t num2 = 0;
	u8_t oper = 0;
	u8_t flag = 0;
	LCD_Init_Vid();
	KPD_Init_Vid();
	while(1)
	{
		num1 = 0;
		num2 = 0;
		oper = 0;



		while(1)//take number1 from user
		{
			flag = 1;
			retKey = KPD_PressedKey_U8();
			if(retKey != KPD_CHECK)
			{
				switch(retKey)
				{
				case 'N':
					LCD_ClearDisplay_U8();
					break;
				case '+':
				case '-':
				case '*':
				case '/':
					LCD_SendChar_Vid(retKey);
					oper = retKey;
					flag = 0;
					break;
				case '=':
					break;
				default:
					LCD_SendChar_Vid(retKey);
					num1 = (num1 * 10) + (retKey-48);
					//num1 = (retKey - 48);
					flag = 1;
					break;
				}
			}
			if(flag == 0)
			{
				break;
			}
		}



//		while(1)//take operation from user
//		{
//			flag = 0;
//			retKey = KPD_PressedKey_U8();
//			if(retKey != KPD_CHECK)
//			{
//				switch(retKey)
//				{
//				case 'N':
//					LCD_ClearDisplay_U8();
//					break;
//				case '+':
//				case '-':
//				case '*':
//				case '/':
//					LCD_SendChar_Vid(retKey);
//					oper = retKey;
//					flag = 1;
//					break;
//				default:
//					break;
//				}
//			}
//
//			if((flag == 1) || (retKey == 'N'))
//			{
//				break;
//			}
//		}
//		if(retKey == 'N')
//		{
//			continue;
//		}



		while(1)//take number2 from user
		{
			flag = 1;
			retKey = KPD_PressedKey_U8();
			if(retKey != KPD_CHECK)
			{
				switch(retKey)
				{
				case 'N':
					LCD_ClearDisplay_U8();
					flag = 0;
					break;
				case '+':
				case '-':
				case '*':
				case '/':
					break;
				case '=':
					flag = 0;
					break;
				default:
					LCD_SendChar_Vid(retKey);
					num2 = (num2 * 10) + (retKey-48);
//					num2 = (retKey - 48);
					flag = 1;
					break;
				}
			}
			if(flag == 0)
			{
				break;
			}
		}

		if((flag == 0) && (retKey == '='))
		{
			LCD_SendChar_Vid('=');
			switch(oper)
			{
			case '+':
				LCD_SendNumber_Vid((num1 + num2));
				break;
			case '-':
				LCD_SendNumber_Vid((num1 - num2));
				break;
			case '*':
				LCD_SendNumber_Vid((num1 * num2));
				break;
			case '/':
				LCD_SendNumber_Vid((num1 / num2));
				break;
			}
		}
	}
}
