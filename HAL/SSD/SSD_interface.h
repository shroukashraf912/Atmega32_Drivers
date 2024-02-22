/*
 * SSD_interface.h
 *
 *  Created on: Jul 9, 2022
 *  Author    : shrouk ashraf(SHA)
 *  Layer     : HAL
 *  SWC       : SSD(Seven Segment Display)
 */

#ifndef HAL_SSD_SSD_INTERFACE_H_
#define HAL_SSD_SSD_INTERFACE_H_

//DEFINE THE SEGMENT


#define SSD_PORTA DIO_PORTA
#define SSD_PORTB DIO_PORTB
#define SSD_PORTC DIO_PORTC
#define SSD_PORTD DIO_PORTD

#define SSD_PIN0  DIO_PIN0
#define SSD_PIN1  DIO_PIN1
#define SSD_PIN2  DIO_PIN2
#define SSD_PIN3  DIO_PIN3
#define SSD_PIN4  DIO_PIN4
#define SSD_PIN5  DIO_PIN5
#define SSD_PIN6  DIO_PIN6
#define SSD_PIN7  DIO_PIN7


#define SSD_COMMON_ANODE   1
#define SSD_COMMON_CATHODE 2

#define SSD_TYPE COMMON_ANODE


typedef struct{

	u8 ID         ;                 // SSD_COMMON_CATHODE or SSD_COMMON_ANODE
	u8 DataPort   ;                 // SSD_PORTA or SSD_PORTB or SSD_PORTC or SSD_PORTD
	u8 EnablePort ;                 // SSD_PORTA or SSD_PORTB or SSD_PORTC or SSD_PORTD
	u8 EnablePin  ;                 // SSD_PIN0 , SSD_PIN1 ,SSD_PIN2 , SSD_PIN3 , SSD_PIN4 , SSD_PIN5 , SSD_PIN6 , SSD_PIN7

}SSD_Type;

/* choose the segment */
void HSSD_vIntial  (SSD_Type A_StSsdConfiguration);

/* wrt the num */
void HSSD_vDispNum (SSD_Type A_StSsdConfiguration,u8 A_u8Num);
void HSSD_vTurnOn  (SSD_Type A_StSsdConfiguration);
/* to turn off */
void HSSD_vTurnOff (SSD_Type A_StSsdConfiguration);


#endif /* HAL_SSD_SSD_INTERFACE_H_ */
