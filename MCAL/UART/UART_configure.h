/*
 * UART_configure.h
 *
 *  Created on: Jul 26, 2023
 *      Author: SHA
 */

#ifndef COTS_MCAL_UART_UART_CONFIGURE_H_
#define COTS_MCAL_UART_UART_CONFIGURE_H_

/* Baud Rate Register */
#define Oscillator_Frequecncy 8000000 //Hz
#define Baud_Rate 9600
#define UBRR_Baud_Rate 51

/*Parity */
/*
 * Choice:
 * ENABLE
 * DISABLE
 * */
#define PARITY_CHECk DISABLE

/*
 * Choice:
 * EVEN
 * ODD
 * */
#define PARITY_MODE EVEN

/*Stop bit*/
/*
 * Choice:
 * TWO_BIT
 * ONE_BIT
 * */
#define STOP_BIT  ONE_BIT


/*Data Size:
 * 0 - BIT_5
 * 1 - BIT_6
 * 2 - BIT_7
 * 3-  BIT_8
 * 4 - BIT_9
 */
#define DATA_SIZE  BIT_8

/*
 * MODE_SELECT:
 * 	ASYNCHRONOUS
 * 	SYNCHRONOUS
 */
#define MODE_SELECT ASYNCHRONOUS

#define RXC_INTERRUPT ENABLE
#define TXC_INTERRUPT DISABLE

#endif /* COTS_MCAL_UART_UART_CONFIGURE_H_ */
