/*
 * Rx_module.h
 *
 *  Created on: Apr 22, 2021
 *      Author: yahia
 */

#ifndef RX_MODULE_H_
#define RX_MODULE_H_
#include "uart.h"
#include "Tx_module.h"

#define BUF_MAX_SIZE 100

void rx_init(uint8_t **ptr2arr);
bool_t release (void);
bool_t dispatch(void);

//void init_comm(viod);//inint UART
// TODO: check if uart is already initialized
//void comm_rx(uint8_t* data ,uint32_t size);
//void rx_dispatch(void);



#endif /* RX_MODULE_H_ */
