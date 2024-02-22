/*
 * LED_interface.h
 *
 *  Created on : Jul 31, 2022
 *  Author	   : SHA
 *  Layer      : HAL
 *  SWC        : LED (Light Emitting Diode)
 */

#ifndef HAL_LED_LED_INTERFACE_H_
#define HAL_LED_LED_INTERFACE_H_

/*########################################################*/
//Port Defines
#define LED_PORTA 0
#define LED_PORTB 1
#define LED_PORTC 2
#define LED_PORTD 3
/*########################################################*/
//Pin Defines
#define LED_PIN0 0
#define LED_PIN1 1
#define LED_PIN2 2
#define LED_PIN3 3
#define LED_PIN4 4
#define LED_PIN5 5
#define LED_PIN6 6
#define LED_PIN7 7
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
}LED_Type;
/*########################################################*/
//The Declaration Of The functions
void HLED_vInit      (LED_Type A_SLED_Configuration);
void HLED_vLedOn     (LED_Type A_SLED_Configuration);
void HLED_vLedOff    (LED_Type A_SLED_Configuration);
void HLED_vLedToggle (LED_Type A_SLED_Configuration);
/*########################################################*/
#endif /* HAL_LED_LED_INTERFACE_H_ */
