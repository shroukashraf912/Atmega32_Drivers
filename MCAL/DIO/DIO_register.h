/*
 * DIO_register.h
 *
 *  Created on : Aug 14, 2022
 *  Author	   : SHA
 *  Layer      : MCAL
 *  SWC        : DIO
 */

#ifndef COTS_MCAL_DIO_DIO_REGISTER_H_
#define COTS_MCAL_DIO_DIO_REGISTER_H_

#define PORTA   *((volatile u8*) 0x3b)
#define PORTB   *((volatile u8*) 0x38)
#define PORTC   *((volatile u8*) 0x35)
#define PORTD   *((volatile u8*) 0x32)

#define DDRA    *((volatile u8*) 0x3a)
#define DDRB	*((volatile u8*) 0x37)
#define DDRC	*((volatile u8*) 0x34)
#define DDRD    *((volatile u8*) 0x31)

#define PINA    *((volatile u8*) 0x39)
#define PINB    *((volatile u8*) 0x36)
#define PINC    *((volatile u8*) 0x33)
#define PIND    *((volatile u8*) 0x30)

#define SFIOR   *((volatile u8*) 0x50)







#endif /* COTS_MCAL_DIO_DIO_REGISTER_H_ */
