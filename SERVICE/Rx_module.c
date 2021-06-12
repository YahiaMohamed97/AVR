/*
 ============================================================================
 Name        : comm_rx.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "STD_TYPES.h"
#include "Rx_module.h"

#define HEADER_SIZE 3

typedef enum{
	IDLE =0,
	REC_DATA,
	REC_HEADER,
	REC_COMP,
}COMM_RX_STATE;

COMM_RX_STATE COMM_RX_STATE_g = IDLE;

static uint8_t lock_flag = 0;
static volatile uint16_t buffer_counter = 0;
static volatile uint8_t rec_flag = 0;
static uint8_t buffer[BUF_MAX_SIZE];


bool_t comm_cb()
{

	bool_t RET_VAL = E_TRUE;
	if ((lock_flag == 0) && (buffer_counter < BUF_MAX_SIZE))
	{

		//save the reg in buffer
		buffer[buffer_counter]= UDR ;
		buffer_counter++;
		rec_flag = 1;
	}
	else
	{
		RET_VAL = E_FALSE;
	}
	return RET_VAL;
}



bool_t dispatch(void)
{

	bool_t RET_VAL = E_TRUE;


		switch (COMM_RX_STATE_g)
		{
		case IDLE :
//			uart_write_byte(buffer_counter+'0');
			if (buffer_counter <= HEADER_SIZE)
			{
				COMM_RX_STATE_g = REC_HEADER;
			}
			else
			{
				/*TODO check header */
				COMM_RX_STATE_g = REC_DATA;
			}
			break;
		case REC_HEADER :
//			uart_write_byte(buffer_counter+'0');
			if (buffer_counter > HEADER_SIZE)
			{
				/*TODO check header*/

				COMM_RX_STATE_g = REC_DATA;
			}
			break;

		case REC_DATA :
			if (buffer_counter >= buffer[1]+'0' )  //concatenate frame size
			{
				COMM_RX_STATE_g = REC_COMP;
				lock_flag = 1;
			}
			break;
		default :
			//COMM_RX_STATE_g = IDLE;
			break;
		}

//		rec_flag = 0;
	return RET_VAL;
}

bool_t release ()
{
	bool_t RET_VAL = E_TRUE;
	if (lock_flag)
	{
		COMM_RX_STATE_g = IDLE;
		buffer_counter = 0;
		lock_flag = 0;
	}
	else
	{
		RET_VAL=E_FALSE;
	}
	return RET_VAL;
}

ISR(USART_RXC_vect)
{


	if ((lock_flag == 0) && (buffer_counter < BUF_MAX_SIZE) )
	{
		//save the reg in buffer
		buffer[buffer_counter]= UDR ;
		rec_flag = 1;
		uart_write_byte(buffer[buffer_counter]);
		buffer_counter++;
	}


}
