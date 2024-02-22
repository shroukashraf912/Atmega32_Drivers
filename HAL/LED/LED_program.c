/*
 * LED_program.c
 *
 *  Created on : Jul 31, 2022
 *  Author	   : SHA
 *  Layer      : HAL
 *  SWC        : LED (Light Emitting Diode)
 */

/*##################################################################################################################*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"

#include "LED_config.h"
#include "LED_interface.h"
/*##################################################################################################################*/
/*
 ****************************************************************************************
 * Function_Name ==>   HLED_vInit(A_SLED_Configuration)
 * Description   ==>   This Function to initialize the pin which connected to led as output pin.
 *  Arguments    ==>   struct has the led port,pin,status
 *  Return       ==>   void
 ****************************************************************************************
*/

void HLED_vInit   (LED_Type A_SLED_Configuration)
{
	MDIO_vWrtPinDir (A_SLED_Configuration.PORT ,A_SLED_Configuration.PIN ,DIO_PIN_OUTPUT);
}
/*##################################################################################################################*/
/*
 ****************************************************************************************
 * Function_Name ==>   HLED_vLedOn(A_SLED_Configuration)
 * Description   ==>   This Function to turn on the led that connected to the Mc.
 *  Arguments    ==>   struct has the led port,pin,status
 *  Return       ==>   void
 ****************************************************************************************
*/
void HLED_vLedOn  (LED_Type A_SLED_Configuration)
{
	if (A_SLED_Configuration.Active_State== ACTIVE_HIGH)
	{
		MDIO_vWrtPinVal (A_SLED_Configuration.PORT ,A_SLED_Configuration.PIN ,DIO_HIGH);
	}
	else if(A_SLED_Configuration.Active_State== ACTIVE_LOW)
	{
		MDIO_vWrtPinVal (A_SLED_Configuration.PORT ,A_SLED_Configuration.PIN ,DIO_LOW);
	}
}
/*##################################################################################################################*/
/*
 ****************************************************************************************
 * Function_Name ==>   HLED_vLedOff(A_SLED_Configuration)
 * Description   ==>   This Function to turn on the led that connected to the Mc.
 *  Arguments    ==>   struct has the led port,pin,status
 *  Return       ==>   void
 ****************************************************************************************
*/
void HLED_vLedOff (LED_Type A_SLED_Configuration)
{
	if (A_SLED_Configuration.Active_State== ACTIVE_LOW)
	{
		MDIO_vWrtPinVal (A_SLED_Configuration.PORT ,A_SLED_Configuration.PIN ,DIO_HIGH);
	}
	else if(A_SLED_Configuration.Active_State== ACTIVE_HIGH)
	{
		MDIO_vWrtPinVal (A_SLED_Configuration.PORT ,A_SLED_Configuration.PIN ,DIO_LOW);
	}
}
/*##################################################################################################################*/
/*
 ****************************************************************************************
 * Function_Name ==>   HLED_vLedToggle(A_SLED_Configuration)
 * Description   ==>   This Function to Toggle the led that connected to the Mc.
 *  Arguments    ==>   struct has the led port,pin,status
 *  Return       ==>   void
 ****************************************************************************************
*/
void HLED_vLedToggle (LED_Type A_SLED_Configuration)
{
	MDIO_vTogPinVal(A_SLED_Configuration.PORT ,A_SLED_Configuration.PIN);
}
/*##################################################################################################################*/

