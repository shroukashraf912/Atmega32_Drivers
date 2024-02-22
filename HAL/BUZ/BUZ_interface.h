/*
 * BUZ_interface.h
 *
 *  Created on : Aug 8, 2023
 *  Author     : SHA
 *  Layer      : HAL
 *  SWC        : BUZZER
 */

#ifndef COTS_HAL_BUZ_BUZ_INTERFACE_H_
#define COTS_HAL_BUZ_BUZ_INTERFACE_H_
/*########################################################*/
//Port Defines
#define BUZ_PORTA 0
#define BUZ_PORTB 1
#define BUZ_PORTC 2
#define BUZ_PORTD 3
/*########################################################*/
//Pin Defines
#define BUZ_PIN0 0
#define BUZ_PIN1 1
#define BUZ_PIN2 2
#define BUZ_PIN3 3
#define BUZ_PIN4 4
#define BUZ_PIN5 5
#define BUZ_PIN6 6
#define BUZ_PIN7 7
/*########################################################*/
//State
#define ACTIVE_HIGH 1
#define ACTIVE_LOW  0
/*########################################################*/
typedef struct
{
	u8 PORT			;
	u8 PIN			;
	u8 Active_State ;
}BUZ_Type;
/*########################################################*/
void HBUZ_vInit   (BUZ_Type A_SBUZ_Configuration);
void HBUZ_vBUZOn  (BUZ_Type A_SBUZ_Configuration);
void HBUZ_vBUZOff (BUZ_Type A_SBUZ_Configuration);
/*########################################################*/
#endif /* COTS_HAL_BUZ_BUZ_INTERFACE_H_ */
