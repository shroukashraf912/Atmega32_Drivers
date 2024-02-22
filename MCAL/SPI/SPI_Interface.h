/*
 * SPI_Interface.h
 *
 *  Created on: Jul 30, 2023
 *  Author    : Shrouk Ashraf
 *  Layer     : MCAL
 *  SWC       : SPI
 */

#ifndef COTS_MCAL_SPI_SPI_INTERFACE_H_
#define COTS_MCAL_SPI_SPI_INTERFACE_H_

void MSPI_vInit(void);

void MSPI_u8Transceive (u8 A_u8Data ,u8 *PReturnData);
void MSPI_vMasterTransmite(u8 A_u8Data);
u8   MSPI_u8MasterReceive(void);

void MSPI_vSlaveTransmite(u8 A_u8Data);
u8   MSPI_u8SlaverReceive(void);

#endif /* COTS_MCAL_SPI_SPI_INTERFACE_H_ */
