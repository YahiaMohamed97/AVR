/*
 * DIO_AVR.c
 *
 *  Created on: Dec 13, 2020
 *      Author: Yahia_Ashour
 */

#include "STD_TYPES.h"
#include "DIO_CFG.h"
#include "DIO_AVR.h"

extern uint8_t arr_pins_cfg[LAST_PIN];


/*             ***************        DIO_Init      ****************
 * INPUT :
 * 		No Input Parameters
 * OUTPUT:
 * 		No Output Parameters
 * Description:
 * 		This Function Initialize all pins to be Output,Input_Pull_Up OR Input_FLOATING USING array in {{{{DIO_CFG.c}}}} File
 * */

void DIO_Init(void){
	uint8_t counter=0;
	uint8_t Actial_Port;
	uint8_t Actial_Pin ;
	uint8_t* arr_reg[8]={DDRA_ADRESS,DDRB_ADRESS,DDRC_ADRESS,DDRD_ADRESS,
						 PORTA_ADRESS,PORTB_ADRESS,PORTC_ADRESS,PORTD_ADRESS};

	for (counter=0;counter<LAST_PIN;counter++)
	{
		Actial_Port = counter/8;
		Actial_Pin = counter%8;
		switch (arr_pins_cfg[counter]) {
			case OUTPUT:
				SET_BIT((*((volatile uint8_t *)(*(arr_reg+Actial_Port)))),Actial_Pin);
				break;
			case INPUT_FLOATING:
				CLEAR_BIT((*((volatile uint8_t *)(*(arr_reg+Actial_Port)))),Actial_Pin);
				CLEAR_BIT((*((volatile uint8_t *)(*(arr_reg+Actial_Port+4)))),Actial_Pin);

				break;
			case INPUT_PULL_UP:
				CLEAR_BIT((*((volatile uint8_t *)(*(arr_reg+Actial_Port)))),Actial_Pin);
				SET_BIT((*((volatile uint8_t *)(*(arr_reg+Actial_Port+4)))),Actial_Pin);

				break;
			default:
				/* Here Should Be Some Code For Error Handling since the user choose wrong one ! */
				break;
		}
	}
}

/*             ***************        DIO_Write_Channel       ****************
 * INPUT :
 * 		pinID: value specifies the pin number required to write to it Range Form 0 to 31 which represent 32 AVILABLE PINS
 * 		Value : either 1 or 0 value to output
 * OUTPUT:
 * 		No Output
 * Description:
 * 		This Function writes the value (0 OR 1) to the specific channel determined by the input parameter pinID
 * */

void DIO_Write_Channel(enum_pin_name pinID,uint8_t value)
{
	if (pinID>=0 && pinID <32)
	{
		uint8_t Actial_Port = pinID/8;
		uint8_t Actial_Pin = pinID%8;
		uint8_t *arr_reg[4]={(uint8_t*)PORTA_ADRESS,(uint8_t*)PORTB_ADRESS,(uint8_t*)PORTC_ADRESS,(uint8_t*)PORTD_ADRESS};

		if (value==1)
			{
				SET_BIT((*((volatile uint8_t *)(*(arr_reg+Actial_Port)))),Actial_Pin);
			}
		else if (value ==0)
			{
				CLEAR_BIT((*((volatile uint8_t *)(*(arr_reg+Actial_Port)))),Actial_Pin);
			}
		else
			{
				/*WRONG CHOISE FOR VALUE INPUT!!!!!!*/
			}
	}
	else
	{
			/*NUM of pin out of range1!!!*/
	}
}
	/*             ***************        DIO_Read_Channel       ****************
	 * INPUT :
	 * 		pinID: value specifies the pin number required to read, it Range Form 0 to 31 which represent 32 AVILABLE PINS
	 * OUTPUT:
	 * 		Ret_val: specifies the value in the required channel
	 * Description:
	 * 		This Function Reads the input to the specific channel determined by the input parameter pinID
	 * */
uint8_t DIO_Read_Channel(enum_pin_name pinID)
{
	uint8_t Ret_val;
	if (pinID>=0 && pinID<32)
	{
		uint8_t Actial_Port = pinID/8;
		uint8_t Actial_Pin = pinID%8;
		uint8_t *arr_reg[4]={(uint8_t*)PINA_ADRESS,(uint8_t*)PINB_ADRESS,(uint8_t*)PINC_ADRESS,(uint8_t*)PIND_ADRESS};
		Ret_val = GET_BIT((*((volatile uint8_t *)(*(arr_reg+Actial_Port)))),Actial_Pin);
	}
	else
	{
		/* Code to handle the situation when the caller send wrong pinID */
	}
		return Ret_val;
}


/*
 * INPUT :
 * 		port : port name from ENUM called enum_port
 * 		value : number in range 0-255 to be assigned to the port reg
 * OUTPUT:
 * 		NO output
 * Description:
 * 		This Function Sets the 8 bit register specified by "port" to the VALUE passed by the caller
 * */
void DIO_Write_port(enum_PORT port,uint8_t value)
{
	switch (port) {
			case PORT_A:
				PORTA_R=value;
				break;

			case PORT_B:
				PORTB_R=value;
				break;

			case PORT_C:
				PORTC_R=value;
				break;

			case PORT_D:
				PORTD_R=value;
				break;
			default:
				/*error handling*/
				break;
		}

}




/*
 * INPUT :
 * 		port : port name from ENUM called 'enum_port'
 *OUTPUT:
 * 		ret_val : 8 bit value
 * Description:
 * 		This Function Returns the 8 bit value readed from "PIN" register specified form the INPUT parameter port to this function
 * */
uint8_t DIO_Read_port(enum_PORT port)
{
	uint8_t ret_val;
	switch (port) {
			case PORT_A:
				ret_val=PINA_R;
				break;

			case PORT_B:
				ret_val=PINB_R;
				break;

			case PORT_C:
				ret_val=PINC_R;
				break;

			case PORT_D:
				ret_val=PIND_R;
				break;
			default:
				/*error handling*/
				break;
		}
return	ret_val;
}




