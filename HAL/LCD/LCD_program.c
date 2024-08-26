/*
 * LCD_program.c
 *
 *  Created on: Aug 12, 2022
 *      Author: SHA
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/TIMER/TIMER_interface.h"

#include "LCD_cfg.h"
#include "LCD_interface.h"


//void HLCD_vInit (void)
//{
//	/* set your pin directions */
//	MDIO_vWrtPortDir(LCD_DATA_PORT   ,DIO_PORT_OUTPUT );
//	MDIO_vWrtPinDir (LCD_CONTROL_PORT ,LCD_RS_PIN ,DIO_PIN_OUTPUT );
//	MDIO_vWrtPinDir (LCD_CONTROL_PORT ,LCD_RW_PIN ,DIO_PIN_OUTPUT );
//	MDIO_vWrtPinDir (LCD_CONTROL_PORT ,LCD_EN_PIN ,DIO_PIN_OUTPUT );
//	/* start init sequence */
//	/* 8-bit initalization */
//	MTIMERS_voidDelay_ms(50);
//	HLCD_vSendCommand(Function_set);
//	MTIMERS_voidDelay_ms(1);
//	HLCD_vSendCommand(Display_ON_CTRL);
//	MTIMERS_voidDelay_ms(1);
//	HLCD_vSendCommand(Display_Clear);
//	MTIMERS_voidDelay_ms(3);
//	HLCD_vSendCommand(Entry_Mode_Set);
//	MTIMERS_voidDelay_ms(1);
//}

//void HLCD_vSendCommand  (u8 A_u8Command)
//{
//	/* control RS & RW PINS */
//	MDIO_vWrtPinVal(LCD_CONTROL_PORT ,LCD_RS_PIN , DIO_LOW);
//	MDIO_vWrtPinVal(LCD_CONTROL_PORT ,LCD_RW_PIN , DIO_LOW);
//
//	/* write command on the data pins */
//	MDIO_vWrtPortVal(LCD_DATA_PORT ,A_u8Command );
//
//	/* pulse on the enable pin */
//	MDIO_vWrtPinVal(LCD_CONTROL_PORT ,LCD_EN_PIN , DIO_HIGH);
//	MTIMERS_voidDelay_ms(1);
//	MDIO_vWrtPinVal(LCD_CONTROL_PORT ,LCD_EN_PIN , DIO_LOW);
//	MTIMERS_voidDelay_ms(1);
//
//}

//void HLCD_vSendData (u8 A_u8data)
//{
//	/* control RS & RW PINS */
//	MDIO_vWrtPinVal(LCD_CONTROL_PORT ,LCD_RS_PIN , DIO_HIGH);
//	MDIO_vWrtPinVal(LCD_CONTROL_PORT ,LCD_RW_PIN , DIO_LOW);
//
//	/* write command on the data pins */
//	MDIO_vWrtPortVal(LCD_DATA_PORT ,A_u8data );
//
//	/* pulse on the enable pin */
//	MDIO_vWrtPinVal(LCD_CONTROL_PORT ,LCD_EN_PIN , DIO_HIGH);
//	MTIMERS_voidDelay_ms(1);
//	MDIO_vWrtPinVal(LCD_CONTROL_PORT ,LCD_EN_PIN , DIO_LOW);
//	MTIMERS_voidDelay_ms(1);
//}
//

void HLCD_vInit(void)
{
    // Set all control pins as output
    MDIO_vWrtPinDir(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_PIN_OUTPUT);
    MDIO_vWrtPinDir(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_PIN_OUTPUT);
    MDIO_vWrtPinDir(LCD_CONTROL_PORT, LCD_EN_PIN, DIO_PIN_OUTPUT);

    // Set all data pins as output
    MDIO_vWrtPortDir(LCD_DATA_PORT, 0xFF);

    // Wait for LCD to power up
    MTIMERS_voidDelay_ms(20);

    // Initialize LCD in 8-bit mode (adjust if using 4-bit mode)
    HLCD_vSendCommand(Function_set); // Function set: 8-bit, 2 lines, 5x8 dots
    MTIMERS_voidDelay_ms(5);
    HLCD_vSendCommand(Display_ON_CTRL); // Display ON, Cursor OFF
    MTIMERS_voidDelay_ms(5);
    HLCD_vSendCommand(Display_Clear); // Clear display
    MTIMERS_voidDelay_ms(5);
    HLCD_vSendCommand(Entry_Mode_Set); // Entry mode: Increment cursor, no shift
    MTIMERS_voidDelay_ms(5);
}

