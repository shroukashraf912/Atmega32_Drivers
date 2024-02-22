/*
 * SW_program.c
 *
 *  Created on: Aug 20, 2023
 *  Author     : Shrouk Ashraf (SHA)
 *  Layer      : HAL
 *  SWC        : Switch(SW)
 */
/*##################################################################################################################*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"
#include "SW_private.h"
#include "SW_config.h"
#include "SW_interface.h"
/*##################################################################################################################*/
/*
 ****************************************************************************************
 * Function_Name ==>   HSW_vInit(SW_Type A_stSwConfig)
 * Description   ==>   This Function initialize the pin which connected to Push Button as Pull Up Input pin
 * Arguments     ==>   struct has the switch port , pin , status
 * Return        ==>   void
 ****************************************************************************************
*/
void HSW_vInit(SW_Type A_stSwConfig)
{
	MDIO_vWrtPinDir(A_stSwConfig.SW_Port,A_stSwConfig.SW_Pin,DIO_PIN_INPUT);
	if (A_stSwConfig.Pull_State == SW_INTERNAL_PULL_UP)
	{
		MDIO_vWrtPinVal(A_stSwConfig.SW_Port,A_stSwConfig.SW_Pin,DIO_HIGH);
//		MDIO_vEnableInternalPullUp(A_stSwConfig.SW_Port,A_stSwConfig.SW_Pin,DIO_HIGH);
	}
}
/*##################################################################################################################*/
/*
 ****************************************************************************************
 * Function_Name ==>   HSW_u8GetPressedSwitch(SW_Type A_stSwConfig)
 * Description   ==>   This Function read Button status
 * Arguments     ==>   struct has the switch port , pin , status
 * Return        ==>   u8
 ****************************************************************************************
*/
u8   HSW_u8GetPressedSwitch(SW_Type A_stSwConfig)
{
	u8 L_u8Result = SW_NOT_PRESSED;
	u8 L_u8PinVal = SW_NOT_PRESSED;

	if ((A_stSwConfig.Pull_State == SW_INTERNAL_PULL_UP) || (A_stSwConfig.Pull_State == SW_EXTERNAL_PULL_UP))
	{
		L_u8PinVal = MDIO_u8GetPinVal(A_stSwConfig.SW_Port,A_stSwConfig.SW_Pin);
		if (L_u8PinVal == 0)
		{
			L_u8Result = SW_PRESSED;
		}
		else if(L_u8PinVal == 1)
		{
			L_u8Result = SW_NOT_PRESSED;
		}
	}
	else if ((A_stSwConfig.Pull_State == SW_EXTERNAL_PULL_DOWN))
	{
		L_u8PinVal = MDIO_u8GetPinVal(A_stSwConfig.SW_Port,A_stSwConfig.SW_Pin);
		if (L_u8PinVal == 1)
		{
			L_u8Result = SW_PRESSED;
		}
		else if(L_u8PinVal == 0)
		{
			L_u8Result = SW_NOT_PRESSED;
		}
	}

}
/*##################################################################################################################*/
