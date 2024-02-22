/*
 * KPD_int.h
 *
 *  Created on: Jul 28, 2022
 *      Author: Lenovo
 */

#ifndef HAL_KPD_KPD_INT_H_
#define HAL_KPD_KPD_INT_H_

#define KPD_NOT_PRESSED 255

void HKPD_vInit(void);
u8 HKPD_u8GetPressedKey(void);

#endif /* HAL_KPD_KPD_INT_H_ */
