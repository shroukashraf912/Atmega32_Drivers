/*
 * SPI_Program.c
 *
 *  Created on: Jul 30, 2023
 *  Author    : Shrouk Ashraf
 *  Layer     : MCAL
 *  SWC       : SPI
 *  Version   : V0
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../DIO/DIO_interface.h"
#include "SPI_Interface.h"
#include "SPI_Register.h"
#include "SPI_Private.h"
#include "SPI_Configure.h"


/*
 ****************************************************************************************
 * Function_Name ==>   MSPI_vInit()
 * Description   ==>   function used to enable the SPI internal circuit of AVR Atmega32
 * 						--> In SPCR Register:
 * 						- Enable Interrupt.
 * 						- SPI Enable.
 * 						- Data Order.
 * 						- Master Or Slave
 * 						- SPI_MODE:
 * 							- Clock Polarity
 * 							- Clock Phase
 * 						- Prescaler
 *
 *  Arguments    ==>   void
 *  Return       ==>   void
 ****************************************************************************************
*/
void MSPI_vInit(void)
{


	#if SPI_MS_MODE == MASTER
		MDIO_vWrtPinDir(SPI_PORT,MOSI_PIN,DIO_PORT_OUTPUT); //MOSI => pin5 output
		MDIO_vWrtPinDir(SPI_PORT,MISO_PIN,DIO_PORT_INPUT);  //MISO => pin6 input
		MDIO_vWrtPinDir(SPI_PORT,SCK_PIN,DIO_PORT_OUTPUT);  //SCK  => pin7 output
		MDIO_vWrtPinVal(SPI_PORT,MISO_PIN,DIO_HIGH);
	#elif SPI_MS_MODE == SLAVE
		MDIO_vWrtPinDir(SPI_PORT,MOSI_PIN,DIO_PORT_INPUT);  //MOSI => pin5 input
		MDIO_vWrtPinDir(SPI_PORT,MISO_PIN,DIO_PORT_OUTPUT); //MISO => pin6 output
		MDIO_vWrtPinDir(SPI_PORT,SCK_PIN,DIO_PORT_OUTPUT);  //SCK  => pin7 output
	#endif
	u8 L_u8TempSPCR = 0;
	/*Write My Configurable Code Here*/
	/* --> In SPCR Register:*/
	/* - Enable Interrupt. */
	#if INTERRUPT == ENABLE
		SET_BIT(L_u8TempSPCR,SPIE);
	#else
		CLR_BIT(L_u8TempSPCR,SPIE);
	#endif
	/* - SPI Enable.       */
	#if SPIENABLE == ENABLE
		SET_BIT(L_u8TempSPCR,SPE);
	#else
		CLR_BIT(L_u8TempSPCR,SPE);
	#endif
	/* - Data Order.       */
	#if DATAORDER == LSB
		SET_BIT(L_u8TempSPCR,DORD);
	#else
		CLR_BIT(L_u8TempSPCR,DORD);
	#endif
	/* - Master Or Slave   */
	#if MASTER_SLAVE_SELECT == MASTER
		SET_BIT(L_u8TempSPCR,MSTR);
	#else
		CLR_BIT(L_u8TempSPCR,MSTR);
	#endif
	/* - SPI_MODE   */
	#if SPI_MODE == MODE_0
			CLR_BIT(L_u8TempSPCR,CPOL);
			CLR_BIT(L_u8TempSPCR,CPHA);
	#elif SPI_MODE == MODE_1
			CLR_BIT(L_u8TempSPCR,CPOL);
			SET_BIT(L_u8TempSPCR,CPHA);
	#elif SPI_MODE == MODE_2
			SET_BIT(L_u8TempSPCR,CPOL);
			CLR_BIT(L_u8TempSPCR,CPHA);
	#elif SPI_MODE == MODE_3
			SET_BIT(L_u8TempSPCR,CPOL);
			SET_BIT(L_u8TempSPCR,CPHA);
	#else
	#endif

	/* - Prescaler         */
	#if Prescaler == SCK_4_Normal
		CLR_BIT(L_u8TempSPCR,SPR0);
		CLR_BIT(L_u8TempSPCR,SPR1);
		CLR_BIT(SPSR,SPI2X);
	#elif Prescaler == SCK_16_Normal
		SET_BIT(L_u8TempSPCR,SPR0);
		CLR_BIT(L_u8TempSPCR,SPR1);
		CLR_BIT(SPSR,SPI2X);
	#elif Prescaler == SCK_64_Normal
		CLR_BIT(L_u8TempSPCR,SPR0);
		SET_BIT(L_u8TempSPCR,SPR1);
		CLR_BIT(SPSR,SPI2X);
	#elif Prescaler == SCK_128_Normal
		SET_BIT(L_u8TempSPCR,SPR0);
		SET_BIT(L_u8TempSPCR,SPR1);
		CLR_BIT(SPSR,SPI2X);
	#elif Prescaler == SCK_2_Double
		CLR_BIT(L_u8TempSPCR,SPR0);
		CLR_BIT(L_u8TempSPCR,SPR1);
		SET_BIT(SPSR,SPI2X);
	#elif Prescaler == SCK_8_Double
		SET_BIT(L_u8TempSPCR,SPR0);
		CLR_BIT(L_u8TempSPCR,SPR1);
		SET_BIT(SPSR,SPI2X);
	#elif Prescaler == SCK_32_Double
		CLR_BIT(L_u8TempSPCR,SPR0);
		SET_BIT(L_u8TempSPCR,SPR1);
		SET_BIT(SPSR,SPI2X);
	#elif Prescaler == SCK_64_Double
		SET_BIT(L_u8TempSPCR,SPR0);
		SET_BIT(L_u8TempSPCR,SPR1);
		SET_BIT(SPSR,SPI2X);
	#else
	#endif

	/*STORE THE Values IN the Register */
	SPCR = L_u8TempSPCR;

}


/*
 ****************************************************************************************
 * Function_Name ==>   MSPI_u8Transceive (A_u8Data)
 * Description   ==>   function used to Transmit and receive the Data
 *  Arguments    ==>   u8 A_u8Data
 *  Return       ==>   u8
 ****************************************************************************************
*/
void  MSPI_u8Transceive (u8 A_u8Data ,u8 *PReturnData)
{

	#if SPI_MS_MODE == MASTER
	/*Start Transmission*/
	SPDR = A_u8Data;
	/*Wait For transmission Complete*/
	while (GET_BIT(SPSR,SPIF)!= 1);
	#elif SPI_MS_MODE == SLAVE
	/*Wait For Reception Complete*/
	while (GET_BIT(SPSR,SPIF)!= 1);
	/*Return data Register*/
	#endif
	*PReturnData = SPDR;

//	return SPDR;
}

