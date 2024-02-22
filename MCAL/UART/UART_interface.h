/*
 * UART_interface.h
 *
 *  Created on: Jul 26, 2023
 *      Author: SHA
 */

#ifndef COTS_MCAL_UART_UART_INTERFACE_H_
#define COTS_MCAL_UART_UART_INTERFACE_H_

#define UART_TX_COMPLETE  1
#define UART_RX_COMPLETE  2
#define UART_UDR_EMPTY    3

void MUART_vInit (void);
void MUART_vTransmitAsyn (u16 A_u16data);
u16  MUART_u16ReceiverAsyn(void);


//want to implemented
void MUART_vSendString(char *A_u8str);
void MUART_vSendNumber(s32 Num);
void MUART_vReceiveString(char A_u8str[],u32 A_u32size);

/* Interrupt APIs */
void MUART_vEnableInterrupt (u8 A_u8InterruptSource);
void MUART_vDisableInterrupt (u8 A_u8InterruptSource);

void MUART_vTransmit_Asynch(char A_xStr[],u16 A_u16Size,void (*Func_CallBack_Ptr)(void));
void MUART_vReceive_Asynch(char A_xBuffer[],u16 A_u16Size,void (*Func_CallBack_Ptr)(void));


void MUART_vTransmitDataSynch (u16 A_u16Data);
u16  MUART_u16RecieveSynch (void);

#endif /* COTS_MCAL_UART_UART_INTERFACE_H_ */
