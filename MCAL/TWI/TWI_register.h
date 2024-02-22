/*
 * TWI_register.h
 *
 *  Created on: Aug 10, 2023
 *  Author    : Shrouk Ashraf
 *  Layer     : MCAL
 *  SWC       : I2C(TWI)
 */

#ifndef COTS_MCAL_TWI_TWI_REGISTER_H_
#define COTS_MCAL_TWI_TWI_REGISTER_H_

#define TWBR	*((volatile u8*)(0x20))
#define TWCR	*((volatile u8*)(0x56))
#define TWSR	*((volatile u8*)(0x21))
#define TWDR	*((volatile u8*)(0x23))
#define TWAR	*((volatile u8*)(0x22))

#endif /* COTS_MCAL_TWI_TWI_REGISTER_H_ */
