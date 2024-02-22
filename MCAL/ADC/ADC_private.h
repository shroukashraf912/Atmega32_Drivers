/*
 * ADC_private.h
 *
 *  Created on: Sep 10, 2022
 *      Author: SHA
 */

#ifndef COTS_MCAL_ADC_ADC_PRIVATE_H_
#define COTS_MCAL_ADC_ADC_PRIVATE_H_

#define ADMUX    (*(volatile u8*) (0x27))
#define ADCSRA   (*(volatile u8*) (0x26))
#define ADCH     (*(volatile u8*) (0x25))
#define ADCL     (*(volatile u8*) (0x24))
#define ADC      (*(volatile u16*)(0x24))
#define SIFOR    (*(volatile u8*) (0x50))


/* Bits of ADMUX */
#define  MUX0  0
#define  MUX1  1
#define  MUX2  2
#define  MUX3  3
#define  MUX4  4
#define  ADLAR 5
#define  REFS0 6
#define  REFS1 7


/* Bits of ADCSRA */
#define  ADPS0 0
#define  ADPS1 1
#define  ADPS2 2
#define  ADIE  3
#define  ADIF  4
#define  ADATE 5
#define  ADSC  6
#define  ADEN  7


/*MADC_SET_REFERANCE_VOLATAGEoptions:*/
#define ADC_AVCC_REFERANCE_VOLTAGE  1
#define ADC_V_REFERANCE_VOLTAGE     2

/*MADC Prescaler options:*/
#define MADC_2_PRESCALER   0b000
#define MADC_4_PRESCALER   0b010
#define MADC_8_PRESCALER   0b011
#define MADC_16_PRESCALER  0b100
#define MADC_32_PRESCALER  0b101
#define MADC_64_PRESCALER  0b110
#define MADC_128_PRESCALER 0b111

#define ADC_LEFT_ADJUSTMENT   1
#define ADC_RIGHT_ADJUSTMENT  0

#define ADC_BIT_MASKING_PRESCALAR    0xF8
#define ADC_BIT_MASKING_CHANNEL      0xE0
#define ADC_BIT_MASKING_REG_CHANNEL  0x07

/* interrupt of ADC */
#define Enable  1
#define Disable 0

#endif /* COTS_MCAL_ADC_ADC_PRIVATE_H_ */


