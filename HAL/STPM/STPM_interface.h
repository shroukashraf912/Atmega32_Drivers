/*
 * STPM_interface.h
 *
 *  Created on: Jul 28, 2022
 *      Author: Lenovo
 */

#ifndef HAL_STPM_STPM_INTERFACE_H_
#define HAL_STPM_STPM_INTERFACE_H_

void HSTPM_vInit       (void);
void HSTPM_vRotateCw   (u16 A_u16Angle);
void HSTPM_vRotateCcw  (u16 A_u16Angle);

void HSTPM_vRotateStepsCw   (u16 A_u16Steps);
void HSTPM_vRotateStepsCcw  (u16 A_u16Steps);

#endif /* HAL_STPM_STPM_INTERFACE_H_ */
