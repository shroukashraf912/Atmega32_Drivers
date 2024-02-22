/*
 * TWI_interface.h
 *
 *  Created on: Aug 10, 2023
 *  Author    : Shrouk Ashraf
 *  Layer     : MCAL
 *  SWC       : I2C(TWI)
 */

#ifndef COTS_MCAL_TWI_TWI_INTERFACE_H_
#define COTS_MCAL_TWI_TWI_INTERFACE_H_

#define TWI_WRITE  0
#define TWI_READ   1

/*-------------Acknowledgment--------------*/
#define TWI_ACK       1
#define TWI_NOT_ACK   0

void MTWI_vInit(void);


u8   MTWI_u8StartCondition(void);
u8   MTWI_u8RepeatedStartCondition(void);
u8   MTWI_u8SendSlaveAdressRw(u8 A_u8Sla,u8 A_u8Rw);
u8   MTWI_u8SendByte(u8 A_u8Byte);
u8   MTWI_u8ReceiveByte(u8* A_pu8Byte,u8 A_u8Ack);
u8   MTWI_u8StopCondition(void);
u8   MTWI_u8GetStatus(void);


void MTWI_vSetBitRate(u32 A_u32BitRate);
void MTWI_vSetSlaveAddress(u8 A_u8OwnSla);


#endif /* COTS_MCAL_TWI_TWI_INTERFACE_H_ */
