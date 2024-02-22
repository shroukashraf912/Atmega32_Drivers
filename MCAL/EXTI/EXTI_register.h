/*
 * EXTI_register.h
 *
 *  Created on: Jul 30, 2022
 *      Author: Lenovo
 */

#ifndef MCAL_EXTI_EXTI_REGISTER_H_
#define MCAL_EXTI_EXTI_REGISTER_H_

#define MCUCR  *((volatile u8*)0x55)
#define MCUCSR *((volatile u8*)0x54)
#define GICR   *((volatile u8*)0x5B)
#define GIFR   *((volatile u8*)0x5A)

#endif /* MCAL_EXTI_EXTI_REGISTER_H_ */
