/*
 * Timer0.h
 *
 *  Created on: Mar 31, 2021
 *      Author: yahia
 */

#ifndef TIMER0_H_
#define TIMER0_H_


/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <avr/io.h>
#include <avr/interrupt.h>





/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
#define F_CPU 8000000
#define TIMER0_MAX_VALUE 0xFF
#define FOC0 7
#define WGM00 6
#define WGM01 3


/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

typedef enum{
	NO_CLK_SOURCE = 0,
	NO_PRESCALER,
	PRESCALER_8,
	PRESCALER_64,
	PRESCALER_256,
	PRESCALER_1024,
	EXTERNAL_FALING_EDGE,
	EXTERNAL_RISING_EDGE
}enum_timer_clk_src;

typedef enum{
	TIMER_INTERRUPT_ON,
	TIMER_INTERRUPT_OFF
}enum_timer_interrupt_mode;

typedef enum{
	NORMAL_MODE = 0,
	PWM_PHASE_CORRECT_MODE = (1<<WGM00)|(0<<WGM01),
	CTC_MODE = ((0 << WGM00 )|(1 << WGM01 )),
	FAST_PWM_MODE = (1<<WGM00)|(1<<WGM01)
}enum_timer_mode;


typedef enum{
	OVERFLOW_INTERRUPT_ENABLE = 0,
	CTC_INTERRUBT_ENABLE
}enum_timer_interrupt_mask;

typedef struct{
	enum_timer_mode Timer_mode;
	enum_timer_clk_src clk_src;
	enum_timer_interrupt_mode intrruptMode;
	enum_timer_interrupt_mask interruptMask;

}str_timer_cfg;



void Timer0Init(void);
void Timer0Update(str_timer_cfg * Update);
void writeTimr0(uint8_t val) ;
void readTimr0(uint8_t* val) ;
void Timr0_delay_ms(uint16_t delay) ;
void Timr0_delay_us(uint16_t delay) ;
void writeTimr0CTC(uint8_t val);
void Timer0DeInit(void) ;


#endif /* TIMER0_H_ */
