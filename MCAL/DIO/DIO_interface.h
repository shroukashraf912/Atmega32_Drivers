/*
 * DIO_int.h
 *
 *  Created on : Jul 5, 2022
 *  Author	   : Shrouk Ashraf
 *  Layer      : MCAL
 *  SWC        : DIO
 */

#ifndef MCAL_DIO_DIO_INT_H_
#define MCAL_DIO_DIO_INT_H_

/*#####################################################################*/
#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7
/*#####################################################################*/
/* the i/p | o/p that on the PORT*/
#define DIO_PORT_INPUT  0x00
#define DIO_PORT_OUTPUT 0xff

/* the i/p | o/p that on the pin*/
#define DIO_PIN_INPUT  0
#define DIO_PIN_OUTPUT 1
/*#####################################################################*/
/* the i/p | o/p that on the pin high|low*/
#define DIO_HIGH   1
#define DIO_LOW    0
/*#####################################################################*/
void MDIO_vWrtPinDir  (u8 A_u8PortNo , u8 A_u8PinNo ,u8 A_u8PinDir);
void MDIO_vWrtPinVal  (u8 A_u8PortNo , u8 A_u8PinNo ,u8 A_u8PinVal);
void MDIO_vTogPinVal  (u8 A_u8PortNo, u8 A_u8PinNo);
u8   MDIO_u8GetPinVal (u8 A_u8PortNo , u8 A_u8PinNo );

void MDIO_vWrtPortDir(u8 A_u8PortNo, u8 A_u8PortDirs);
void MDIO_vWrtPortVal(u8 A_u8PortNo,u8 A_u8PortVals);
void MDIO_vTogPortVal(u8 A_u8PortNo);

void MDIO_vWrtHighNibbles(u8 A_u8PortNo,u8 A_u8PortVals);
void MDIO_vWrtLowNibbles(u8 A_u8PortNo,u8 A_u8PortVals);

void MDIO_vEnableInternalPullUp(u8 A_u8PortNo, u8 A_u8PinNo ,u8 A_u8ConnectPullup);
/*#####################################################################*/

#endif /* MCAL_DIO_DIO_INT_H_ */
