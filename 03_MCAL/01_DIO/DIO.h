#ifndef _DIO_H_
#define _DIO_H_

typedef enum{
    DIO_LOW = 0,
    DIO_HIGH
}logic_t;

typedef enum{
	DIO_PORTA = 0,
	DIO_PORTB,
	DIO_PORTC,
	DIO_PORTD
}port_index_t;

typedef enum{
	DIO_PIN0,
	DIO_PIN1,
	DIO_PIN2,
	DIO_PIN3,
	DIO_PIN4,
	DIO_PIN5,
	DIO_PIN6,
	DIO_PIN7
}pin_index_t;

typedef enum{
	DIO_PIN_INPUT = 0,
	DIO_PIN_OUTPUT
}pin_direction_t;

typedef enum{
	DIO_PORT_INPUT = 0x00,
	DIO_PORT_OUTPUT = 0Xff
}port_direction_t;

void DIO_SetPinDirection_Vid(u8_t Copy_u8Port, u8_t Copy_u8Pin , u8_t Copy_u8Direction);
void DIO_SetPinValue_Vid(u8_t Copy_u8Port, u8_t Copy_u8Pin , u8_t Copy_u8Value);
void DIO_TogglePin_Vid(u8_t Copy_u8Port, u8_t Copy_u8Pin);
u8_t DIO_tGetPinValue_u8(u8_t Copy_u8Port, u8_t Copy_u8Pin);


void DIO_SetPortDirection_Vid(u8_t Copy_u8Port, u8_t Copy_u8Direction);
void DIO_SetPortValue_Vid(u8_t Copy_u8Port, u8_t Copy_u8Value);
void DIO_TogglePort_Vid(u8_t Copy_u8Port);
u8_t DIO_tGetPortValue_u8(u8_t Copy_u8Port);


#endif