void HLCD_vSendCommand(u8 A_u8Command)
{
    // Set RS and RW to 0 for command mode
    MDIO_vWrtPinVal(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_LOW);
    MDIO_vWrtPinVal(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_LOW);

    // Place command on data bus
    MDIO_vWrtPortVal(LCD_DATA_PORT, A_u8Command);

    // Pulse the enable pin
    MDIO_vWrtPinVal(LCD_CONTROL_PORT, LCD_EN_PIN, DIO_HIGH);
    MTIMERS_voidDelay_us(1);
    MDIO_vWrtPinVal(LCD_CONTROL_PORT, LCD_EN_PIN, DIO_LOW);

    // Wait for command to be processed
    MTIMERS_voidDelay_ms(2);
}

void HLCD_vSendData(u8 A_u8Data)
{
    // Set RS to 1 and RW to 0 for data mode
    MDIO_vWrtPinVal(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_HIGH);
    MDIO_vWrtPinVal(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_LOW);

    // Place data on data bus
    MDIO_vWrtPortVal(LCD_DATA_PORT, A_u8Data);

    // Pulse the enable pin
    MDIO_vWrtPinVal(LCD_CONTROL_PORT, LCD_EN_PIN, DIO_HIGH);
    MTIMERS_voidDelay_us(1);
    MDIO_vWrtPinVal(LCD_CONTROL_PORT, LCD_EN_PIN, DIO_LOW);

    // Wait for data to be processed
    MTIMERS_voidDelay_ms(2);
}


void HLCD_vPrintString(char *A_charstring)
{
    u8 colCount = 0;

    while (*A_charstring != '\0') // Check end of string
    {
        HLCD_vSendData(*A_charstring++); // Send Data, then move pointer to the next Char

        colCount++;

        if (colCount == MAX_LCD_COLS) // If the end of the row is reached
        {
            colCount = 0;
            HLCD_vSendCommand(LCD_SECOND_ROW); // Move to the next row
        }

        MTIMERS_voidDelay_us(50); // Short delay to ensure LCD has processed the character
    }
}



void HLCD_vPrintNumber(s32 A_s32Number)
{
    u8 L_u8Digits[10] = {0};   // Array to store digits
    u8 L_u8Counter = 0;        // Counter for number of digits

    // Handle zero case
    if (A_s32Number == 0)
    {
        HLCD_vSendData('0');
        return;
    }

    // Handle negative numbers
    if (A_s32Number < 0)
    {
        HLCD_vSendData('-');
        A_s32Number = -A_s32Number;  // Convert to positive
    }

    // Save digits in reverse order
    while (A_s32Number > 0)
    {
        L_u8Digits[L_u8Counter] = A_s32Number % 10;
        L_u8Counter++;
        A_s32Number /= 10;
    }

    // Print digits in reverse order
    for (s8 L_s8PrintIndex = L_u8Counter - 1; L_s8PrintIndex >= 0; L_s8PrintIndex--)
    {
        HLCD_vSendData('0' + L_u8Digits[L_s8PrintIndex]);
    }
}


void HLCD_vGoToRowColoum (u8 A_u8Row ,u8 A_u8Coloum)
{
	u8 L_u8DdramAddress;
	u8 L_u8Command     ;
	/* valid range */
	 if ( (A_u8Row <= MAX_IDX_OF_ROWS) && (A_u8Coloum <= MAX_IDX_OF_COL) )
	 {
		 /* GO TO THE GOLOUM & ROWS I WANT */
		 if (A_u8Row == FIRST_ROW_IDX)
		 {
			 L_u8DdramAddress = START_OF_FIRST_ROW  + A_u8Coloum;
		 }
		 else
		 {
			 L_u8DdramAddress = START_OF_SECOND_ROW + A_u8Coloum;
		 }
	 }
	 else
	 {
		 /* DO NOTHING */
	 }

//	 SET_BIT(L_u8DdramAddress ,SET_BIT7_OF_DDRAM_ADDRESS );
//	 HLCD_vSendCommand(L_u8DdramAddress);
	 /* put in bit8 -> 1 to go to the address of the ddram */
	 L_u8Command = L_u8DdramAddress | SET_AC_MASK ;
	 HLCD_vSendCommand(L_u8Command);

}

