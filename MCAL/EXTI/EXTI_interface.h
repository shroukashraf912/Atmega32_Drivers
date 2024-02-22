/*
 * EXTI_interface.h
 *
 *  Created on: Jul 30, 2022
 *      Author: Lenovo
 */

#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_

/* HW Connection */
#define DIO_INT0_PORT   DIO_PORTD
#define DIO_INT0_PIN    DIO_PIN2

#define DIO_INT1_PORT   DIO_PORTD
#define DIO_INT1_PIN    DIO_PIN3

#define DIO_INT2_PORT   DIO_PORTB
#define DIO_INT2_PIN    DIO_PIN2


void MEXTI_vInit             (void);
void MEXTI_vEnableInterrupt  (u8 A_u8ExtiLineNo);
void MEXTI_vDisableInterrupt (u8 A_u8ExtiLineNo);
void MEXTI_vSetSenseControl  (u8 A_u8ExtiLineNo ,u8 A_u8SenseControl);

#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
