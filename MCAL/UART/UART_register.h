/*
 * UART_register.h
 *
 *  Created on: Jul 26, 2023
 *      Author: SHA
 */

#ifndef COTS_MCAL_UART_UART_REGISTER_H_
#define COTS_MCAL_UART_UART_REGISTER_H_


#define UDR    *((volatile u8*) 0x2C)
#define UCSRA  *((volatile u8*) 0x2B)
#define UCSRB  *((volatile u8*) 0x2A)
#define UCSRC  *((volatile u8*) 0x40)
#define UBRRH  *((volatile u8*) 0x40)
#define UBRRL  *((volatile u8*) 0x29)

#endif /* COTS_MCAL_UART_UART_REGISTER_H_ */
