/*
 * DCM_
interface.h
 *
 *  Created on: Jul 27, 2022
 *      Author: SHA
 */

#ifndef HAL_DCM_DCM_INTERFACE_H_
#define HAL_DCM_DCM_INTERFACE_H_

typedef struct
{
	u8 port;
	u8 pin1;
	u8 pin2;
}DCM_Type;

#define NOSTRUCT  0
#define STRUCT    1
#define METHOD    STRUCT


#if METHOD == NOSTRUCT
void HDCM_vInit      (void);
void HDCM_vRotateCW  (void);  /* TODO: implement speed as input*/
void HDCM_vRotateCCW (void);  /* TODO: implement speed as input*/
void HDCM_vStop      (void);
#endif

#if METHOD == STRUCT
DCM_Type HDCM_xInit       (u8 A_u8port ,u8 A_u8pin1 ,u8 A_u8pin2);
void     HDCM_vSRotateCW  (DCM_Type* A_xMotor);  /* TODO: implement speed as input*/
void     HDCM_vSRotateCCW (DCM_Type* A_xMotor);  /* TODO: implement speed as input*/
void     HDCM_vSStop      (DCM_Type* A_xMotor);
#endif

#endif /* HAL_DCM_DCM_INTERFACE_H_ */
