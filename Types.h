/*
 * Types.h
 *
 *  Created on: Mar 12, 2017
 *      Author: ahmed
 */

#ifndef TYPES_H_
#define TYPES_H_
// Data Types
typedef unsigned char u_int8 ;
typedef unsigned short int u_int16 ;
typedef unsigned long int u_int32 ;
typedef signed char s_int8 ;
typedef signed short int s_int16 ;
typedef signed long int s_int32 ;
typedef float f32 ;
typedef double d64 ;
// Pointers
typedef unsigned char *  ptr_uint8 ;
typedef unsigned short int *  ptr_uint16 ;
typedef unsigned long int *  ptr_uint32 ;
typedef signed char *  ptr_sint8 ;
typedef signed short int *  ptr_sint16 ;
typedef signed long int * ptr_sint32 ;
typedef float *  ptr_f32 ;
typedef double *  ptr_d46 ;
typedef  void (*ptr_fn) (void)   ;
//		((ptr_fn) 0x002 ) = LCD_Init ;

#endif /* TYPES_H_ */
