/*
 * TIMER_configure.h
 *
 *  Created on: Sep 5, 2022
 *      Author: SHA
 */

#ifndef COTS_MCAL_TIMER_TIMER_CONFIGURE_H_
#define COTS_MCAL_TIMER_TIMER_CONFIGURE_H_

/*************************** Timer-0 config ***************************/
/* options :
 * 1- Normal
 * 2- PWM(phase correct)
 * 3- CTC
 * 4- Fast_PWM
 */
#define W_Form_Generation_Mode  CTC

/*options:
 * 1- Prescaler_8
 * 2- Prescaler_64
 * 3- Prescaler_256
 * 4- Prescaler_1024
 */
#define Prescaler_Select        Prescaler_8

/*options:
 * 1-CTC_Interrupt
 * 2-OVF_Interrupt
 * */
#define Interrupt_Enable        CTC_Interrupt

/*options:
 * 1-ENABLE
 * 2-DISABLE
 * */
#define Timer_Interrupt         DISABLE

/* options :
 * 2- PWM(phase correct)
 * 3- CTC
 * 4- Fast_PWM
 */
#define Compare_Match_Mode     Fast_PWM

/* options:
 **** IN CTC *******
 * Disconnected
 * TOGGLE
 * CLEAR
 * SET
 ****IN Fast_PWM*****
 * CLR_COM_SET_TOP
 * SET_COM_CLR_TOP
 *****IN PWM******
 * CLR_UP_SET_DOWN
 * SET_UP_CLR_DOWN
 * */

#define OC0_PIN                CLR_COM_SET_TOP
/**********************************************************************/

/*************************** Timer-1 config ***************************/

/**********************************************************************/

/*************************** Timer-2 config ***************************/

/**********************************************************************/
#endif /* COTS_MCAL_TIMER_TIMER_CONFIGURE_H_ */
