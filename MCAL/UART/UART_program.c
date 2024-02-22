/*
 * UART_program.c
 *
 *  Created on : July 26, 2023
 *  Author     : Shrouk Ashraf
 *  Version    : V1
 *  Layer      : MCAL
 *  SWC        : UART
 */

/*##################################################################################################################*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../DIO/DIO_interface.h"
#include "../GIE/GIE_interface.h"
#include "UART_interface.h"
#include "UART_register.h"
#include "UART_private.h"
#include "UART_configure.h"
/*##################################################################################################################*/

/* HOW TO MAKE CALLBACK MAGANIZM?
 * 1- declaration global function to pointer (because it is shared between (SetcallBack & ISR)
 * 2- implement two function (
 * 					1- ISR & make in it callback
 * 					2- Set CallBack (that i give the addresses of the functions )
 */

/*##################################################################################################################*/
/* Global Variables */
static void (*GS_TXC_CallBack)      (void) ;
static void (*GS_RXC_CallBack)      (void) ;
static void (*GS_UDR_EMPTY_CallBack)(void) ;

static char  *GS_pu8InternalTxBuffer       ;
static u16    GS_u16TxBufferCounter = 0    ;
static u16    GS_u16TxBufferSize    = 0    ;

static char  *GS_pu8InternalRxBuffer       ;
static u16    GS_u16RxBufferCounter = 0	   ;
static u16    GS_u16RxBufferSize    = 0	   ;
/*##################################################################################################################*/

/*
 ****************************************************************************************
 * Function_Name ==>   MUART_vInit()
 * Description   ==>   function used to enable the USART internal circuit of AVR Atmega32
 * 						-Set the transmitter & Receiver pins of Atmega32
 * 						-Set the transmitter & Receiver in UCSRB registers
 * 						- Configure Frame Format:
 * 							-> Asynchronous & synchronous
 * 							-> Data Size (5,6,7,8,9)
 *  						-> Parity Check (Even or Odd or None)
 *  						-> Stop bit (1,2 bits)
 *  					-Baud Rate
 *  Arguments   ==>    void
 *  Return      ==>    void
 ****************************************************************************************
*/
void MUART_vInit (void)
{

	u8 L_u8TempUCSRB = 0;
	u8 L_u8TempUCSRC = 0;

//	MGIE_vDisableGlobalInterrupt();

	/*1- Set the transmitter & Receiver pins of Atmega32*/
	MDIO_vWrtPinDir(UART_PORT,Rx_PIN,DIO_PORT_INPUT);
	MDIO_vWrtPinDir(UART_PORT,Tx_PIN,DIO_PORT_OUTPUT);


	/* 2- Set the transmitter & Receiver in UCSRB register TxE & RxE*/
		//Transmitter
	SET_BIT(L_u8TempUCSRB , TXEN);
		//Receiver
	SET_BIT(L_u8TempUCSRB , RXEN);


	/* 3- Configure Frame Format:
	 *  - Asynchronous
	 *  - Data Size
	 *  - Parity Check
	 *  - Stop bit
	 *
	 */
    	//0- Register select
	SET_BIT(L_u8TempUCSRC,URSEL);

		//1- Asynchronous
	#if MODE_SELECT == ASYNCHRONOUS
		CLR_BIT(L_u8TempUCSRC,UMSEL);
	#else
		SET_BIT(L_u8TempUCSRC,UMSEL);
	#endif
		//2- Data Size 8
	#if DATA_SIZE == BIT_5
		CLR_BIT(L_u8TempUCSRC ,UCSZ0);
		CLR_BIT(L_u8TempUCSRC ,UCSZ1);
		CLR_BIT(L_u8TempUCSRB ,UCSZ2);
	#elif DATA_SIZE == BIT_6
		SET_BIT(L_u8TempUCSRC ,UCSZ0);
		CLR_BIT(L_u8TempUCSRC ,UCSZ1);
		CLR_BIT(L_u8TempUCSRB ,UCSZ2);
	#elif DATA_SIZE == BIT_7
		CLR_BIT(L_u8TempUCSRC ,UCSZ0);
		SET_BIT(L_u8TempUCSRC ,UCSZ1);
		CLR_BIT(L_u8TempUCSRB ,UCSZ2);
	#elif DATA_SIZE == BIT_8
		SET_BIT(L_u8TempUCSRC ,UCSZ0);
		SET_BIT(L_u8TempUCSRC ,UCSZ1);
		CLR_BIT(L_u8TempUCSRB ,UCSZ2);
	#elif DATA_SIZE == BIT_9
		SET_BIT(L_u8TempUCSRC ,UCSZ0);
		SET_BIT(L_u8TempUCSRC ,UCSZ1);
		SET_BIT(L_u8TempUCSRB ,UCSZ2);
	#endif
		//3- Parity Check
	#if PARITY_CHECk == DISABLE
		CLR_BIT(L_u8TempUCSRC ,UPM0);
		CLR_BIT(L_u8TempUCSRC ,UPM1);
	#elif PARITY_CHECk == ENABLE
		switch (PARITY_MODE)
		{
			case EVEN:
				CLR_BIT(L_u8TempUCSRC ,UPM0);
				SET_BIT(L_u8TempUCSRC ,UPM1);
				break;
			case ODD:
				SET_BIT(L_u8TempUCSRC ,UPM0);
				SET_BIT(L_u8TempUCSRC ,UPM1);
		}
	#endif


		//4- stop bit
	#if STOP_BIT == TWO_BIT
		SET_BIT(L_u8TempUCSRC ,USBS);
	#else
		CLR_BIT(L_u8TempUCSRC ,USBS);
	#endif

	UCSRB = L_u8TempUCSRB;
	UCSRC = L_u8TempUCSRC;


	/* 4- Set the Baud Rate */
	/* ACCORDING TO BAUD RATE 9600 UBRR = 51 */
	UBRRL = UBRR_Baud_Rate;
}

