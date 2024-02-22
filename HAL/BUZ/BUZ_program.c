/*
 * BUZ_program.c
 *
 *  Created on : Aug 8, 2023
 *  Author     : SHA
 *  Layer      : HAL
 *  SWC        : BUZZER
 */

/*##################################################################################################################*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"

#include "BUZ_private.h"
#include "BUZ_config.h"
#include "BUZ_interface.h"
/*##################################################################################################################*/
/*
 ****************************************************************************************
 * Function_Name ==>   HBUZ_vInit(A_SBUZ_Configuration)
 * Description   ==>   This Function to initialize the pin which connected to Buzzer as output pin.
 *  Arguments    ==>   struct has the led port,pin,status
 *  Return       ==>   void
 ****************************************************************************************
*/
void HBUZ_vInit   (BUZ_Type A_SBUZ_Configuration)
{
	MDIO_vWrtPinDir (A_SBUZ_Configuration.PORT ,A_SBUZ_Configuration.PIN ,DIO_PIN_OUTPUT);
}
/*##################################################################################################################*/
/*
 ****************************************************************************************
 * Function_Name ==>   HBUZ_vBUZOn(A_SBUZ_Configuration)
 * Description   ==>   This Function to turn on the buzzer.
 *  Arguments    ==>   struct has the led port,pin,status
 *  Return       ==>   void
 ****************************************************************************************
*/
void HBUZ_vBUZOn  (BUZ_Type A_SBUZ_Configuration)
{
	if (A_SBUZ_Configuration.Active_State== ACTIVE_HIGH)
	{
		MDIO_vWrtPinVal (A_SBUZ_Configuration.PORT ,A_SBUZ_Configuration.PIN ,DIO_HIGH);
	}
	else if(A_SBUZ_Configuration.Active_State== ACTIVE_LOW)
	{
		MDIO_vWrtPinVal (A_SBUZ_Configuration.PORT ,A_SBUZ_Configuration.PIN ,DIO_LOW);
	}
}
/*##################################################################################################################*/
/*
 ****************************************************************************************
 * Function_Name ==>   HBUZ_vBUZOff(A_SBUZ_Configuration)
 * Description   ==>   This Function to turn off the buzzer.
 *  Arguments    ==>   struct has the led port,pin,status
 *  Return       ==>   void
 ****************************************************************************************
*/
void HBUZ_vBUZOff (BUZ_Type A_SBUZ_Configuration)
{
	if (A_SBUZ_Configuration.Active_State== ACTIVE_LOW)
	{
		MDIO_vWrtPinVal (A_SBUZ_Configuration.PORT ,A_SBUZ_Configuration.PIN ,DIO_HIGH);
	}
	else if(A_SBUZ_Configuration.Active_State== ACTIVE_HIGH)
	{
		MDIO_vWrtPinVal (A_SBUZ_Configuration.PORT ,A_SBUZ_Configuration.PIN ,DIO_LOW);
	}
}
/*##################################################################################################################*/

