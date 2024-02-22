/*
 * TWI_private.h
 *
 *  Created on: Aug 10, 2023
 *  Author    : Shrouk Ashraf
 *  Layer     : MCAL
 *  SWC       : I2C(TWI)
 */

#ifndef COTS_MCAL_TWI_TWI_PRIVATE_H_
#define COTS_MCAL_TWI_TWI_PRIVATE_H_

/*#####################################################*/

/*-----------Bits Of Registers---------------*/
//Bits Of TWCR
#define TWINT 7
#define TWEA  6
#define TWSTA 5
#define TWSTO 4
#define TWWC  3
#define TWEN  2
#define TWIE  0

//Bits of TWAR
#define TWA6   7
#define TWA5   6
#define TWA4   5
#define TWA3   4
#define TWA2   3
#define TWA1   2
#define TWA0   1
#define TWGCE  0

//Bits of TWSR
#define TWS7   7
#define TWS6   6
#define TWS5   5
#define TWS4   4
#define TWS3   3
#define TWPS1  1
#define TWPS0  0

/*#####################################################*/
//Interrupt EN/DEN
#define ENABLE   1
#define DISABLE  0

/*#####################################################*/
#define Minimum_Bit_Rate 10
/*#####################################################*/

/*-----------MASTER STATUS CODES------------*/
#define MASTER_SEND_START_COND              0x08
#define MASTER_SEND_REPEATED_STA_COND       0x10
#define MASTER_ARBITRATION_LOST             0x38

//Status Codes for Master Transmitter Mode
#define MASTER_SEND_SLA_W_RECIVE_ACK        0x18
#define MASTER_SEND_SLA_W_RECIVE_NACK       0x20
#define MASTER_SEND_DATA_RECEIVE_ACK        0x28
#define MASTER_SEND_DATA_RECEIVE_NACK       0x30

//Status Codes for Master Receiver Mode
#define MASTER_SEND_SLA_R_RECIVE_ACK        0x40
#define MASTER_SEND_SLA_R_RECIVE_NACK       0x48
#define MASTER_RECEIVE_DATA_RETURN_ACK      0x50
#define MASTER_RECEIVE_DATA_RETURN_NACK     0x58

/*#####################################################*/

/*-----------SLAVE STATUS CODES------------*/

//Status Codes for Slave Receiver Mode
#define SLAVE_RECEIVE_SLA_W_RETURN_ACK   										   0x60
#define SLAVE_ARBITRATION_LOST_MASTER_BUT_RECEIVE_SLA_W_RETURN_ACK                 0x68
#define SLAVE_RECEIVE_GENERAL_CALL_ADDRESS_RETURN_ACK  							   0x70
#define SLAVE_ARBITRATION_LOST_MASTER_BUT_RECEIVE_GENERAL_CALL_ADDRESS_RETURN_ACK  0x78
#define SLAVE_RECEIVE_DATA_RETURN_ACK											   0x80
#define SLAVE_RECEIVE_DATA_RETURN_NACK 											   0x88
#define SLAVE_RECEIVE_DATA_OF_GENERAL_CALL_RETURN_ACK 							   0x90
#define SLAVE_RECEIVE_DATA_OF_GENERAL_CALL_RETURN_NACK 							   0x98
#define SLAVE_RECEIVE_STOP_OR_REPEATED_START_COND     							   0xA0

//Status Codes for Slave Transmitter Mode
#define SLAVE_RECEIVE_SLA_R_RETURN_ACK  							0xA8
#define SLAVE_ARBITRATION_LOST_MASTER_BUT_RECEIVE_SLA_R_RETURN_ACK  0xB0
#define SLAVE_SEND_DATA_IN_TWDR_RECECIVE_ACK					    0xB8
#define SLAVE_SEND_DATA_IN_TWDR_RECECIVE_NACK 						0xC0
#define LAST_DATA_BYTE_IN_TWDR_TRANSMITTED_ACK_RECEIVED 			0xC8

/*#####################################################*/
/*----------Masked macros----------------*/
#define MASKED_PRESCALER_BITS 0xF8

#endif /* COTS_MCAL_TWI_TWI_PRIVATE_H_ */
