/*
 * Tx_module.h
 *
 *  Created on: Apr 20, 2021
 *      Author: yahia
 */

#ifndef TX_MODULE_H_
#define TX_MODULE_H_
#include "uart.h"


void init_comm(viod);//inint UART
void send_comm(uint8_t* data ,uint32_t size);
void comm_dispatch(void);



#endif /* TX_MODULE_H_ */
