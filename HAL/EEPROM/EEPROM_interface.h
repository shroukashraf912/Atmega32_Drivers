/*
 * EEPROM_interface.h
 *
 *  Created on: Aug 17, 2023
 *  Author    : Shrouk Ashraf
 *  Layer     : HAL
 *  SWC       : EEPROM
 */

#ifndef COTS_HAL_EEPROM_EEPROM_INTERFACE_H_
#define COTS_HAL_EEPROM_EEPROM_INTERFACE_H_

void HEEPROM_vWriteByte (u8 A_u8DataByte,u16 A_u16Address );
u8   HEEPROM_u8ReadByte (u16 A_u16Address);

#endif /* COTS_HAL_EEPROM_EEPROM_INTERFACE_H_ */
