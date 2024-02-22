/*
 * ADC_interface.h
 *
 *  Created on: Sep 10, 2022
 *      Author: SHA
 */

#ifndef COTS_MCAL_ADC_ADC_INTERFACE_H_
#define COTS_MCAL_ADC_ADC_INTERFACE_H_

typedef enum
{
	ADC_CH0,
	ADC_CH1,
	ADC_CH2,
	ADC_CH3,
	ADC_CH4,
	ADC_CH5,
	ADC_CH6,
	ADC_CH7
}et_ADCChannels;

typedef enum
{
	ADC_Complete,
	ADC_Not_Complete
}et_FlagStatus;

/*intialization of ADC*/
void          MADC_vAdcInit           (void);
/*read adc from the required channel synchronous */
u16           MADC_u16ReadAnalogValue (u8 Copy_u8AdcChannelId);
/* interrupt based APIS */
void          MADC_vStartConversion   (u8 Copy_u8AdcChannelId);
/* Asynchronous */
u16           MADC_u16GetAdcData      (void);
void          MADC_vSetCallBack       (void (*A_vfptr) (void));

/* Alternative Method :*/
void MADC_vStartADCConversion_Asynch (u8 Copy_u8AdcChannelId ,
									  u16 *Copy_pu16ADCData  ,
									  void (*A_vfptr) (void));


et_FlagStatus MADC_u8GetFlagStatus    (void);
#endif /* COTS_MCAL_ADC_ADC_INTERFACE_H_ */
