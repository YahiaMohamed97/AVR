#ifndef _ADC_AVR_H
#define _ADC_AVR_H

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "STD_TYPES.h"



/* ========================================================================== */
/*                          	 Macros                                       */
/* ========================================================================== */

/* ****** REGISTERS FOR ADC ****** */
#define ADCL_R *(volatile uint8_t*)0x24
#define ADCH_R *(volatile uint8_t*)0x25
#define ADCSRA_R *(volatile uint8_t*)0x26
#define ADMUX_R *(volatile uint8_t*)0x27
#define SPIOR_R *(volatile uint8_t*)0x50
#define ADIF_BIT 4

#define NUM_OF_CHANNELS 3



unsigned short arr_data_read[8];
uint8_t numberOfChannels;

 /* ========================================================================== */
 /*                         Structures and Enums                               */
 /* ========================================================================== */


typedef enum{
	FREE =1,
	BUSY,
	UBDEFINED_ERROR,
}tenum_adc_state;

 tenum_adc_state status;


typedef enum{
    AREF_ADC=0,   // Enernal Vreff turned off
    AVCC_ADC=1,   // Vcc with external cap at AREF pin
    INTERNAL_REF=3, // internal 2.65V with external cap at AREF pin
}tenum_vref_adc;



typedef enum {
    ADC0=0,
    ADC1,
    ADC2,
    ADC3,
    ADC4,
    ADC5,
    ADC6,
    ADC7,
}tenum_channel ;

/*typedef enum{
    SINGLE_MODE,
    FREE_RUNNING_MODE,
}tenum_adc_mode;
*/


typedef enum {
    PRESCALER_DIV_2=0,
    PRESCALER_DIV_4=2,
    PRESCALER_DIV_8=3,
    PRESCALER_DIV_16=4,
    PRESCALER_DIV_32=5,
    PRESCALER_DIV_64=6,
    PRESCALER_DIV_128=7,
} tenum_adc_pre_scaler;

typedef enum{
    RIGHT_ADJ=0,
    LIFT_ADJ=1,
}tenum_adc_adjustment;

typedef struct adc_nodeP{
    tenum_channel pin;
    tenum_adc_pre_scaler pre_scaler;
    tenum_vref_adc adc_referance;
    tenum_adc_adjustment adj;

}str_adc_channel_config;

/* ========================================================================== */
/*                           				                                  */
/* ========================================================================== */


/*
* Array of str_adc_channel_config
* each element contains the configuration of one channel
*/
str_adc_channel_config adc_arr[8];

/* ========================================================================== */
/*                           Functions                                        */
/* ========================================================================== */

void adc_init_interrupt(void);

void adc_init_channel(str_adc_channel_config * );

void adc_start_conversion(tenum_channel);

void read_analog(tenum_channel pin);

//tenum_adc_state
void adc_read(void);


#endif
