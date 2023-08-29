#include "../../04_LIB/STD_TYP.h"
#include "../../04_LIB/BIT_MATH.h"
#include "DIO.h"
#include <avr/io.h>

void DIO_SetPinDirection_Vid(u8_t Copy_u8Port, u8_t Copy_u8Pin , u8_t Copy_u8Direction)
{
	if(Copy_u8Direction == 1)
	{
		switch(Copy_u8Port)
		{
			case 0:SET_BIT(DDRA, Copy_u8Pin);break;
			case 1:SET_BIT(DDRB, Copy_u8Pin);break;
			case 2:SET_BIT(DDRC, Copy_u8Pin);break;
			case 3:SET_BIT(DDRD, Copy_u8Pin);break;
		}
	}
	else if(Copy_u8Direction == 0)
	{
		switch(Copy_u8Port)
		{
			case 0:CLEAR_BIT(DDRA, Copy_u8Pin);break;
			case 1:CLEAR_BIT(DDRB, Copy_u8Pin);break;
			case 2:CLEAR_BIT(DDRC, Copy_u8Pin);break;
			case 3:CLEAR_BIT(DDRD, Copy_u8Pin);break;
		}
	}
}

void DIO_SetPinValue_Vid(u8_t Copy_u8Port, u8_t Copy_u8Pin , u8_t Copy_u8Value)
{
	if(Copy_u8Value == 1)
	{
		switch(Copy_u8Port)
		{
			case 0:SET_BIT(PORTA, Copy_u8Pin);break;
			case 1:SET_BIT(PORTB, Copy_u8Pin);break;
			case 2:SET_BIT(PORTC, Copy_u8Pin);break;
			case 3:SET_BIT(PORTD, Copy_u8Pin);break;
		}
	}
	else if(Copy_u8Value == 0)
	{
		switch(Copy_u8Port)
		{
			case 0:CLEAR_BIT(PORTA, Copy_u8Pin);break;
			case 1:CLEAR_BIT(PORTB, Copy_u8Pin);break;
			case 2:CLEAR_BIT(PORTC, Copy_u8Pin);break;
			case 3:CLEAR_BIT(PORTD, Copy_u8Pin);break;
		}
	}
}

void DIO_TogglePin_Vid(u8_t Copy_u8Port, u8_t Copy_u8Pin)
{
	switch(Copy_u8Port)
	{
		case 0:TOGGLE_BIT(PORTA, Copy_u8Pin);break;
		case 1:TOGGLE_BIT(PORTB, Copy_u8Pin);break;
		case 2:TOGGLE_BIT(PORTC, Copy_u8Pin);break;
		case 3:TOGGLE_BIT(PORTD, Copy_u8Pin);break;
	}

}

u8_t DIO_GetPinValue_u8(u8_t Copy_u8Port, u8_t Copy_u8Pin)
{
	u8_t Temp_u8RetVal = 0; 
	switch(Copy_u8Port)
	{
		case 0:Temp_u8RetVal = GET_BIT(PINA, Copy_u8Pin);break;
		case 1:Temp_u8RetVal = GET_BIT(PINB, Copy_u8Pin);break;
		case 2:Temp_u8RetVal = GET_BIT(PINC, Copy_u8Pin);break;
		case 3:Temp_u8RetVal = GET_BIT(PIND, Copy_u8Pin);break;
	}
	return (Temp_u8RetVal);
}




void DIO_SetPortDirection_Vid(u8_t Copy_u8Port, u8_t Copy_u8Direction)
{
	switch(Copy_u8Port)
	{
		case 0:DDRA = Copy_u8Direction;break;
		case 1:DDRB = Copy_u8Direction;break;
		case 2:DDRC = Copy_u8Direction;break;
		case 3:DDRD = Copy_u8Direction;break;
	}

}

void DIO_SetPortValue_Vid(u8_t Copy_u8Port, u8_t Copy_u8Value)
{
	switch(Copy_u8Port)
	{
		case 0:PORTA = Copy_u8Value;break;
		case 1:PORTB = Copy_u8Value;break;
		case 2:PORTC = Copy_u8Value;break;
		case 3:PORTD = Copy_u8Value;break;
	}

}

void DIO_TogglePort_Vid(u8_t Copy_u8Port)
{
	switch(Copy_u8Port)
	{
		case 0:PORTA ^= PORTA;break;
		case 1:PORTB ^= PORTB;break;
		case 2:PORTC ^= PORTC;break;
		case 3:PORTD ^= PORTD;break;
	}
}

u8_t DIO_GetPortValue_u8(u8_t Copy_u8Port)
{
	u8_t Temp_u8RetVal = 0; 
	switch(Copy_u8Port)
	{
		case 0:Temp_u8RetVal = PINA;break;
		case 1:Temp_u8RetVal = PINB;break;
		case 2:Temp_u8RetVal = PINC;break;
		case 3:Temp_u8RetVal = PIND;break;
	}
	return (Temp_u8RetVal);
}































