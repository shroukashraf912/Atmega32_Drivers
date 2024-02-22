/*

 * STPM_program.c
 *
 *  Created on: Jul 28, 2022
 *      Author: SHA
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "STPM_interface.h"
#include "STPM_configuration.h"

void HSTPM_vInit       (void)
{
	MDIO_vWrtPinDir(STPM_PORT ,STPM_PIN_B ,DIO_PIN_OUTPUT );
	MDIO_vWrtPinDir(STPM_PORT ,STPM_PIN_P ,DIO_PIN_OUTPUT );
	MDIO_vWrtPinDir(STPM_PORT ,STPM_PIN_Y ,DIO_PIN_OUTPUT );
	MDIO_vWrtPinDir(STPM_PORT ,STPM_PIN_O ,DIO_PIN_OUTPUT );
}

void HSTPM_vRotateCw   (u16 A_u16Angle)
{

}

void HSTPM_vRotateCcw  (u16 A_u16Angle)
{

}

void HSTPM_vRotateStepsCw   (u16 A_u16Steps)
{

}

void HSTPM_vRotateStepsCcw  (u16 A_u16Steps)
{

}


