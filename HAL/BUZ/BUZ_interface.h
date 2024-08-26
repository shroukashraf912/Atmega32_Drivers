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
/*
 ****************************************************************************************
 * Function_Name ==>   HBUZ_vInit(A_SBUZ_Configuration)
 * Description   ==>   This Function to initialize the pin which connected to Buzzer as output pin.
 *  Arguments    ==>   struct has the led port,pin,status
 *  Return       ==>   void
 ****************************************************************************************
*/
void HBUZ_vInit   (BUZ_Type A_SBUZ_Configuration);
/*
 ****************************************************************************************
 * Function_Name ==>   HBUZ_vBUZOn(A_SBUZ_Configuration)
 * Description   ==>   This Function to turn on the buzzer.
 *  Arguments    ==>   struct has the led port,pin,status
 *  Return       ==>   void
 ****************************************************************************************
*/
void HBUZ_vBUZOn  (BUZ_Type A_SBUZ_Configuration);
/*
 ****************************************************************************************
 * Function_Name ==>   HBUZ_vBUZOff(A_SBUZ_Configuration)
 * Description   ==>   This Function to turn off the buzzer.
 *  Arguments    ==>   struct has the led port,pin,status
 *  Return       ==>   void
 ****************************************************************************************
*/
void HBUZ_vBUZOff (BUZ_Type A_SBUZ_Configuration);
/*########################################################*/
#endif /* COTS_HAL_BUZ_BUZ_INTERFACE_H_ */
