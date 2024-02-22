/*
 * SPI_Configure.h
 *
 *  Created on: Jul 30, 2023
 *  Author    : Shrouk Ashraf
 *  Layer     : MCAL
 *  SWC       : SPI
 */

#ifndef COTS_MCAL_SPI_SPI_CONFIGURE_H_
#define COTS_MCAL_SPI_SPI_CONFIGURE_H_

/*
 * ENABLE
 * DISABLE
 */
#define INTERRUPT  DISABLE
#define SPIENABLE  ENABLE

/*DATA Transfer:
 * LSB 0
 * MSB 1
 */
#define DATAORDER  LSB

/*MASTER_SLAVE_SELECT:
 * MASTER 0
 * SLAVE  1
 */
#define MASTER_SLAVE_SELECT MASTER


/*SPI Clock Rate
SCK_4_Normal
SCK_16_Normal
SCK_64_Normal
SCK_128_Normal
SCK_2_Double
SCK_8_Double
SCK_32_Double
SCK_64_Double
*/
#define Prescaler SCK_4_Normal

/*
 * SPI CLOCK_Polarity & CLOCK_Phase:
 * MODE_0
 * MODE_1
 * MODE_2
 * MODE_3
 * */
#define SPI_MODE  MODE_3

/*SPI_MS_MODE:
 * MASTER
 * SLAVE
 * */
#define SPI_MS_MODE  MASTER

#endif /* COTS_MCAL_SPI_SPI_CONFIGURE_H_ */
