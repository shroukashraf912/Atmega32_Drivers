/*

 * DIP_interface.h
 *
 *  Created on: Jul 31, 2022
 *      Author: SHA
 */

#ifndef HAL_DIP_DIP_INTERFACE_H_
#define HAL_DIP_DIP_INTERFACE_H_

#define NO_OfDipPins 8
#define DIO_PIN0 0
#define DIO_PIN7 7

void HDIP_vInit (void);
u8   HDIP_u8GetValue (u8 *A_u8PValOfDip);

#endif /* HAL_DIP_DIP_INTERFACE_H_ */
