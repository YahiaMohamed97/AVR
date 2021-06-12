/*
 * uart.c
 *
 *  Created on: Apr 20, 2021
 *      Author: yahia
 */


#include "uart.h"
#define F_CPU_ 8000000

static uint16_t baud_rate_value;

bool_t uart_init(uint16_t baud_rate,uint8_t parity,uint8_t stop_bits,uint8_t sync,uint8_t Interrupt_Enable)
{
	//write def reg setting
	bool_t b_ret_val = E_TRUE;
	UCSRB = (1 << RXEN) | (1 << TXEN)| (1<<RXCIE)| (0<<TXCIE); // Enable RX and TX pins

	UCSRC |= (3<<UCSZ0); // 8 bits mode
	UCSRA |=(1<<U2X); // double speed active
	UCSRC |=(1<<URSEL); // select reg UCSRC
	UCSRC |=(parity<<UPM0); // select parity
	UCSRC |=(stop_bits<<USBS); // select stop_bits
	if (sync==0)
	{
		baud_rate_value=( (F_CPU_ / (8L * baud_rate) ) -1); //set baud_rate value
		UCSRC |=(1<<URSEL); // select reg UCSRC
		UCSRC &=~(1<<UMSEL);
		UBRRL &=~(1<<URSEL);
		UBRRL = (uint8_t)(baud_rate_value); // set baud_rate
		UBRRH = (uint8_t)(baud_rate_value>>8); // set baud_rate
	}
	else if (sync==1)
	{
		UCSRC |=(1<<URSEL); // select reg UCSRC
		UCSRC |=(1<<UMSEL);
		UCSRC &=~(1<<URSEL); // sync mode
		UBRRL = (uint8_t)(baud_rate_value); // set baud_rate
		UBRRH = (uint8_t)(baud_rate_value>>8); // set baud_rate
	}
	return b_ret_val;
}
bool_t uart_receive_ready()
{
	bool_t b_ret_val = E_TRUE;
		if ((UCSRA & (1<<RXC))>>RXC==1)// if MCU ready to receive new data
		{
			SET_BIT(UCSRA,RXC); // Necessary For Clearing The Flag
		}
		else {
			b_ret_val = E_FALSE;
		}
		return b_ret_val;
}


bool_t uart_write_byte(uint8_t write_byte)
{
	bool_t b_ret_val = E_TRUE;
	if((UCSRA & (1<<UDRE)))// handle it with interrupt to prevent delay
	{
		UDR = write_byte;
	}
	else
	{
		b_ret_val=E_FALSE;
	}
	return b_ret_val;
}


bool_t uart_read_byte(char * read_byte)
{
	bool_t b_ret_val = E_TRUE;
	*read_byte=UDR;
	return b_ret_val;
}

bool_t is_send_complete(void)
{
	bool_t b_ret_val = E_TRUE;
	if ((UCSRA & (1<<TXC))>>TXC==1)
	{
		SET_BIT(UCSRA,TXC); // Necessary For Clearing The Flag
	}
	else {
		b_ret_val = E_FALSE;
	}
	return b_ret_val;
}








