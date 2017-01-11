/**
	**************************************************************************
	*@file					board.c
	*@author				
	*@version				v1.0
	*@date					2016.12.27
	*@brief					FreeRTOS
	**************************************************************************
	*/
	#include "includes.h"
	
	/*
	*@function:Board_Init
	*@param:None
	*@retval:None
	*@brief:系统初始化配置
	*/
	void Board_Init(void)
	{
		/*优先级分组设置为4，可配置0-15级抢占式优先级，0级优先级，即不存在子优先级。*/
		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
		
		LED_GPIO_Config();																				/*初始化LED配置*/
		NVIC_Configuration();
		USART1_Configuration(115200);															/*初始化串口1配置*/
	}
	
	
	
	