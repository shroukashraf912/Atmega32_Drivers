/*
 * LCD_program.c
 *
 *  Created on: Aug 12, 2022
 *      Author: SHA
 */
#include <util/delay.h>
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"

#include "LCD_cfg.h"
#include "LCD_interface.h"


void HLCD_vInit (void)
{
	/* set your pin directions */
	MDIO_vWrtPortDir(LCD_DATA_PORT   ,DIO_PORT_OUTPUT );
	MDIO_vWrtPinDir (LCD_CONTROL_PORT ,LCD_RS_PIN ,DIO_PIN_OUTPUT );
	MDIO_vWrtPinDir (LCD_CONTROL_PORT ,LCD_RW_PIN ,DIO_PIN_OUTPUT );
	MDIO_vWrtPinDir (LCD_CONTROL_PORT ,LCD_EN_PIN ,DIO_PIN_OUTPUT );
	/* start init sequence */
	/* 8-bit initalization */
	_delay_ms(50);
	HLCD_vSendCommand(Function_set);
	_delay_ms(1);
	HLCD_vSendCommand(Display_ON_CTRL);
	_delay_ms(1);
	HLCD_vSendCommand(Display_Clear);
	_delay_ms(3);
	HLCD_vSendCommand(Entry_Mode_Set);
	_delay_ms(1);
}

void HLCD_vSendCommand  (u8 A_u8Command)
{
	/* control RS & RW PINS */
	MDIO_vWrtPinVal(LCD_CONTROL_PORT ,LCD_RS_PIN , DIO_LOW);
	MDIO_vWrtPinVal(LCD_CONTROL_PORT ,LCD_RW_PIN , DIO_LOW);

	/* write command on the data pins */
	MDIO_vWrtPortVal(LCD_DATA_PORT ,A_u8Command );

	/* pulse on the enable pin */
	MDIO_vWrtPinVal(LCD_CONTROL_PORT ,LCD_EN_PIN , DIO_HIGH);
	_delay_ms(1);
	MDIO_vWrtPinVal(LCD_CONTROL_PORT ,LCD_EN_PIN , DIO_LOW);
	_delay_ms(1);
}

void HLCD_vSendData (u8 A_u8data)
{
	/* control RS & RW PINS */
	MDIO_vWrtPinVal(LCD_CONTROL_PORT ,LCD_RS_PIN , DIO_HIGH);
	MDIO_vWrtPinVal(LCD_CONTROL_PORT ,LCD_RW_PIN , DIO_LOW);

	/* write command on the data pins */
	MDIO_vWrtPortVal(LCD_DATA_PORT ,A_u8data );

	/* pulse on the enable pin */
	MDIO_vWrtPinVal(LCD_CONTROL_PORT ,LCD_EN_PIN , DIO_HIGH);
	_delay_ms(1);
	MDIO_vWrtPinVal(LCD_CONTROL_PORT ,LCD_EN_PIN , DIO_LOW);
	_delay_ms(1);
}

void HLCD_vPrintString (char *A_charstring )
{
	while ( *A_charstring != '\0' )//check end of string
	{
		HLCD_vSendData(*A_charstring++);//Send Data then move pointer to the next Char
		_delay_ms(100);
	}
}

void HLCD_vPrintNumber (s32 A_s32Number)
{
	u8 L_u8Digits[10] = {0};
		u8 L_u8Counter = 0;
		/* TODO: IMplement negative number handling  	*/
		/* TODO: implement Zero in units corner case    */
		/* save reversed in array */
		while(A_s32Number > 0)
		{
			L_u8Digits[L_u8Counter] = A_s32Number%10 ;
			L_u8Counter++;
			A_s32Number /= 10 ;
		}

		/* print array in reverese  */
		for(s8 L_s8PrintIndex=0; L_s8PrintIndex >= 0; L_s8PrintIndex-- )
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
















