/*
 * TIMER_private.h
 *
 *  Created on: Sep 5, 2022
 *      Author: SHA
 */

#ifndef COTS_MCAL_TIMER_TIMER_PRIVATE_H_
#define COTS_MCAL_TIMER_TIMER_PRIVATE_H_

/*************************** Timer 0 ***************************/
#define TCCR0  *((volatile u8*)(0x53))
#define TCNT0  *((volatile u8*)(0x52))
#define OCR0   *((volatile u8*)(0x5C))
#define TIMSK  *((volatile u8*)(0x59))
#define TIFR   *((volatile u8*)(0x58))
#define SFIOR  *((volatile u8*)(0x50))

//Bits of TCCR0
#define CS00  	0
#define CS01	1
#define CS02	2
#define WGM01	3
#define COM00 	4
#define COM01 	5
#define WGM00 	6
#define FOC0	7

//bits of TIMSK
#define TOIE0	0
#define OCIE0	1

//bits of TIFR
#define TOV0	0
#define OCF0	1

//bit of SFIOR
#define PSR10	0
/*******************************************************************/

/*************************** Timer-1 Reg ***************************/

/*******************************************************************/

/*************************** Timer-2 Reg ***************************/

/*******************************************************************/

#endif /* COTS_MCAL_TIMER_TIMER_PRIVATE_H_ */
