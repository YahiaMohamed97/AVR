/*
 * uart.h
 *
 *  Created on: Apr 20, 2021
 *      Author: yahia
 */

#ifndef UART_H_
#define UART_H_
#include "STD_TYPES.h"
#include <avr/io.h>
#include <avr/interrupt.h>

typedef enum
{
	NONE,
	EVEN=2,
	ODD,
}parity_sel;

typedef enum
{
	ONE_BIT,
	TWO_BITS,
}stop_bits_sel;

bool_t uart_init(uint16_t baud_rate,uint8_t parity,uint8_t stop_bits,uint8_t sync,uint8_t Interrupt_Enable);
bool_t uart_receive_ready(void); // return 1 if ready to receive new data
bool_t uart_write_byte(uint8_t write_byte);
bool_t uart_read_byte(char * read_byte);
bool_t is_send_complete(void);
#endif /* UART_H_ */
