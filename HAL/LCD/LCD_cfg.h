/*
 * LCD_cfg.h
 *
 *  Created on: Aug 12, 2022
 *      Author: SHA
 */

#ifndef COTS_HAL_LCD_LCD_CFG_H_
#define COTS_HAL_LCD_LCD_CFG_H_

/*
 * OPTIONS:
 * DIO_PORTA
 * DIO_PORTB
 * DIO_PORTC
 * DIO_PORTD
 */
#define LCD_DATA_PORT DIO_PORTC

/*
 * OPTIONS:
 * DIO_PORTA
 * DIO_PORTB
 * DIO_PORTC
 * DIO_PORTD
 */
#define LCD_CONTROL_PORT DIO_PORTD
/*
 * OPTIONS:
 *DIO_PIN0 0
 *DIO_PIN1 1
 *DIO_PIN2 2
 *DIO_PIN3 3
 *DIO_PIN4 4
 *DIO_PIN5 5
 *DIO_PIN6 6
 *DIO_PIN7 7
 */
#define LCD_RS_PIN DIO_PIN0
#define LCD_RW_PIN DIO_PIN1
#define LCD_EN_PIN DIO_PIN2


#define MAX_IDX_OF_ROWS     1
#define FIRST_ROW_IDX       0
#define SECOND_ROW _IDX     1
#define START_OF_FIRST_ROW  0x00
#define START_OF_SECOND_ROW 0x40
#define SET_AC_MASK         0x80

#define MAX_IDX_OF_COL  15

/****************************
 **** patterns in CGRAM ****
 ***************************/
//0  -> 7  0b01000000
#define pattern0 0x40
//8  -> 15 0b01001000
#define pattern1 0x48
//16 -> 23 0b01010000
#define pattern2 0x50
//24 -> 31 0b01011000
#define pattern3 0x58
//32 -> 39 0b01100000
#define pattern4 0x60
//40 -> 47 0b01101000
#define pattern5 0x68
//48 -> 55 0b01110000
#define pattern6 0x70
//56 -> 63 0b01111000
#define pattern7 0x78


/**************
 ** commands **
 **************/

/*options: 0011NFXX
 * N -> 0 (1 line display)
 *   -> 1 (2 line display)
 * F -> 0 (5X7 DOT character font)
 * 	 -> 1 (5X10 DOT character font)
 * X -> DON'T CARE (0)
 */
#define Function_set 0b00111000

/*options: 00001DCB
 * D -> 0 (ON)
 *   -> 1 (OFF)
 * C -> 0 (Cursor off)
 * 	 -> 1 (Cursor ON)
 * B -> 0 (BLINK off)
 * 	 -> 1 (BLINK ON)
 */
#define Display_ON_CTRL   0b00001100
#define Display_OFF_CTRL  0b00001000
#define Display_Clear     0b00000001

/*
 * options: 000001 I/D S
 * I/D  -> 0 (increment mode off)
 * 		-> 1 (increment mode on)
 * 	S   -> 0 (NO display shift operation)
 * 		-> 1 (display shift operation on)
 */
#define Entry_Mode_Set    0b00000110



#endif /* COTS_HAL_LCD_LCD_CFG_H_ */
