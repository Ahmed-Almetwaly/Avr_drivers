/*
 * DIO.h
 *
 *  Created on: Mar 20, 2017
 *      Author: ahmed
 */
// Gards
#ifndef DIO_H_
#define DIO_H_

#include "Types.h"

//------------------------------------------------------------

void DIO_PinDirection( u_int8 pin_no,u_int8 direction ) ;
void DIO_PortDirection( u_int8 port_no, u_int8 pins_no,u_int8 direction ) ;
void DIO_SetPin( u_int8 pin_no,u_int8 state ) ;
void DIO_SetPort(u_int8 port_no, u_int8 pins_no,u_int8 state) ;
void DIO_PinMode( u_int8 pin_no,u_int8 mode ) ;
void DIO_PortMode(u_int8 port_no, u_int8 pins_no,u_int8 mode) ;
u_int8 DIO_GetPin( u_int8 pin_no ) ;
u_int8 DIO_GetPort(u_int8 port_no, u_int8 pins_no) ;
void DIO_AssPort(u_int8 port_no,u_int8 value) ;

#endif /* DIO_H_ */
