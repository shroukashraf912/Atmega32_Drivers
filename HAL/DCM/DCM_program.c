/*
 * DCM_progr
am.c
 *
 *  Created on: Jul 27, 2022
 *      Author: SHA
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "DCM_interface.h"
#include "DCM_configuration.h"

void HDCM_vInit(void)
{
	MDIO_vWrtPinDir(DCM_PORT ,DCM_PIN1 ,DIO_PIN_OUTPUT);
	MDIO_vWrtPinDir(DCM_PORT ,DCM_PIN2 ,DIO_PIN_OUTPUT);

	/* TODO: setup speed control pin */
}

void HDCM_vRotateCW(void)
{
	/* TODO: implement speed as input*/

	MDIO_vWrtPinVal(DCM_PORT ,DCM_PIN1 ,DIO_HIGH);
	MDIO_vWrtPinVal(DCM_PORT ,DCM_PIN2 ,DIO_LOW);
}

void HDCM_vRotateCCW(void)
{
	/* TODO: implement speed as input*/

	MDIO_vWrtPinVal(DCM_PORT ,DCM_PIN1 ,DIO_LOW);
	MDIO_vWrtPinVal(DCM_PORT ,DCM_PIN2 ,DIO_HIGH);
}

void HDCM_vStop(void)
{
	MDIO_vWrtPinVal(DCM_PORT ,DCM_PIN1 ,DIO_LOW);
	MDIO_vWrtPinVal(DCM_PORT ,DCM_PIN2 ,DIO_LOW);
}

void HDCM_vSRotateCW(DCM_Type* A_xMotor)
{
	/* TODO: implement speed as input*/
	MDIO_vWrtPinVal(A_xMotor -> port ,A_xMotor -> pin1 ,DIO_HIGH);
	MDIO_vWrtPinVal(A_xMotor -> port ,A_xMotor -> pin2 ,DIO_LOW);

}
void HDCM_vSRotateCCW(DCM_Type* A_xMotor)
{
	/* TODO: implement speed as input*/
	MDIO_vWrtPinVal(A_xMotor -> port ,A_xMotor -> pin1 ,DIO_LOW);
	MDIO_vWrtPinVal(A_xMotor -> port ,A_xMotor -> pin2 ,DIO_HIGH);
}
void HDCM_vSStop(DCM_Type* A_xMotor)
{
	MDIO_vWrtPinVal(A_xMotor -> port ,A_xMotor -> pin1 ,DIO_LOW);
	MDIO_vWrtPinVal(A_xMotor -> port ,A_xMotor -> pin2 ,DIO_LOW);
}

DCM_Type HDCM_xInit(u8 A_u8port ,u8 A_u8pin1 ,u8 A_u8pin2)
{
	DCM_Type L_xNewMotor;

	L_xNewMotor.port = A_u8port;
	L_xNewMotor.pin1 = A_u8pin1;
	L_xNewMotor.pin2 = A_u8pin2;

	return L_xNewMotor;
}
