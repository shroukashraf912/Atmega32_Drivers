/*
 * LCD_interface.h
 *
 *  Created on: Aug 12, 2022
 *      Author: SHA
 */

#ifndef COTS_HAL_LCD_LCD_INTERFACE_H_
#define COTS_HAL_LCD_LCD_INTERFACE_H_

#define Clear_Display 0b00000001
#define Return_Home   0b00000010

void HLCD_vInit              (void);
void HLCD_vSendCommand       (u8 A_u8Command);
void HLCD_vSendData          (u8 A_u8data);
void HLCD_vPrintString       (char *A_charstring );//string array of characters
void HLCD_vGoToRowColoum     (u8 A_u8Row ,u8 A_u8Coloum);
void HLCD_vPrintNumber       (s32 A_s32Number);
void HLCD_vWriteCGRAM        (u8 A_u8PatternIdx ,u8 *A_u8PatternValue);

#endif /* COTS_HAL_LCD_LCD_INTERFACE_H_ */
