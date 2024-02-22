/*
 * EEPROM.c
 *
 *  Created on: Aug 17, 2023
 *  Author    : Shrouk Ashraf
 *  Layer     : HAL
 *  SWC       : EEPROM
 */

/*##################################################################################################################*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/TWI/TWI_interface.h"

#include "EEPROM_private.h"
#include "EEPROM_config.h"
#include "EEPROM_interface.h"
/*##################################################################################################################*/
/*
 * *****************************************************************
 * Function_Name ==> HEEPROM_vWriteByte(A_u8DataByte,A_u16Address).
 * Description   ==> Write data in EEPROM by using TWI Driver
 * Arguments     ==> u8 A_u8DataByte,u16 A_u16Address
 * Returns       ==> void
 * *******************************************************************
 */

void HEEPROM_vWriteByte (u8 A_u8DataByte,u16 A_u16Address )
{
	/* Byte Write */
	MTWI_u8StartCondition();
	MTWI_u8SendSlaveAdressRw(SLAVE_ADDRESS,TWI_WRITE);
	MTWI_u8SendByte((u8)A_u16Address);
	MTWI_u8SendByte(A_u8DataByte);
	MTWI_u8StopCondition();
	/* Page Write */
}
/*##################################################################################################################*/
/*
 * *****************************************************************
 * Function_Name ==> HEEPROM_u8ReadByte(A_u16Address).
 * Description   ==> Read data from EEPROM by using TWI Driver
 * Arguments     ==> u16 A_u16Address
 * Returns       ==> u8
 * *******************************************************************
 */
u8   HEEPROM_u8ReadByte (u16 A_u16Address)
{
	u8 L_u8Receive = Zero ;
	MTWI_u8StartCondition();
	MTWI_u8SendSlaveAdressRw(SLAVE_ADDRESS,TWI_WRITE);
	MTWI_u8SendByte((u8)A_u16Address);
	MTWI_u8StartCondition();
	MTWI_u8SendSlaveAdressRw(SLAVE_ADDRESS,TWI_READ);
	MTWI_u8ReceiveByte(&L_u8Receive,TWI_NOT_ACK);
	MTWI_u8StopCondition();
	return L_u8Receive;
}
/*##################################################################################################################*/
