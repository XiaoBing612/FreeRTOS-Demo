/**
	**************************************************************************
	*@file					nvic.c
	*@author				
	*@version				v1.0
	*@date					2016.12.27
	*@brief					FreeRTOS
	**************************************************************************
	*/
	#include "nvic.h"
	
	/*
	*@function:NVIC_Configuration
	*@param:None
	*@retval:None
	*/
	void NVIC_Configuration(void)
	{
		NVIC_InitTypeDef	NVIC_InitStructure;
		
		NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;
		NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
		NVIC_Init(&NVIC_InitStructure);
	}
	
	