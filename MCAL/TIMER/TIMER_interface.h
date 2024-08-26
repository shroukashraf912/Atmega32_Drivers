/*
 * TIMER_interface.h
 *
 *  Created on: Sep 5, 2022
 *      Author: SHA
 */

#ifndef COTS_MCAL_TIMER_TIMER_INTERFACE_H_
#define COTS_MCAL_TIMER_TIMER_INTERFACE_H_


#define Start_Timer             0b010
#define Stop_Timer              0b000
#define Bit_Mask_Of_Timer       0xF8


void MTIMERS_voidInit (u16 A_u16Timer_ID);
void MTIMERS_voidSetPreloadValue(u16 A_u16Timer_ID ,u16 A_u16Preload );
void MTIMERS_voidSetInterval_Asynch(u16 A_u16Timer_ID ,u16 A_u16IntervalCounts ,void (*A_fptr)(void));
void MTIMERS_voidStartTimer(u16 A_u16Timer_ID);
void MTIMERS_voidStopTimer (u16 A_u16Timer_ID);
void MTIMERS_voidSetCompareValue(u16 A_u16Timer_ID ,u16 A_u16CompareValue);
void MTIMERS_vSetInterval_CTC_Asynch(u16 A_u16Timer_ID      ,
									 u16 A_u16IntervalCounts,
									 u16 A_u16CompareValue  ,
									 void (*A_fptr)(void)   );
void MTIMERS_voidDelay_us(u32 A_u32Delay_us);
void MTIMERS_voidDelay_ms(u16 A_u16Delay_ms);

//Waveform_Generation_Modes
#define  Normal     0
#define  PWM        1
#define  CTC        2
#define  Fast_PWM   3

//Interrupt_Enable
#define OVF_Interrupt 0
#define CTC_Interrupt 1

//Prescaler_select
#define Prescaler_8    0
#define Prescaler_64   1
#define Prescaler_256  2
#define Prescaler_1024 3

//Timer_Interrupt
#define ENABLE  0
#define DISABLE 1

//timers
#define Timer_0 0
#define Timer_1 1
#define Timer_2 2

//Timers CallBack
#define TIM_CB_OVF 0
#define TIM_CB_CTC 1

//PIN_OC0
#define Disconnected      0
#define TOGGLE			  1
#define CLEAR			  2
#define SET               3
#define CLR_COM_SET_TOP   4
#define SET_COM_CLR_TOP   5
#define CLR_UP_SET_DOWN   6
#define SET_UP_CLR_DOWN   7
#endif /* COTS_MCAL_TIMER_TIMER_INTERFACE_H_ */
