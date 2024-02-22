/*
 * ADC_program.c
 *
 *  Created on: Sep 10, 2022
 *      Author: SHA
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"


#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"

/* HOW TO MAKE CALLBACK MAGANIZM?
 * 1- declaration global function to pointer (because it is shared between (SetcallBack & ISR)
 * 2- implement two function (
 * 					1- ISR & make in it callback
 * 					2- Set CallBack (that i give the addresses of the functions )
 */

void (*ADC_CallBack) (void);

void (*ADC_CallBack_2) (u16  A_u16ADC_Data);
u16 *G_pu16ADC_Data;
et_FlagStatus xAdcFlag = ADC_Not_Complete ;

void MADC_vAdcInit (void)
{
		/* 1- Reference voltage selection */
#if   ADC_REFERANCE_VOLATAGE == ADC_AVCC_REFERANCE_VOLTAGE
	CLR_BIT(ADMUX ,REFS1);
	SET_BIT(ADMUX ,REFS0);
#elif ADC_REFERANCE_VOLATAGE == ADC_V_REFERANCE_VOLTAGE
	CLR_BIT(ADMUX ,REFS1);
	CLR_BIT(ADMUX ,REFS0);
#endif
		/* 2- Data Adjustment direction (right/left) */
#if   ADC_SET_ADJUSTMENT == ADC_RIGHT_ADJUSTMENT
	CLR_BIT(ADMUX ,ADLAR);
#elif ADC_SET_ADJUSTMENT == ADC_LEFT_ADJUSTMENT
	SET_BIT(ADMUX ,ADLAR);
#endif
		/* 3- Select presacaler bits */
	ADCSRA = (ADCSRA & ADC_BIT_MASKING_PRESCALAR) | (MADC_SET_PPRESCALAR) ;
		/* 4- Auto Trigger enable */
			/* 4.a- Select Auto trigger source */
	CLR_BIT(ADCSRA ,ADATE );
		/* 5- Interrupt (Enable / Disable )*/
#if  ADC_INTERRUPT_ENABLE == Enable
	SET_BIT(ADCSRA ,ADIE);
#else
	CLR_BIT(ADCSRA ,ADIE);
#endif
		/* 6- Enable ADC peripheral */
#if ADC_ENABLE == Enable
	SET_BIT(ADCSRA ,ADEN);
#else
	CLR_BIT(ADCSRA ,ADEN);
#endif
}
u16  MADC_u16ReadAnalogValue (u8 Copy_u8AdcChannelId)
{
	/* 1- Select the Channel Id*/
	ADMUX = (ADMUX & ADC_BIT_MASKING_CHANNEL) | (Copy_u8AdcChannelId & ADC_BIT_MASKING_REG_CHANNEL);
	/* 2- Start Conversion */
	SET_BIT(ADCSRA ,ADSC);
	/* 3- Poll on Flag ( Conversion complete flag )*/
	while (GET_BIT(ADCSRA ,ADIF ) != 1);
	/* 4- Clear Flag */
	SET_BIT(ADCSRA ,ADIF);
	/* 5- Return ADC Data */
	return ADC;
}

/* ASYNCHROUNOUS FUNCTIONS */
void MADC_vStartConversion (u8 Copy_u8AdcChannelId)
{
	/* 1- Select the Channel Id*/
	ADMUX = (ADMUX & ADC_BIT_MASKING_CHANNEL) | (Copy_u8AdcChannelId & ADC_BIT_MASKING_REG_CHANNEL);
	/* 2- Start Conversion */
	SET_BIT(ADCSRA ,ADSC);
}

//to receive the data in the ISR
u16 MADC_u16GetAdcData (void)
{
	/* 5- Return ADC Data */
	return ADC;

}

et_FlagStatus MADC_u8GetFlagStatus    (void)
{

	if (GET_BIT(ADCSRA ,ADIF) == 1)
	{
		 xAdcFlag = ADC_Complete;
	}
	return xAdcFlag;
}

void MADC_vSetCallBack (void (*A_vfptr) (void))
{
	ADC_CallBack = A_vfptr;
}


void MADC_vStartADCConversion_Asynch (u8 Copy_u8AdcChannelId ,
									  u16 *Copy_pu16ADCData  ,
									  void (*A_vfptr) (void))
{
	/* 1- Set callback function pointer */
	ADC_CallBack = A_vfptr;
	/* 2- set ADC data pointer (asign pointer to pointer not use data)*/
	G_pu16ADC_Data = Copy_pu16ADCData;

	/* 1- Select the Channel Id*/
	ADMUX = (ADMUX & ADC_BIT_MASKING_CHANNEL) | (Copy_u8AdcChannelId & ADC_BIT_MASKING_REG_CHANNEL);
	/* 2- Start Conversion */
	SET_BIT(ADCSRA ,ADSC);


}



/* ADC ISR*/
void __vector_16(void) __attribute__((signal));
void __vector_16(void)
{
	if (G_pu16ADC_Data != NULL)
	{
		*G_pu16ADC_Data = ADC ;
	}
	if (ADC_CallBack   != NULL)
	{
		ADC_CallBack();
//		ADC_CallBack_2(ADC);
	}
	//to return start conversion
	 xAdcFlag = ADC_Complete;
}








