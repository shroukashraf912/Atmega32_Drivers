/*
 * KYD_cfg.h
 *
 *  Created on: Jul 28, 2022
 *      Author: Lenovo
 */

#ifndef HAL_KPD_KYD_CFG_H_
#define HAL_KPD_KYD_CFG_H_

/*
 * OPTIONS:
 * DIO_PORTA
 * DIO_PORTB
 * DIO_PORTC
 * DIO_PORTD
 */
//#define KPD_PORT  DIO_PORTC
//
//#define COL_START DIO_PIN0
//#define COL_END   DIO_PIN3
//
//#define ROW_START DIO_PIN4
//#define ROW_END   DIO_PIN7
//
//#define ROW_SIZE 4
//#define COL_SIZE 4
//
//#define KPD_NOT_PRESSED 255

#define KPD_PORT    DIO_PORTA	  /* Keypad HW Connection */

#define COL_START   DIO_PIN0      /* First Column is PIN0 */
#define COL_END     DIO_PIN3      /* Last  Column is PIN3 */
#define ROW_START   DIO_PIN4      /* First Row    is PIN4 */
#define ROW_END     DIO_PIN7      /* Last  Row    is PIN7 */

#define ROW_SIZE 4
#define COL_SIZE 4

#endif /* HAL_KPD_KYD_CFG_H_ */