/*##################################################################################################################*/

/*
 ****************************************************************************************
 * Function_Name ==>   MUART_vTransmitAsyn(A_u16data)
 * Description   ==>   function used to transmit Asynchronous Data in UART in UDR REG
 *  Arguments   ==>    u16 A_u16data
 *  Return      ==>    void
 ****************************************************************************************
*/

void MUART_vTransmitAsyn (u16 A_u16data)
{
	//Wait for Empty Transmit buffer
	while(GET_BIT(UCSRA,UDRE)==0);
	//put Data into buffer , Send the Data
	UDR = A_u16data;
/*
    //Wait for empty transmit buffer
	while ( !( UCSRA & (1<<UDRE)) );//0
	//Put data into buffer, sends the data
	UDR = A_u16data;
*/
}


/*##################################################################################################################*/

/*
 *************************************************************************************************
 * Function_Name ==>   MUART_u16ReceiverAsyn()
 * Description   ==>   function used to Receive Asynchronous Data in UART & store them in UDR REG
 *  Arguments   ==>    void
 *  Return      ==>    u16
 *************************************************************************************************
*/


u16  MUART_u16ReceiverAsyn(void)
{
	/* Wait for data to be received */
	while(GET_BIT(UCSRA,RXC)!=1);
	/*Get and Return Received data from buffer*/
	return UDR;
/*
	// Wait for data to be received
	while ( !(UCSRA & (1<<RXC)) )
	;
	// Get and return received data from buffer
	return UDR;
*/
}

/*##################################################################################################################*/

/*
 *************************************************************************************************
 * Function_Name ==>   MUART_vSendString(A_u8str[])
 * Description   ==>   function used to send string Data in UART & store them in UDR REG
 *  Arguments   ==>    char* str
 *  Return      ==>    void
 *************************************************************************************************
*/

void MUART_vSendString(char *A_u8str)
{

//	for (u32  i=0;A_u8str[i]!=NULL;i++)
//	{
//		MUART_vTransmitAsyn(A_u8str[i]);
//	}

	/* "*MOVEright*" */
	while(*A_u8str != 0)
	{
		MUART_vTransmitAsyn(*A_u8str);
		A_u8str++;
	}


}

/*##################################################################################################################*/

/*
 *************************************************************************************************
 * Function_Name ==>   MUART_vReceiveString(A_u8str[],A_u32size)
 * Description   ==>   function used to Receive string Data in UART & store them in UDR REG
 *  Arguments   ==>    u8 A_u8str[],u32 A_u32size
 *  Return      ==>    void
 *************************************************************************************************
*/
void MUART_vReceiveString(char A_u8str[],u32 A_u32size)
{
	for (u32 i=0; i<A_u32size ;i++)
	{
		A_u8str[i]=MUART_u16ReceiverAsyn();
		if(A_u8str[i] == '\n' || A_u8str[i] == '\r')
		{
			A_u8str[i]='\0';
			break;
		}
		A_u8str[A_u32size-1] = '\0';
	}
}

