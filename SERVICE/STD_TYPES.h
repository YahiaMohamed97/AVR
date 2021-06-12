/*
 * STD_TYPES.h
 *
 *  Created on: Dec 13, 2020
 *      Author: yahia
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

#define SET_BIT(reg,index) ((reg)|=(1<<(index)))
#define CLEAR_BIT(reg,index) ((reg)&=~(1<<(index)))
#define TOGGLE_BIT(reg,index) ((reg)^=(1<<(index)))
#define SHIFT_R(reg,index) ((reg)=((reg)>>(index)))
#define SHIFT_L(reg,index) ((reg)=((reg)<<(index)))
#define ROL(reg,index) ((reg)= ((((reg)<<(index))|((reg)>>(8-index)))))
#define ROR(reg,index) ((reg)= ((((reg)>>(index))|((reg)<<(8-index)))))
#define BIT_IS_SET(reg,index) ((reg)&(1<<index))?1:0
#define BIT_IS_CLEAR(reg,index) ((reg)&(1<<index))?0:1
#define GET_BIT(reg,index) ((reg)&(1<<index))

#define NULL ((void *)0)

typedef unsigned long long uint64_t;
typedef long long sint64_t;
typedef unsigned long uint32_t;
typedef long sint32_t;
//typedef unsigned short uint16_t;
typedef short sint16_t;
typedef unsigned char uint8_t;
typedef char sint8_t;
typedef float float32_t;
typedef double float64_t;
typedef enum{
	E_FALSE =0,
	E_TRUE,
}tenum_bool;
typedef tenum_bool bool_t;




#endif /* STD_TYPES_H_ */
