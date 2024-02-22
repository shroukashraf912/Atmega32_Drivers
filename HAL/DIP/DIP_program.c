/*

 * DIP_program.c
 *
 *  Created on: Jul 31, 2022
 *      Author: SHA
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"

#include "DIP_cfg.h"
#include "DIP_interface.h"

void HDIP_vInit (void)
{
	//1- CONFIGURE PIN OF 8 DIP SWITCH AS INPUT
	for (u8 i=0 ; i<=7 ;i++)
	{
		MDIO_vWrtPinDir(DIO_PORTA ,i ,DIO_PIN_INPUT);
	}
	//CONFIGURE Pull up
	MDIO_vWrtPinVal(DIO_PORTA ,DIO_PIN7 ,DIO_HIGH);
}

u8   HDIP_u8GetValue ( u8 *A_u8PValOfDip )
{
	//STEP 2:GET VAL
	for (u8 DIP_PIN = DIO_PIN0 ; DIP_PIN <= DIO_PIN7 ; DIP_PIN ++)
	{
		A_u8PValOfDip[DIP_PIN] = MDIO_u8GetPinVal(DIP_PORT ,DIP_PIN );
	}
	return *A_u8PValOfDip;
}
