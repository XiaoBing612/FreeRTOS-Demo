/**
	**************************************************************************
	*@file					usart1.c
	*@author				
	*@version				v1.0
	*@date					2016.12.27
	*@brief					FreeRTOS
	**************************************************************************
	*/
	#include "includes.h"
	
	/*
	*@function:USART1_Configuration
	*@param:nBaudRate
	*@retval:None
	*/
	void USART1_Configuration(u32 nBaudRate)
	{
		GPIO_InitTypeDef	GPIO_InitStructure;
		USART_InitTypeDef	USART_InitStructure;
		
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
		
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOA,&GPIO_InitStructure);
		
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
		GPIO_Init(GPIOA,&GPIO_InitStructure);
		
		USART_InitStructure.USART_BaudRate = nBaudRate;
		USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
		USART_InitStructure.USART_WordLength = USART_WordLength_8b;
		USART_InitStructure.USART_StopBits = USART_StopBits_1;
		USART_InitStructure.USART_Parity = USART_Parity_No;
		USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
		USART_Init(USART1,&USART_InitStructure);
		
		USART_Cmd(USART1,ENABLE);
	}
	
	int fputc(int ch,FILE *f)
	{
		USART_SendData(USART1,(u8)ch);
		
		while(USART_GetFlagStatus(USART1,USART_FLAG_TXE) == RESET);
		
		return ch;
	}
	
	int fgetc(FILE *f)
	{
		while(USART_GetFlagStatus(USART1,USART_FLAG_RXNE) == RESET);
		
		return (int)USART_ReceiveData(USART1);
	}
	
	
	