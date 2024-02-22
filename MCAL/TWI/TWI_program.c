/*

 * TWI_program.c
 *
 *  Created on: Aug 10, 2023
 *  Author    : Shrouk Ashraf
 *  Layer     : MCAL
 *  SWC       : I2C(TWI)
 *  Version   : V0
 */

/*##################################################################################################################*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../DIO/DIO_interface.h"
#include "TWI_register.h"
#include "TWI_private.h"
#include "TWI_config.h"
#include "TWI_interface.h"
/*##################################################################################################################*/
/*
 * *****************************************************************
 * Function_Name ==> MTWI_vInit().
 * Description   ==> Initialization the Inter Integrated circuit (I2C) or Two Wired Integrated in AVR Atmega32.
 * Arguments     ==> void
 * Returns       ==> void
 * *******************************************************************
 */
void MTWI_vInit(void)
{
	/* Interrupt Enable/Disable */
	#if INTERRUPT_MODE == ENABLE
		SET_BIT(TWCR,TWIE);
	#elif INTERRUPT_MODE == DISABLE
		CLR_BIT(TWCR,TWIE);
	#else
		#error "ERROR :("
	#endif
	/* Bit Rate */
	TWBR = Minimum_Bit_Rate;

}
/*##################################################################################################################*/
/*
 * *****************************************************************
 * Function_Name ==> MTWI_u8StartCondition().
 * Description   ==> To Send Start Condition By falling edge in the SDA send To the SCK By Master To The Data Line.
 * Arguments     ==> void
 * Returns       ==> u8
 * *******************************************************************
 */
u8 MTWI_u8StartCondition(void)
{
	/* 1- Send Start Condition */
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	/* 2- Wait for TWINT Flag is Set,This indicates that the START condition has been transmitted*/
	while (!(TWCR & (1<<TWINT)));

	/* 3- Check value of TWI Status Register. Mask prescaler bits. If status different from START go to ERROR */
//	if ((TWSR & START_MASKED_PRESCALER_BITS) != MASTER_SEND_START_COND)
//	ERROR();

	return (TWSR & MASKED_PRESCALER_BITS);

}
/*##################################################################################################################*/
/*
 * *****************************************************************
 * Function_Name ==> MTWI_u8RepeatedStartCondition().
 * Description   ==> To Send Repeated Start Condition By falling edge in the SDA send To the SCK By Master To The Data Line.
 * Thats The Same Function of Start Condition But It is for Just Documentation
 * Arguments     ==> void
 * Returns       ==> u8
 * *******************************************************************
 */
u8   MTWI_u8RepeatedStartCondition(void)
{
	/* 1- Send Start Condition */
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	/* 2- Wait for TWINT Flag is Set,This indicates that the START condition has been transmitted*/
	while (!(TWCR & (1<<TWINT)));

	/* 3- Check value of TWI Status Register. Mask prescaler bits. If status different from START go to ERROR */
//	if ((TWSR & START_MASKED_PRESCALER_BITS) != MASTER_SEND_START_COND)
//	ERROR();

	return (TWSR & MASKED_PRESCALER_BITS);
}
/*##################################################################################################################*/
/*
 * *****************************************************************
 * Function_Name ==> MTWI_u8SendSlaveAdressRw(A_u8Sla, A_u8Rw)
 * Description   ==> After Start Condition the Master Send the SLA & what's it want? Read Or Write.
 * Arguments     ==> u8 A_u8Sla,u8 A_u8Rw
 * Returns       ==> void
 * *******************************************************************
 */
u8 MTWI_u8SendSlaveAdressRw(u8 A_u8Sla,u8 A_u8Rw)
{
	/* 1- Put SLA in data register with read or write configuration*/
	TWDR = (A_u8Sla << 1) | (A_u8Rw) ;
	/* 2- Clear Interrupt Flag & Enable TWI */
	TWCR = (1<<TWINT) | (1<<TWEN);
	/* 3- After Ensure I'm Send Start Condition Clear this bit*/
	CLR_BIT(TWCR,TWSTA);
	/* 4- Wait for TWINT Flag is Set,This indicates that the SLA+W has been transmitted, and ACK/NACK has been received.*/
	while (!(TWCR & (1<<TWINT)));
	/* 5- Check value of TWI Status Register. Mask prescaler bits. If status different from MT_SLA_ACK go to ERROR*/
//	if ((TWSR & MASKED_PRESCALER_BITS) != MT_SLA_ACK)
//	ERROR();
	return (TWSR & MASKED_PRESCALER_BITS);
}
/*##################################################################################################################*/
/*
 * *****************************************************************
 * Function_Name ==> MTWI_u8SendByte(A_u8Byte)
 * Description   ==> After the Slave send Acknowledge The master Start Read Or write means Send Data to Slaves
 * Arguments     ==> u8 A_u8Byte
 * Returns       ==> u8
 * *******************************************************************
 */
