/*
 * SSD_program.c
 *
 *  Created on: Jul 9, 2022
 *  Author    : shrouk ashraf(SHA)
 *  Layer     : HAL
 *  SWC       : SSD(Seven Segment Display)
 */
/*##################################################################################################################*/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "SSD_config.h"
#include "SSD_private.h"
#include "SSD_interface.h"
/*##################################################################################################################*/

static u8 GS_u8ASsdDecToASeg[10] = SSD_ANODE_SEGMENT;
static u8 GS_u8ASsdDecToCSeg[10] = SSD_CATHODE_SEGMENT;

/*##################################################################################################################*/
/*
 ****************************************************************************************
 * Function_Name ==>   HSSD_vIntial(A_StSsdConfiguration)
 * Description   ==>   This Function to turn on the buzzer.
 *  Arguments    ==>   DataPort --> Port Name [ SSD_PORTA ,	SSD_PORTB , SSD_PORTC , SSD_PORTD ]
 *  Return       ==>   void
 ****************************************************************************************
*/
void HSSD_vIntial  (SSD_Type A_StSsdConfiguration)
{
	MDIO_vWrtPortDir(A_StSsdConfiguration.DataPort ,SSD_PORT_HIGH);
}
/*##################################################################################################################*/
/*
 ****************************************************************************************
 * Function_Name ==>   HSSD_vDispNum(SSD_Type A_StSsdConfiguration,u8 A_u8Num)
 * Description   ==>   This Function write Number on 7 seg [ 0 : 9 ]
 *  Arguments    ==>   struct has the SSD type , data port and enable(port & pin)
 *  Return       ==>   void
 ****************************************************************************************
*/
/* wrt the num */
void HSSD_vDispNum (SSD_Type A_StSsdConfiguration,u8 A_u8Num)
{
	if (A_StSsdConfiguration.ID == SSD_COMMON_ANODE)
	{
		MDIO_vWrtPortVal(A_StSsdConfiguration.DataPort ,GS_u8ASsdDecToASeg[A_u8Num]);
	}
	else if(A_StSsdConfiguration.ID == SSD_COMMON_CATHODE)
	{
		MDIO_vWrtPortVal(A_StSsdConfiguration.DataPort ,GS_u8ASsdDecToCSeg[A_u8Num]);
	}
}
/*##################################################################################################################*/
/*
 ****************************************************************************************
 * Function_Name ==>   HSSD_vTurnOn( A_StSsdConfiguration)
 * Description   ==>   This Function enable common pin
 *  Arguments    ==>   struct has the SSD type , data port and enable(port & pin)
 *  Return       ==>   void
 ****************************************************************************************
*/
void HSSD_vTurnOn  (SSD_Type A_StSsdConfiguration)
{
	if (A_StSsdConfiguration.ID == SSD_COMMON_ANODE)
	{
		MDIO_vWrtPinDir(A_StSsdConfiguration.EnablePort,A_StSsdConfiguration.EnablePin,DIO_PIN_OUTPUT);
		MDIO_vWrtPinVal(A_StSsdConfiguration.EnablePort,A_StSsdConfiguration.EnablePin,DIO_HIGH);
	}
	else if(A_StSsdConfiguration.ID == SSD_COMMON_CATHODE)
	{
		MDIO_vWrtPinDir(A_StSsdConfiguration.EnablePort,A_StSsdConfiguration.EnablePin,DIO_PIN_OUTPUT);
		MDIO_vWrtPinVal(A_StSsdConfiguration.EnablePort,A_StSsdConfiguration.EnablePin,DIO_LOW);
	}

}
/*##################################################################################################################*/
/*
 ****************************************************************************************
 * Function_Name ==>   HSSD_vTurnOn( A_StSsdConfiguration)
 * Description   ==>   This Function disable common pin
 *  Arguments    ==>   struct has the SSD type , data port and enable(port & pin)
 *  Return       ==>   void
 ****************************************************************************************
*/
void HSSD_vTurnOff (SSD_Type A_StSsdConfiguration)
{
	if (A_StSsdConfiguration.ID == SSD_COMMON_ANODE)
	{
		MDIO_vWrtPinDir(A_StSsdConfiguration.EnablePort,A_StSsdConfiguration.EnablePin,DIO_PIN_OUTPUT);
		MDIO_vWrtPinVal(A_StSsdConfiguration.EnablePort,A_StSsdConfiguration.EnablePin,DIO_LOW);
	}
	else if(A_StSsdConfiguration.ID == SSD_COMMON_CATHODE)
	{
		MDIO_vWrtPinDir(A_StSsdConfiguration.EnablePort,A_StSsdConfiguration.EnablePin,DIO_PIN_OUTPUT);
		MDIO_vWrtPinVal(A_StSsdConfiguration.EnablePort,A_StSsdConfiguration.EnablePin,DIO_HIGH);
	}

}
/*######################################################## END ##########################################################*/