void HLCD_vWriteCGRAM (u8 A_u8PatternIdx ,u8 *A_u8PatternValue)
{
	u8 L_u8LoopIterator ;
	/* Step1 : set AC on CGRAM */
	switch(A_u8PatternIdx)
	{
	 	case 0 : HLCD_vSendCommand(pattern0);break;
	 	case 1 : HLCD_vSendCommand(pattern1);break;
	 	case 2 : HLCD_vSendCommand(pattern2);break;
	 	case 3 : HLCD_vSendCommand(pattern3);break;
	 	case 4 : HLCD_vSendCommand(pattern4);break;
	 	case 5 : HLCD_vSendCommand(pattern5);break;
	 	case 6 : HLCD_vSendCommand(pattern6);break;
	 	case 7 : HLCD_vSendCommand(pattern7);break;
	 	default:           /*error*/        ;break;
	}
	/* Step2 : write pattern  */
	for (L_u8LoopIterator = 0 ;L_u8LoopIterator < 8 ;L_u8LoopIterator++ )
	{
		HLCD_vSendData(A_u8PatternValue[L_u8LoopIterator]);
	}
}


void HLCD_vScrollText(char *A_u8pText, u16 A_u16Delay_ms)
{
	u8 textLength = 0;
	    char displayBuffer[MAX_LCD_COLS + 1] = {0};  // Buffer to store the text to be displayed

	    // Find the length of the text
	    while (A_u8pText[textLength] != '\0')
	    {
	        textLength++;
	    }

	    // Add padding spaces to the end of the text for scrolling effect
	    char paddedText[MAX_LCD_COLS + textLength + 1];
	    for (u8 i = 0; i < MAX_LCD_COLS + textLength; i++)
	    {
	        if (i < textLength)
	        {
	            paddedText[i] = A_u8pText[i];
	        }
	        else
	        {
	            paddedText[i] = ' ';  // Add spaces to the end
	        }
	    }
	    paddedText[MAX_LCD_COLS + textLength] = '\0';  // Null-terminate the string

	    // Scroll the text from right to left

		for (u8 startIdx = 0; startIdx <= textLength; startIdx++)
		{
			// Clear the LCD and display the current substring
			HLCD_vSendCommand(Display_Clear);
			// Copy the substring to the buffer
			for (u8 i = 0; i <= MAX_LCD_COLS; i++)
			{
				displayBuffer[i] = paddedText[startIdx + i];
			}
			displayBuffer[MAX_LCD_COLS] = '\0';  // Null-terminate the buffer
			HLCD_vPrintString(displayBuffer);
			MTIMERS_voidDelay_ms(A_u16Delay_ms);  // Delay between frames
		}
}

void HLCD_vClearScreen(void)
{
	HLCD_vSendCommand(Display_Clear);
	MTIMERS_voidDelay_ms(10);
}



///////////////////////////////////////////under test
//void scrollTextLeftRight(char *text, u16 delay_ms)
//{
//    u8 textLength = 0;
//    char displayBuffer[MAX_LCD_COLS + 1] = {0};  // Buffer to store the text to be displayed
//
//    // Find the length of the text
//    while (text[textLength] != '\0')
//    {
//        textLength++;
//    }
//
//    // Add padding spaces to the end of the text for scrolling effect
//    char paddedText[MAX_LCD_COLS + textLength + 1];
//    for (u8 i = 0; i < MAX_LCD_COLS + textLength; i++)
//    {
//        if (i < textLength)
//        {
//            paddedText[i] = text[i];
//        }
//        else
//        {
//            paddedText[i] = ' ';  // Add spaces to the end
//        }
//    }
//    paddedText[MAX_LCD_COLS + textLength] = '\0';  // Null-terminate the string
//
//    while (1)
//    {
//        // Scroll text to the left
//        for (u8 startIdx = 0; startIdx <= textLength; startIdx++)
//        {
//            // Clear the LCD and display the current substring
//            HLCD_vSendCommand(Display_Clear);
//            // Copy the substring to the buffer
//            for (u8 i = 0; i < MAX_LCD_COLS; i++)
//            {
//                displayBuffer[i] = paddedText[startIdx + i];
//            }
//            displayBuffer[MAX_LCD_COLS] = '\0';  // Null-terminate the buffer
//            HLCD_vPrintString(displayBuffer);
//            MTIMERS_voidDelay_ms(delay_ms);  // Delay between frames
//        }
//
//        // Scroll text to the right
//        for (u8 startIdx = textLength; startIdx >= MAX_LCD_COLS - 1; startIdx--)
//        {
//            // Clear the LCD and display the current substring
//            HLCD_vSendCommand(Display_Clear);
//            // Copy the substring to the buffer
//            for (u8 i = 0; i < MAX_LCD_COLS; i++)
//            {
//                displayBuffer[i] = paddedText[startIdx - i];
//            }
//            displayBuffer[MAX_LCD_COLS] = '\0';  // Null-terminate the buffer
//            HLCD_vPrintString(displayBuffer);
//            MTIMERS_voidDelay_ms(delay_ms);  // Delay between frames
//        }
//    }
//}