u8 MTWI_u8SendByte(u8 A_u8Byte)
{
	/* 1- Put Data in data register */
	TWDR = A_u8Byte;
	/* 2- Clear Interrupt Flag & Enable TWI */
	TWCR = (1<<TWINT) | (1<<TWEN);
	/* 3- Wait for TWINT Flag set. This indicates that the DATA has been transmitted, and ACK/NACK has been received.*/
	while (!(TWCR & (1<<TWINT)));
	/* 4- Check & Return value of TWI Status Register. Mask prescaler bits. If status different from MT_DATA_ACK go to ERROR*/
//	if ((TWSR & 0xF8) != MT_DATA_ACK)
//	ERROR();
	return (TWSR & MASKED_PRESCALER_BITS);
}
/*##################################################################################################################*/
/*
 * *****************************************************************
 * Function_Name ==> MTWI_u8ReceiveByte(A_pu8Byte,A_u8Ack)
 * Description   ==> the slave or master Start to Receive Data Then Send Ack
 * Arguments     ==> u8* A_pu8Byte,u8 A_u8Ack
 * Returns       ==> u8
 * *******************************************************************
 */
u8   MTWI_u8ReceiveByte(u8* A_pu8Byte,u8 A_u8Ack)
{
	/* Clear Interrupt flag and Enable TWI and Send ACK */
	switch (A_u8Ack)
	{
		case TWI_ACK:
			TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
			break;
		case TWI_NOT_ACK:
			TWCR = (1<<TWINT)|(1<<TWEN);
			CLR_BIT(TWCR,TWEA);
			break;
	}
	/* 3- Wait for TWINT Flag set. This indicates that the DATA has been Received, and ACK/NACK has been received.*/
	while (!(TWCR & (1<<TWINT)));
	/* 4- Receive the data in TWDR registers*/
	*A_pu8Byte = TWDR;
	/* 5- Return value of TWI Status Register. Mask prescaler bits.*/
	return (TWSR & MASKED_PRESCALER_BITS);
}
/*##################################################################################################################*/
/*
 * *****************************************************************
 * Function_Name ==> MTWI_u8StopCondition().
 * Description   ==> To Send Stop Condition By Raising edge in the SDA send To the SCK By Master To The Data Line.
 * Arguments     ==> void
 * Returns       ==> u8
 * *******************************************************************
 */
u8 MTWI_u8StopCondition(void)
{
	/* 1- Transmit STOP condition*/
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
	/* 2- Return value of TWI Status Register. Mask prescaler bits.*/
	return (TWSR & MASKED_PRESCALER_BITS);
}
/*##################################################################################################################*/
/*
 * *****************************************************************
 * Function_Name ==> MTWI_u8GetStatus().
 * Description   ==> To Get the Status I'm in it
 * Arguments     ==> void
 * Returns       ==> u8
 * *******************************************************************
 */
u8   MTWI_u8GetStatus(void)
{
	return (TWSR & MASKED_PRESCALER_BITS);
}
/*##################################################################################################################*/
/*
 * *****************************************************************
 * Function_Name ==> MTWI_vSetBitRate(A_u32BitRate).
 * Description   ==> To Set The Bit Rate By User From 100kbps to 400kbps
 * Arguments     ==> u8 A_u32BitRate
 * Returns       ==> void
 * *******************************************************************
 */
void MTWI_vSetBitRate(u32 A_u32BitRate)
{

}
/*##################################################################################################################*/
/*
 * *****************************************************************
 * Function_Name ==> MTWI_vSetSlaveAddress(A_u8OwnSla).
 * Description   ==> To Send the Slave Addresses That I want to Talk
 * Arguments     ==> void
 * Returns       ==> u8
 * *******************************************************************
 */
void MTWI_vSetSlaveAddress(u8 A_u8OwnSla)
{

}
/*##################################################################################################################*/




