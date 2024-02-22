/*
 * UART_private.h
 *
 *  Created on: Jul 26, 2023
 *      Author: SHA
 */

#ifndef COTS_MCAL_UART_UART_PRIVATE_H_
#define COTS_MCAL_UART_UART_PRIVATE_H_

/* UCSRA */
#define RXC   7
#define TXC   6
#define UDRE  5
#define FE    4
#define DOR   3
#define PE    2
#define U2X   1
#define MPCM  0

/* UCSRB */
#define RXCIE 7
#define TXCIE 6
#define UDRIE 5
#define RXEN  4
#define TXEN  3
#define UCSZ2 2
#define RXB8  1
#define TXBX  0

/* UCSRC */
#define URSEL 7
#define UMSEL 6
#define UPM1  5
#define UPM0  4
#define USBS  3
#define UCSZ1 2
#define UCSZ0 1
#define UCPOL 0


#define ENABLE  1
#define DISABLE 0

#define EVEN    0
#define ODD     1

#define TWO_BIT  1
#define ONE_BIT  0

#define UART_PORT  DIO_PORTD
#define Tx_PIN     DIO_PIN1
#define Rx_PIN     DIO_PIN0

#define BIT_5  0
#define BIT_6  1
#define BIT_7  2
#define BIT_8  3
#define BIT_9  4

#define ASYNCHRONOUS 1
#define SYNCHRONOUS  0



#endif /* COTS_MCAL_UART_UART_PRIVATE_H_ */
