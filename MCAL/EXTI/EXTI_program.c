/*
 * EXTI_program.c
 *
 *  Created on: Jul 30, 2022
 *      Author: SHA
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../DIO/DIO_interface.h"

#include "EXTI_interface.h"
#include "EXTI_register.h"
#include "EXTI_private.h"
#include "EXTI_cfg.h"


void MEXTI_vInit (void)
{
	#if EXTI_LINE0 == ENABLE
		/* step1 : sense control */
			/* Low Level For INT0 */
		#if EXTI_LINE0_SENSE_CTRL == EXTI_LowLevel
		CLR_BIT(MCUCR ,ISC00 );
		CLR_BIT(MCUCR ,ISC01 );
			/* On Change For INT0 */
		#elif EXTI_LINE0_SENSE_CTRL == EXTI_OnChange
		SET_BIT(MCUCR ,ISC00 );
		CLR_BIT(MCUCR ,ISC01 );
			/* Falling Edge For INT0 */
		#elif EXTI_LINE0_SENSE_CTRL == EXTI_FallingEdge
		CLR_BIT(MCUCR ,ISC00 );
		SET_BIT(MCUCR ,ISC01 );
			/* Rising Edge For INT0 */
		#elif EXTI_LINE0_SENSE_CTRL == EXTI_RisingEdge
		SET_BIT(MCUCR ,ISC00);
		SET_BIT(MCUCR ,ISC01);
		#else
		#error "Sense Control must be Low ,On Change ,Falling ,Rising ..."
		#endif

		/* step2 : enable interrupt */
	SET_BIT(GICR ,INT0);
	#endif

	#if EXTI_LINE1 == ENABLE
		/* step1 : sense control */
			/* Low Level For INT1 */
		#if EXTI_LINE1_SENSE_CTRL == EXTI_LowLevel
		CLR_BIT(MCUCR ,ISC10 );
		CLR_BIT(MCUCR ,ISC11 );
			/* On Change For INT1 */
		#elif EXTI_LINE1_SENSE_CTRL == EXTI_OnChange
		SET_BIT(MCUCR ,ISC10 );
		CLR_BIT(MCUCR ,ISC11 );
			/* Falling Edge For INT1 */
		#elif EXTI_LINE1_SENSE_CTRL == EXTI_FallingEdge
		CLR_BIT(MCUCR ,ISC10 );
		SET_BIT(MCUCR ,ISC11 );
			/* Rising Edge For INT1 */
		#elif EXTI_LINE1_SENSE_CTRL == EXTI_RisingEdge
		SET_BIT(MCUCR ,ISC10);
		SET_BIT(MCUCR ,ISC11);
		#else
		#error "Sense Control must be Low ,On Change ,Falling ,Rising ..."
		#endif
		/* step2 : enable interrupt */
		SET_BIT(GICR ,INT1);
	#endif

	#if EXTI_LINE2 == ENABLE
		/* step1 : sense control */
			/* Falling Edge For INT2 */
		#if EXTI_LINE2_SENSE_CTRL == EXTI_FallingEdge
		CLR_BIT(MCUCSR ,ISC2 );
			/* Rising Edge For INT2 */
		#elif EXTI_LINE2_SENSE_CTRL == EXTI_RisingEdge
		SET_BIT(MCUCSR ,ISC2 );
		#else
		#error "Sense Control must be Falling ,Rising ..."
		#endif
		/* step2 : enable interrupt */
		SET_BIT(GICR ,INT2);
	#endif
}

void MEXTI_vEnableInterrupt  (u8 A_u8ExtiLineNo)
{
	#if   EXTI_LINE0 == ENABLE
		SET_BIT(GICR ,INT0);
	#elif EXTI_LINE1 == ENABLE
		SET_BIT(GICR ,INT1);
	#elif EXTI_LINE2 == ENABLE
		SET_BIT(GICR ,INT2);
	#endif
}

void MEXTI_vDisableInterrupt (u8 A_u8ExtiLineNo)
{
	#if   EXTI_LINE0 == DISABLE
		SET_BIT(GICR ,INT0);
	#elif EXTI_LINE1 == DISABLE
		SET_BIT(GICR ,INT1);
	#elif EXTI_LINE2 == DISABLE
		SET_BIT(GICR ,INT2);
	#endif
}

void MEXTI_vSetSenseControl  (u8 A_u8ExtiLineNo ,u8 A_u8SenseControl)
{
	/////EXTI_LINE0
	#if A_u8ExtiLineNo == EXTI_LINE0
		#if  A_u8SenseControl == EXTI_LowLevel
		CLR_BIT(MCUCR ,ISC00 );
		CLR_BIT(MCUCR ,ISC01 );
			/* On Change For INT0 */
		#elif A_u8SenseControl == EXTI_OnChange
		SET_BIT(MCUCR ,ISC00 );
		CLR_BIT(MCUCR ,ISC01 );
			/* Falling Edge For INT0 */
		#elif A_u8SenseControl == EXTI_FallingEdge
		CLR_BIT(MCUCR ,ISC00 );
		SET_BIT(MCUCR ,ISC01 );
			/* Rising Edge For INT0 */
		#elif A_u8SenseControl == EXTI_RisingEdge
		SET_BIT(MCUCR ,ISC00);
		SET_BIT(MCUCR ,ISC01);
		#else
		#error "Sense Control must be Low ,On Change ,Falling ,Rising ..."
		#endif
	#endif

/////EXTI_LINE1
	#if A_u8ExtiLineNo == EXTI_LINE1
		/* step1 : sense control */
			/* Low Level For INT1 */
		#if A_u8SenseControl == EXTI_LowLevel
		CLR_BIT(MCUCR ,ISC10 );
		CLR_BIT(MCUCR ,ISC11 );
			/* On Change For INT1 */
		#elif A_u8SenseControl == EXTI_OnChange
		SET_BIT(MCUCR ,ISC10 );
		CLR_BIT(MCUCR ,ISC11 );
			/* Falling Edge For INT1 */
		#elif A_u8SenseControl == EXTI_FallingEdge
		CLR_BIT(MCUCR ,ISC10 );
		SET_BIT(MCUCR ,ISC11 );
			/* Rising Edge For INT1 */
		#elif A_u8SenseControl == EXTI_RisingEdge
		SET_BIT(MCUCR ,ISC10);
		SET_BIT(MCUCR ,ISC11);
		#else
		#error "Sense Control must be Low ,On Change ,Falling ,Rising ..."
		#endif
	#endif

/////EXTI_LINE2
	#if A_u8ExtiLineNo == EXTI_LINE2
		/* step1 : sense control */
			/* Falling Edge For INT2 */
		#if A_u8SenseControl == EXTI_FallingEdge
		CLR_BIT(MCUCSR ,ISC2 );
			/* Rising Edge For INT2 */
		#elif A_u8SenseControl == EXTI_RisingEdge
		SET_BIT(MCUCSR ,ISC2 );
		#else
		#error "Sense Control must be Falling ,Rising ..."
		#endif
	#endif

}
