/*
 * SPI_Register.h
 *
 *  Created on: Jul 30, 2023
 *  Author    : Shrouk Ashraf
 *  Layer     : MCAL
 *  SWC       : SPI
 */

#ifndef COTS_MCAL_SPI_SPI_REGISTER_H_
#define COTS_MCAL_SPI_SPI_REGISTER_H_

#define SPCR *((volatile u8*)(0x2D))
#define SPSR *((volatile u8*)(0x2E))
#define SPDR *((volatile u8*)(0x2F))

#define SS_PIN   DIO_PIN4
#define SPI_PORT  DIO_PORTB
#define MOSI_PIN  DIO_PIN5
#define MISO_PIN  DIO_PIN6
#define SCK_PIN   DIO_PIN7
#endif /* COTS_MCAL_SPI_SPI_REGISTER_H_ */
