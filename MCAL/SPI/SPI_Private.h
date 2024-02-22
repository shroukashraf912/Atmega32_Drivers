/*
 * SPI_Private.h
 *
 *  Created on: Jul 30, 2023
 *  Author    : Shrouk Ashraf
 *  Layer     : MCAL
 *  SWC       : SPI
 */

#ifndef COTS_MCAL_SPI_SPI_PRIVATE_H_
#define COTS_MCAL_SPI_SPI_PRIVATE_H_

/*
 * Bits of SPSR Register
 */
#define SPIF 7
#define WCOL 6
#define SPI2X 0


/*
 * Bits of SPCR Register
 */

#define SPIE 7
#define SPE  6
#define DORD 5
#define MSTR 4
#define CPOL 3
#define CPHA 2
#define SPR1 1
#define SPR0 0

/*INTERRUPT & SPI*/
#define ENABLE  1
#define DISABLE 0

/*DATA Transfer*/
#define LSB 0
#define MSB 1

/*MASTER_SLAVE_SELECT*/
#define MASTER 0
#define SLAVE  1

/*SPI Clock Rate*/
#define SCK_4_Normal     0
#define SCK_16_Normal    1
#define SCK_64_Normal    2
#define SCK_128_Normal   3
#define SCK_2_Double     4
#define SCK_8_Double     5
#define SCK_32_Double    6
#define SCK_64_Double    7

/* SPI CLOCK_Polarity & CLOCK_Phase */
#define MODE_0   0
#define MODE_1   1
#define MODE_2   2
#define MODE_3   3



#endif /* COTS_MCAL_SPI_SPI_PRIVATE_H_ */