/*##################################################################################################################*/
/*
 ****************************************************************************************
 * Function_Name ==>   MUART_vEnableInterrupt(A_u8InterruptSource)
 * Description   ==>   function used to enable the Interrupt
 *  Arguments   ==>    u8 A_u8InterruptSource
 *  Return      ==>    void
 ****************************************************************************************
*/
void MUART_vEnableInterrupt (u8 A_u8InterruptSource)
{
	switch(A_u8InterruptSource)
	{
		case UART_TX_COMPLETE:
			SET_BIT(UCSRB,TXCIE);
			break;
		case UART_RX_COMPLETE:
			SET_BIT(UCSRB,RXCIE);
			break;
		case UART_UDR_EMPTY:
			SET_BIT(UCSRB,UDRIE);
			break;
	}
}
/*##################################################################################################################*/
/*
 ****************************************************************************************
 * Function_Name ==>   MUART_vDisableInterrupt(A_u8InterruptSource)
 * Description   ==>   function used to disable the Interrupt
 *  Arguments   ==>    u8 A_u8InterruptSource
 *  Return      ==>    void
 ****************************************************************************************
*/
void MUART_vDisableInterrupt (u8 A_u8InterruptSource)
{

	switch(A_u8InterruptSource)
	{
		case UART_TX_COMPLETE:
			CLR_BIT(UCSRB,TXCIE);
			break;
		case UART_RX_COMPLETE:
			CLR_BIT(UCSRB,RXCIE);
			break;
		case UART_UDR_EMPTY:
			CLR_BIT(UCSRB,UDRIE);
			break;
	}
}
/*##################################################################################################################*/
/*
 ****************************************************************************************
 * Function_Name ==>   MUART_vTransmit_Asynch(A_xStr[], A_u16Size,Func_CallBack_Ptr)
 * Description   ==>   function used to transmit Asynchronous Data in UART in UDR REG by using Interrupt
 *  Arguments   ==>    char A_xStr[],u16 A_u16Size,void (*Func_CallBack_Ptr)(void)
 *  Return      ==>    void
 ****************************************************************************************
*/
void MUART_vTransmit_Asynch(char A_xStr[],u16 A_u16Size,void (*Func_CallBack_Ptr)(void))
{
	/* 1- Set CallBack */
	GS_TXC_CallBack = Func_CallBack_Ptr;
	/* 2- send The string to the internal buffer that will send by ISR*/
	GS_pu8InternalTxBuffer = A_xStr;
	/* 3- Check The size of the buffer */
	GS_u16TxBufferSize = A_u16Size;
	/* 4- Enable Interrupt */
	MUART_vEnableInterrupt(UART_TX_COMPLETE);
	/* 5- A_xStr ==> Send first Byte To start Communication
	 * and The Call back Will Continue Sending all other bytes */
	UDR = A_xStr[0];
	GS_u16RxBufferCounter++;
//	else
//	{
//		/* Return error Status to check if the transmission
//		 * started successfully */
//	}

}
/*##################################################################################################################*/
/*
 ****************************************************************************************
 * Function_Name ==>   MUART_vReceive_Asynch(A_xStr[], A_u16Size,Func_CallBack_Ptr)
 * Description   ==>   function used to Rececive Asynchronous Data by UART from UDR REG by using Interrupt
 *  Arguments   ==>    char A_xStr[],u16 A_u16Size,void (*Func_CallBack_Ptr)(void)
 *  Return      ==>    void
 ****************************************************************************************
*/
void MUART_vReceive_Asynch(char A_xBuffer[],u16 A_u16Size,void (*Func_CallBack_Ptr)(void))
{
	/* 1- Set CallBack */
	GS_RXC_CallBack= Func_CallBack_Ptr;
	/* 2- Receive The string to the internal buffer that will send by ISR*/
	GS_pu8InternalRxBuffer = A_xBuffer;
	/* 3- Check The size of the buffer */
	GS_u16RxBufferSize = A_u16Size;
	MUART_vEnableInterrupt(UART_RX_COMPLETE);
}



/*##################################################################################################################*/

/*
14  USART, RXC USART, Rx Complete
15  USART, UDRE USART Data Register Empty
16  USART, TXC USART, Tx Complete
*/
/*USART, RXC USART, Rx Complete*/
void __vector_13(void) __attribute__((signal));
void __vector_13(void)
{
	if (GS_RXC_CallBack != NULL)
	{
		GS_RXC_CallBack();
	}
	if(GS_u16RxBufferCounter < GS_u16RxBufferSize)
	{
		if(GS_pu8InternalRxBuffer[GS_u16RxBufferCounter] != '\n' ||
		   GS_pu8InternalRxBuffer[GS_u16RxBufferCounter] != '\r')
		{
			GS_pu8InternalRxBuffer[GS_u16RxBufferCounter]=UDR;
			GS_u16RxBufferCounter++;
		}
		else
		{
			GS_pu8InternalRxBuffer[GS_u16RxBufferCounter]='\0';
			MUART_vDisableInterrupt(UART_RX_COMPLETE);
		}
	}
	else
	{
		GS_u16RxBufferCounter = 0;
	}
}
/*USART, UDRE USART Data Register Empty*/
void __vector_14(void) __attribute__((signal));
void __vector_14(void)
{
	if (GS_UDR_EMPTY_CallBack != NULL)
	{
		GS_UDR_EMPTY_CallBack();
	}
}
/*USART, TXC USART, Tx Complete*/
void __vector_15(void) __attribute__((signal));
void __vector_15(void)
{
	/*  Check If GS_u16TxBufferCounter greater than or equal GS_u16TxBufferSize of array make Counter = 0 */
	if (GS_u16TxBufferCounter < GS_u16TxBufferSize)
	{
		if (GS_TXC_CallBack != NULL)
		{
			GS_TXC_CallBack();
		}
		/* 1- Check on the array reach to the end or not */
		if (GS_pu8InternalTxBuffer[GS_u16TxBufferCounter] != '\0')
		{
			/* 2- Send The Buffer To the UDR */
			UDR = GS_pu8InternalTxBuffer[GS_u16TxBufferCounter];
			/* 3- Increment The counter */
			GS_u16TxBufferCounter++;
		}
		else
		{
			MUART_vDisableInterrupt(UART_TX_COMPLETE);
		}
	}
	else
	{
		/* Counter = 0 */
		GS_u16TxBufferCounter = 0;
	}
}
/*##################################################################################################################*/


