/*
 * SSD_private.h
 *
 *  Created on: Jul 9, 2022
 *  Author    : shrouk ashraf(SHA)
 *  Layer     : HAL
 *  SWC       : SSD(Seven Segment Display)
 */

#ifndef COTS_HAL_SSD_SSD_PRIVATE_H_
#define COTS_HAL_SSD_SSD_PRIVATE_H_

/*##################################################################################################################*/
/*Common Anode*/
#define SSD_ANODE_SEGMENT   {0b11000000/* 0 */,0b11111001/* 1 */,0b10100100/* 2 */,0b10110000/* 3 */,0b10011001 /* 4 */,0b10010010/* 5 */,0b10000010/* 6 */,0b11111000/* 7 */,0b10000000/* 8 */,0b10011000/* 9 */}
/*Common Cathod*/
#define SSD_CATHODE_SEGMENT {0b00111111/* 0 */,0b00000110/* 1 */,0b01011011/* 2 */,0b01001111/* 3 */,0b01100110/* 4 */,0b01101101/* 5 */,0b01111101/* 6 */,0b00000111/* 7 */,0b01111111/* 8 */,0b01101111/* 9 */}
/*##################################################################################################################*/
#define  SSD_PORT_HIGH  0xff
#endif /* COTS_HAL_SSD_SSD_PRIVATE_H_ */
