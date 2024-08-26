/*
 * LCD_interface.h
 *
 *  Created on: Aug 12, 2022
 *      Author: SHA
 */

#ifndef COTS_HAL_LCD_LCD_INTERFACE_H_
#define COTS_HAL_LCD_LCD_INTERFACE_H_

#define Return_Home   0b00000010
#define ENTRY_MODE 0x06
#define Display_Clear     0b00000001

void HLCD_vInit(void);
void HLCD_vSendCommand(u8 A_u8Command);
void HLCD_vSendData(u8 A_u8data);
void HLCD_vPrintString(char *A_charstring );//string array of characters
void HLCD_vGoToRowColoum(u8 A_u8Row ,u8 A_u8Coloum);
void HLCD_vPrintNumber(s32 A_s32Number);
void HLCD_vWriteCGRAM(u8 A_u8PatternIdx ,u8 *A_u8PatternValue);
void HLCD_vScrollText(char *A_u8pText, u16 A_u16Delay_ms);

void HLCD_vClearScreen(void);

#endif /* COTS_HAL_LCD_LCD_INTERFACE_H_ */
