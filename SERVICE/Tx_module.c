/*
 * Tx_module.c
 *
 *  Created on: Apr 20, 2021
 *      Author: yahia
 */


#include "Tx_module.h"


typedef enum {
IDLE=20,
SENDING_FRAME,
SENDING_BYTE,
FINISH_BYTE,
}enum_comm_state;
static enum_comm_state comm_state;

typedef struct {

    uint8_t * data_location;
    uint8_t * current_location;
    uint8_t data_avilable_flag;
    uint32_t size_data;
    uint32_t current_byte_num;
}str_data_header;
static str_data_header str_data_config;


void init_comm(viod)
{
	uart_init(9600,0,1,0,0);
    comm_state = IDLE;
}


void send_comm(uint8_t* data ,uint32_t size)
{
    if (comm_state==IDLE)
    {
        comm_state = SENDING_FRAME;
        str_data_config.data_location=data;
        str_data_config.current_location=data;
        str_data_config.size_data=size;
        str_data_config.current_byte_num=0;

        str_data_config.data_avilable_flag =1;
    }
	else
	{
		//return ERROR BUSY!
	}
}
void comm_dispatch(void)
{

    switch (comm_state)
    {
		case IDLE:

			break;


		case SENDING_FRAME:
			if (str_data_config.current_location != NULL && str_data_config.current_byte_num < str_data_config.size_data)
			{
				//send_uart_byte; *(str_data_config.data_location+str_data_config.current_byte_num)
				uart_write_byte(*(str_data_config.current_location));
				str_data_config.current_location++;
				comm_state=SENDING_BYTE;
				str_data_config.current_byte_num++;
			}
			else
			{
				if (str_data_config.current_byte_num >= str_data_config.size_data)
				{
					comm_state=IDLE;
//					str_data_config.data_avilable_flag =0;
//					str_data_config.data_location=NULL;
//					str_data_config.current_location=NULL;
//					str_data_config.size_data=0;
//					str_data_config.current_byte_num=0;
				}
				else
				{
					//ERROR Accessing NULL
				}
			}
			break;


		case SENDING_BYTE:
		if (is_send_complete()== E_TRUE)
		{
			comm_state=SENDING_FRAME;

		}
		else
		{
			//Stay
		}
		break;

		default:
			break;
    }
}
