#include "ADC_AVR.h"








void adc_init_channel(str_adc_channel_config *channel_cfg)
{    
	ADCSRA_R |= (1<<7);               // Enable ADC module
	adc_arr[numberOfChannels].adc_referance = channel_cfg->adc_referance;
	adc_arr[numberOfChannels].adj=channel_cfg->adj;
	adc_arr[numberOfChannels].pre_scaler= channel_cfg->pre_scaler;
	numberOfChannels++;
}




void adc_config_channel(tenum_channel channel)
{
	ADMUX_R |= ((adc_arr[channel].adc_referance<<6)  | ((channel<<0)|(ADMUX_R&0xF0)) | (adc_arr[channel].adj<<5) );
	ADMUX_R &= ((channel<<0)|(ADMUX_R&0xF0)) ;
	ADCSRA_R &=((adc_arr[channel].pre_scaler<<0)| (ADCSRA_R & 0b11111100) );
}

void adc_start_conversion(tenum_channel channel)
{
	adc_config_channel(channel);
	ADCSRA_R |= (1<<6); // Start Conversion.
}

void read_analog(tenum_channel pin)
{
	adc_start_conversion(pin);
}




//tenum_adc_state
void adc_read(void){

	tenum_adc_state ret_state=status;
	static uint8_t count=0;	
	uint32_t dataLow,dataHigh,output; // To return The value.

	switch (status)
	{
	case FREE:
		if (count<=numberOfChannels)
		{
			read_analog(count);
			status = BUSY;
		}
		else
		{
			ret_state = UBDEFINED_ERROR;
		}

		break;


	case BUSY:
		if ((ADCSRA_R&(1<<ADIF_BIT))!=0)
		{
			dataLow = (uint32_t)ADCL_R;
			dataHigh = (uint32_t)ADCH_R;
			output=(dataHigh*256)+dataLow;
			arr_data_read[count]=output;
			status=FREE;
			count++;
			if (count > numberOfChannels) {count=0;}
		}
		break;

	default:
		break;
	}


//	return ret_state;
}

