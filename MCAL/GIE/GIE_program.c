/*
 * GIE_program.c
 *
 *  Created on: Jul 30, 2022
 *      Author: Lenovo
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "GIE_interface.h"
#include "GIE_register.h"
#include "GIE_private.h"
#include "GIE_cfg.h"

void MGIE_vEnableGlobalInterrupt (void)
{
	SET_BIT(SREG ,I);
}
void MGIE_vDisableGlobalInterrupt (void)
{
	CLR_BIT(SREG ,I);
}


