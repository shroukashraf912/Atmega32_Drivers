/*
 * SW_interface.h
 *
 *  Created on: Aug 20, 2023
 *  Author     : Shrouk Ashraf (SHA)
 *  Layer      : HAL
 *  SWC        : Switch(SW)
 */

#ifndef COTS_HAL_SW_SW_INTERFACE_H_
#define COTS_HAL_SW_SW_INTERFACE_H_

/*#####################################################################*/
/* >>>Switch Status<<< */
#define SW_PRESSED  1
#define SW_NOT_PRESSED  0
/*#####################################################################*/
/* >>>Options of State<<< */
#define SW_INTERNAL_PULL_UP    0
#define SW_EXTERNAL_PULL_UP    1
#define SW_EXTERNAL_PULL_DOWN  2
#define SW_FLOATING            3
/*#####################################################################*/
/* >>>Switch Configurations<<< */
typedef struct
{
	u8 SW_Port;
	u8 SW_Pin;
	u8 Pull_State
}SW_Type;
/*#####################################################################*/
void HSW_vInit(SW_Type A_stSwConfig);
u8   HSW_u8GetPressedSwitch(SW_Type A_stSwConfig);
/*#####################################################################*/


#endif /* COTS_HAL_SW_SW_INTERFACE_H_ */
