/*
 * DIO_CFG.h
 *
 *  Created on: Dec 13, 2020
 *      Author: Yahia_Ashour
 */

#ifndef DIO_CFG_H_
#define DIO_CFG_H_


#define LAST_PIN 32
typedef enum {
	OUTPUT,
	INPUT_PULL_UP,
	INPUT_FLOATING
}enum_pin_mode;


typedef enum{
	PINA0,
	PINA1,
	PINA2,
	PINA3,
	PINA4,
	PINA5,
	PINA6,
	PINA7,
	PINB0,
	PINB1,
	PINB2,
	PINB3,
	PINB4,
	PINB5,
	PINB6,
	PINB7,
	PINC0,
	PINC1,
	PINC2,
	PINC3,
	PINC4,
	PINC5,
	PINC6,
	PINC7,
	PIND0,
	PIND1,
	PIND2,
	PIND3,
	PIND4,
	PIND5,
	PIND6,
	PIND7
}enum_pin_name;



#endif /* DIO_CFG_H_ */
