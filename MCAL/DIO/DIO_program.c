/*
 * DIO_program.c
 *
 *  Created on : Jul 5, 2022
 *  Author	   : Shrouk Ashraf
 *  Layer      : MCAL
 *  SWC        : Digital Input Output (DIO)
 */
/*##################################################################################################################*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "DIO_register.h"
#include "DIO_private.h"
#include "DIO_config.h"
#include "DIO_interface.h"
/*##################################################################################################################*/
/*
 ****************************************************************************************
 * Function_Name ==>   MDIO_vWrtPinDir(u8 A_u8PortNo , u8 A_u8PinNo ,u8 A_u8PinDir)
 * Description   ==>   This Function set the direction of the Pin  (INPUT || OUTPUT)
 *  Arguments    ==>   =>A_u8PortNo --> Port Name [ DIO_PORTA ,	DIO_PORTB , DIO_PORTC , DIO_PORTD ]
 *				   	   =>A_u8PinNo  --> Pin Number [ DIO_PIN0 , DIO_PIN1 , DIO_PIN2 , DIO_PIN3 , DIO_PIN4 , DIO_PIN5 , DIO_PIN6 , DIO_PIN7 ]
 *					   =>A_u8PinDir --> Pin Direction [ DIO_PIN_OUTPUT , DIO_PIN_INPUT ]
 *  Return       ==>   void
 ****************************************************************************************
*/
void MDIO_vWrtPinDir  (u8 A_u8PortNo , u8 A_u8PinNo ,u8 A_u8PinDir)
{
	switch (A_u8PortNo)
	{
		case DIO_PORTA:  WRT_BIT(DDRA, A_u8PinNo, A_u8PinDir); break;
		case DIO_PORTB:  WRT_BIT(DDRB, A_u8PinNo, A_u8PinDir); break;
		case DIO_PORTC:  WRT_BIT(DDRC, A_u8PinNo, A_u8PinDir); break;
		case DIO_PORTD:  WRT_BIT(DDRD, A_u8PinNo, A_u8PinDir); break;
		default:    /* EEROR */     break;
	}
}
/*##################################################################################################################*/
/*
 ****************************************************************************************
 * Function_Name ==>   MDIO_vWrtPinVal(u8 A_u8PortNo , u8 A_u8PinNo ,u8 A_u8PinVal)
 * Description   ==>   This Function set the Value of the Pin  (HIGH || LOW)
 *  Arguments    ==>   =>A_u8PortNo --> Port Name [ DIO_PORTA ,	DIO_PORTB , DIO_PORTC , DIO_PORTD ]
 *				   	   =>A_u8PinNo  --> Pin Number [ DIO_PIN0 , DIO_PIN1 , DIO_PIN2 , DIO_PIN3 , DIO_PIN4 , DIO_PIN5 , DIO_PIN6 , DIO_PIN7 ]
 *					   =>A_u8PinVal --> Pin Direction [ DIO_PIN_HIGH , DIO_PIN_LOW ]
 *  Return       ==>   void
 ****************************************************************************************
*/
void MDIO_vWrtPinVal  (u8 A_u8PortNo , u8 A_u8PinNo ,u8 A_u8PinVal)
{
	switch (A_u8PortNo)
	{
		case DIO_PORTA:  WRT_BIT(PORTA, A_u8PinNo, A_u8PinVal); break;
		case DIO_PORTB:  WRT_BIT(PORTB, A_u8PinNo, A_u8PinVal); break;
		case DIO_PORTC:  WRT_BIT(PORTC, A_u8PinNo, A_u8PinVal); break;
		case DIO_PORTD:  WRT_BIT(PORTD, A_u8PinNo, A_u8PinVal); break;
		default:    /* EEROR */     break;
	}
}
/*##################################################################################################################*/
/*
 ****************************************************************************************
 * Function_Name ==>   MDIO_vTogPinVal(u8 A_u8PortNo, u8 A_u8PinNo)
 * Description   ==>   This Function Toggle the Value of the Pin.
 *  Arguments    ==>   =>A_u8PortNo --> Port Name [ DIO_PORTA ,	DIO_PORTB , DIO_PORTC , DIO_PORTD ]
 *				   	   =>A_u8PinNo  --> Pin Number [ DIO_PIN0 , DIO_PIN1 , DIO_PIN2 , DIO_PIN3 , DIO_PIN4 , DIO_PIN5 , DIO_PIN6 , DIO_PIN7 ]
 *  Return       ==>   void
 ****************************************************************************************
*/
void MDIO_vTogPinVal(u8 A_u8PortNo, u8 A_u8PinNo)
{
	switch (A_u8PortNo)
	{
		case DIO_PORTA : TOG_BIT(PORTA ,A_u8PinNo );break;
		case DIO_PORTB : TOG_BIT(PORTB ,A_u8PinNo );break;
		case DIO_PORTC : TOG_BIT(PORTC ,A_u8PinNo );break;
		case DIO_PORTD : TOG_BIT(PORTD ,A_u8PinNo );break;
		default:    /* EEROR */     break;
	}
}
/*##################################################################################################################*/
/*
 ****************************************************************************************
 * Function_Name ==>   MDIO_u8GetPinVal(u8 A_u8PortNo, u8 A_u8PinNo)
 * Description   ==>   This Function Get the Value of the Pin.
 *  Arguments    ==>   =>A_u8PortNo --> Port Name [ DIO_PORTA ,	DIO_PORTB , DIO_PORTC , DIO_PORTD ]
 *				   	   =>A_u8PinNo  --> Pin Number [ DIO_PIN0 , DIO_PIN1 , DIO_PIN2 , DIO_PIN3 , DIO_PIN4 , DIO_PIN5 , DIO_PIN6 , DIO_PIN7 ]
 *  Return       ==>   u8
 ****************************************************************************************
*/
u8   MDIO_u8GetPinVal (u8 A_u8PortNo , u8 A_u8PinNo )
{
	u8 L_u8PinValue;
	switch (A_u8PortNo)
	{
		 case DIO_PORTA: L_u8PinValue = GET_BIT(PINA, A_u8PinNo); break;
		 case DIO_PORTB: L_u8PinValue = GET_BIT(PINB, A_u8PinNo); break;
		 case DIO_PORTC: L_u8PinValue = GET_BIT(PINC, A_u8PinNo); break;
		 case DIO_PORTD: L_u8PinValue = GET_BIT(PIND, A_u8PinNo); break;
		 default:    /* EEROR??? */     break;
	}
	return L_u8PinValue;
}
/*##################################################################################################################*/
/*
 ****************************************************************************************
 * Function_Name ==>   MDIO_vWrtPortDir(u8 A_u8PortNo, u8 A_u8PortDirs)
 * Description   ==>   This Function Set the direction of the port (INPUT / OUTPUT)
 * Arguments     ==>   =>A_u8PortNo  --> Port Name [ DIO_PORTA ,	DIO_PORTB , DIO_PORTC , DIO_PORTD ]
 *				   	   =>A_u8PortDirs--> Port direction [ DIO_PORT_OUTPUT , DIO_PORT_INPUT ]
 * Return       ==>    void
 ****************************************************************************************
*/
void MDIO_vWrtPortDir(u8 A_u8PortNo, u8 A_u8PortDirs)
{
	switch (A_u8PortNo)
	{
		case DIO_PORTA: DDRA = A_u8PortDirs;break;
		case DIO_PORTB: DDRB = A_u8PortDirs;break;
		case DIO_PORTC: DDRC = A_u8PortDirs;break;
		case DIO_PORTD: DDRD = A_u8PortDirs;break;
		default:    /* EEROR??? */     break;
	}
}
/*##################################################################################################################*/
/*
 ****************************************************************************************
 * Function_Name ==>   MDIO_vWrtPortVal(u8 A_u8PortNo,u8 A_u8PortVals)
 * Description   ==>   This Function Set value on Port.
 * Arguments     ==>   =>A_u8PortNo  --> Port Name [ DIO_PORTA ,	DIO_PORTB , DIO_PORTC , DIO_PORTD ]
 *				   	   =>A_u8PortVals--> The Value  [DIO_PORT_HIGH , DIO_PORT_LOW , Another Value]
 * Return       ==>    void
 ****************************************************************************************
*/
void MDIO_vWrtPortVal(u8 A_u8PortNo,u8 A_u8PortVals)
{
	switch (A_u8PortNo)
	{
		case DIO_PORTA: PORTA = A_u8PortVals;break;
		case DIO_PORTB: PORTB = A_u8PortVals;break;
		case DIO_PORTC: PORTC = A_u8PortVals;break;
		case DIO_PORTD: PORTD = A_u8PortVals;break;
		default:    /* EEROR??? */     break;
	}
}
/*##################################################################################################################*/
/*
 ****************************************************************************************
 * Function_Name ==>   MDIO_vTogPortVal(u8 A_u8PortNo)
 * Description   ==>   This Function Toggle the Value of the Port.
 *  Arguments    ==>   A_u8PortNo --> Port Name [ DIO_PORTA ,	DIO_PORTB , DIO_PORTC , DIO_PORTD ]
 *  Return       ==>   void
 ****************************************************************************************
*/
void MDIO_vTogPortVal(u8 A_u8PortNo)
{
	switch (A_u8PortNo)
	{
		case DIO_PORTA : PORTA = ~PORTA ;break ;
		case DIO_PORTB : PORTB = ~PORTB ;break ;
		case DIO_PORTC : PORTC = ~PORTC ;break ;
		case DIO_PORTD : PORTD = ~PORTD ;break ;
	}
}
/*##################################################################################################################*/
/*
 ****************************************************************************************
 * Function_Name ==>   MDIO_vWrtHighNibbles(u8 A_u8PortNo,u8 A_u8PortVals)
 * Description   ==>   This Function write value on high nibbles of the Port.
 * Arguments     ==>   =>A_u8PortNo   --> Port Name [ DIO_PORTA , DIO_PORTB , DIO_PORTC , DIO_PORTD ]
 *                     =>A_u8PortVals --> to set its high bits on high nibble oh register
 * Return       ==>    void
 * Hint1 : High Nibbles = Most Pins [4:7]
 * Hint2 : This Function take the first 4 bits from the value (#) => xxxx#### AND put it in high nobbles
 ****************************************************************************************
*/
void MDIO_vWrtHighNibbles(u8 A_u8PortNo,u8 A_u8PortVals)
{
	A_u8PortVals <<= 4;
	switch (A_u8PortNo)
	{
		case DIO_PORTA:
			PORTA &= 0x0f;         // make sure the high bits = 0000
			PORTA |= A_u8PortVals; //Set only the high nibble of the port A by the given value
			break;
		case DIO_PORTB:
			PORTB &= 0x0f;         //Set only the high nibble of the port B by the given value
			PORTB |= A_u8PortVals;
			break;
		case DIO_PORTC:
			PORTC &= 0x0f;         //Set only the high nibble of the port C by the given value
			PORTC |= A_u8PortVals;
			break;
		case DIO_PORTD:
			PORTD &= 0x0f;         //Set only the high nibble of the port D by the given value
			PORTD |= A_u8PortVals;
			break;
		default:    /* EEROR??? */     break;
	}
}
/*##################################################################################################################*/
/*
 ****************************************************************************************
 * Function_Name ==>   MDIO_vWrtLowNibbles(u8 A_u8PortNo,u8 A_u8PortVals)
 * Description   ==>   This Function write value on high nibbles of the Port.
 * Arguments     ==>   =>A_u8PortNo   --> Port Name [ DIO_PORTA , DIO_PORTB , DIO_PORTC , DIO_PORTD ]
 *                     =>A_u8PortVals --> to set its low bits on low nibble oh register
 * Return       ==>    void
 * Hint1 : Low Nibbles = least Pins [0:3]
 * Hint2 : This Function take the first 4 bits from the value (#) => xxxx#### AND put it in low nobbles
 ****************************************************************************************
*/
void MDIO_vWrtLowNibbles(u8 A_u8PortNo,u8 A_u8PortVals)
{
	A_u8PortVals &= 0x0f;
	switch (A_u8PortNo)
	{
		case DIO_PORTA:
			PORTA &= 0xf0; //Set only the high nibble of the port A by the given value
			PORTA |= A_u8PortVals;
			break;
		case DIO_PORTB:
			PORTB &= 0xf0;  //Set only the high nibble of the port B by the given value
			PORTB |= A_u8PortVals;
			break;
		case DIO_PORTC:
			PORTC &= 0xf0;  //Set only the high nibble of the port C by the given value
			PORTC |= A_u8PortVals;
			break;
		case DIO_PORTD:
			PORTD &= 0xf0;   //Set only the high nibble of the port D by the given value
			PORTD |= A_u8PortVals;
			break;
		default:    /* EEROR??? */     break;
	}
}
/*##################################################################################################################*/
/*
 ****************************************************************************************
 * Function_Name ==>   MDIO_vEnableInternalPullUp(u8 A_u8PortNo, u8 A_u8PinNo ,u8 A_u8ConnectPullup)
 * Description   ==>   This Function connected internal pull up
 * Arguments     ==>   =>A_u8PortNo --> Port Name [ DIO_PORTA ,	DIO_PORTB , DIO_PORTC , DIO_PORTD ]
					   =>A_u8PinNo  --> Pin Number [ DIO_PIN0 , DIO_PIN1 , DIO_PIN2 , DIO_PIN3 , DIO_PIN4 , DIO_PIN5 , DIO_PIN6 , DIO_PIN7 ]
					   =>A_u8ConnectPullup --> [DIO_PIN_HIGH , DIO_PIN_LOW ]
 * Return       ==>    void
 ****************************************************************************************
*/
void MDIO_vEnableInternalPullUp(u8 A_u8PortNo, u8 A_u8PinNo ,u8 A_u8ConnectPullup)
{
	switch(A_u8PortNo)
	{
	  /* Connect or disconnect the pull up resistance to the given pin in port A */
	  case DIO_PORTA:
		  if (A_u8ConnectPullup == DIO_HIGH)
		  {
			  CLR_BIT(SFIOR,PUD);
			  CLR_BIT(DDRA,A_u8PinNo);
			  SET_BIT(PORTA,A_u8PinNo);
		  }
		  else
		  {
			  CLR_BIT(PORTA,A_u8PinNo);
		  }
		  break;
	  /* Connect or disconnect the pull up resistance to the given pin in port B */
	  case DIO_PORTB:
		  if (A_u8ConnectPullup == DIO_HIGH)
		  {
			  CLR_BIT(SFIOR,PUD);
			  CLR_BIT(DDRB,A_u8PinNo);
			  SET_BIT(PORTB,A_u8PinNo);
		  }
		  else
		  {
			  CLR_BIT(PORTB,A_u8PinNo);
		  }
		  break;
	  /* Connect or disconnect the pull up resistance to the given pin in port C */
	  case DIO_PORTC:
		  if (A_u8ConnectPullup == DIO_HIGH)
		  {
			  CLR_BIT(SFIOR,PUD);
			  CLR_BIT(DDRC,A_u8PinNo);
			  SET_BIT(PORTC,A_u8PinNo);
		  }
		  else
		  {
			  CLR_BIT(PORTC,A_u8PinNo);
		  }
		  break;
	  /* Connect or disconnect the pull up resistance to the given pin in port D */
	  case DIO_PORTD:
		  if (A_u8ConnectPullup == DIO_HIGH)
		  {
			  CLR_BIT(SFIOR,PUD);
			  CLR_BIT(DDRD,A_u8PinNo);
			  SET_BIT(PORTD,A_u8PinNo);
		  }
		  else
		  {
			  CLR_BIT(PORTD,A_u8PinNo);
		  }
		  break;
	}
}
/*##################################################################################################################*/
