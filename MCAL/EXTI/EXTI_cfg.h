/*
 * EXTI_cfg.h
 *
 *  Created on: Jul 30, 2022
 *      Author: Lenovo
 */

#ifndef MCAL_EXTI_EXTI_CFG_H_
#define MCAL_EXTI_EXTI_CFG_H_

/////enable of the interrupt/////
/*
 * Options:
 * ENABLE,
 * DISABLE
 */
#define EXTI_LINE0  ENABLE
#define EXTI_LINE1  DISABLE
#define EXTI_LINE2  DISABLE


//////sense control//////
/*
 * Options:
 * EXTI_LowLevel,
 * EXTI_OnChange,
 * EXTI_FallingEdge,
 * EXTI_RisingEdge
 */
#define EXTI_LINE0_SENSE_CTRL  EXTI_LowLevel

/*
 * Options:
 * EXTI_LowLevel,
 * EXTI_OnChange,
 * EXTI_FallingEdge,
 * EXTI_RisingEdge
 */
#define EXTI_LINE1_SENSE_CTRL  EXTI_LowLevel

/*
 * Options:
 * EXTI_FallingEdge,
 * EXTI_RisingEdge
 */
#define EXTI_LINE2_SENSE_CTRL  EXTI_FallingEdge

#endif /* MCAL_EXTI_EXTI_CFG_H_ */
