/*
 * DIO_AVR.h
 *
 *  Created on: Dec 13, 2020
 *      Author: Yahia_Ashour
 */

#ifndef DIO_AVR_H_
#define DIO_AVR_H_
#include "STD_TYPES.h"
#include "DIO_CFG.h"

#define PINA_R (*((volatile uint8_t *)0x39))
#define DDRA_R (*((volatile uint8_t *)0x3A))
#define PORTA_R (*((volatile uint8_t *)0x3B))

#define PINB_R (*((volatile uint8_t *)0x36))
#define DDRB_R (*((volatile uint8_t *)0x37))
#define PORTB_R (*((volatile uint8_t *)0x38))


#define PINC_R (*((volatile uint8_t *)0x33))
#define DDRC_R (*((volatile uint8_t *)0x34))
#define PORTC_R (*((volatile uint8_t *)0x35))

#define PIND_R (*((volatile uint8_t *)0x30))
#define DDRD_R (*((volatile uint8_t *)0x31))
#define PORTD_R (*((volatile uint8_t *)0x32))


#define PORTA_ADRESS	0x3B
#define PORTB_ADRESS	0x38
#define PORTC_ADRESS	0x35
#define PORTD_ADRESS	0x32

#define PINA_ADRESS	0x39
#define PINB_ADRESS	0x36
#define PINC_ADRESS	0x33
#define PIND_ADRESS	0x30

#define DDRA_ADRESS	0x3A
#define DDRB_ADRESS	0x37
#define DDRC_ADRESS	0x34
#define DDRD_ADRESS	0x31



typedef enum{
	PORT_A=1,
	PORT_B,
	PORT_C,
	PORT_D
}enum_PORT;



void DIO_Init(void);

void DIO_Write_Channel(enum_pin_name pinID,uint8_t pin);
uint8_t DIO_Read_Channel(enum_pin_name pinID);

void DIO_Write_port(enum_PORT port,uint8_t value);
uint8_t DIO_Read_port(enum_PORT port);




#endif /* DIO_AVR_H_ */
