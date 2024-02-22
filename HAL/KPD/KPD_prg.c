/*

 * KPD_prg.c
 *
 *  Created on: Jul 28, 2022
 *      Author: SHA
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include <util/delay.h>

#include "../../MCAL/DIO/DIO_interface.h"
#include "KPD_int.h"
#include "KYD_cfg.h"



static const u8 global_Au8_SwitchVal[ROW_SIZE][COL_SIZE] =
{
	{
		0x07, /* Row 0 Column 0 */
		0x04, /* Row 1 Column 0 */
		0x01, /* Row 2 Column 0 */
		0x0A  /* Row 3 Column 0 */
	},
	{
		0x08, /* Row 0 Column 1 */
		0x05, /* Row 1 Column 1 */
		0x02, /* Row 2 Column 1 */
		0x00  /* Row 4 Column 1 */
	},
	{
		0x09, /* Row 0 Column 2 */
		0x06, /* Row 1 Column 2 */
		0x03, /* Row 2 Column 2 */
		0x0B  /* Row 3 Column 2 */
	},
	{
		0x01, /* Row 0 Column 3 */
		0x05, /* Row 1 Column 3 */
		0x09, /* Row 2 Column 3 */
		0x0D  /* Row 3 Column 3 */
	}
};

void HKPD_vInit(void)
{
	/* Set Columns as Output & High */
	for (u8 local_u8_PinID = COL_START; local_u8_PinID <= COL_END; local_u8_PinID++) {
		MDIO_vWrtPinDir(KPD_PORT, local_u8_PinID, DIO_PIN_OUTPUT);
		MDIO_vWrtPinVal(KPD_PORT, local_u8_PinID, DIO_HIGH);
	}
	/* Set Rows as Inputs & Pulled up */
	for (u8 local_u8_PinID = ROW_START; local_u8_PinID <= ROW_END; local_u8_PinID++) {
		MDIO_vWrtPinDir(KPD_PORT, local_u8_PinID, DIO_PIN_INPUT);
		MDIO_vWrtPinVal(KPD_PORT, local_u8_PinID, DIO_HIGH);
	}
}

u8 HKPD_u8GetPressedKey(void)
{
	u8 local_u8_Column, local_u8_Row, local_u8_PinVal;

	/* A- Initialize the switch status to NOT Pressed as a default value */
	u8 local_u8_PressedKey = KPD_NOT_PRESSED;

	/* B- Looping on columns of the Key Pad */
	for (local_u8_Column = COL_START; local_u8_Column <= COL_END; local_u8_Column++) {
		/* 1- Activate the Column */
		MDIO_vWrtPinVal(KPD_PORT, local_u8_Column, DIO_LOW);

		/* 2- Loop on the rows of the Key Pad */
		for (local_u8_Row = ROW_START; local_u8_Row <= ROW_END; local_u8_Row++) {
			/* Check the status of the switch */
			local_u8_PinVal = MDIO_u8GetPinVal(KPD_PORT, local_u8_Row);
			if (local_u8_PinVal == 0) {
				/* a- Get the value of the currently pressed switch */
				local_u8_PressedKey = global_Au8_SwitchVal[local_u8_Column - COL_START][local_u8_Row - ROW_START];

				/* b- Wait until the switch is released (Single Press) */
				while (local_u8_PinVal == 0) {
					local_u8_PinVal = MDIO_u8GetPinVal(KPD_PORT, local_u8_Row);
				}

				/* c- Delay to avoid bouncing */
				_delay_ms(20);
			}
		}

		/* 3- Deactivate the Column */
		MDIO_vWrtPinVal(KPD_PORT, local_u8_Column, DIO_HIGH);
	}

	/* C- Returning the value */
	return local_u8_PressedKey;
}


