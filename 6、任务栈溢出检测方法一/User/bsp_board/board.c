/**
	***********************************************************************
	*@file			board.c
	*@author
	*@version		v1.0
	*@date			2017.01.11
	*@brief			FreeRTOS任务栈溢出检测方法一
	***********************************************************************
	*/
	#include "includes.h"
	
	/*
	*@function:Board_Init
	*@param:None
	*@retval:None
	*@brief:板子初始化配置
	*/
	void Board_Init(void)
	{
		/*优先级分组设置为4，可配置0-15级抢占式优先级，0级优先级，即不存在子优先级。*/
		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
		
		LED_GPIO_Config();
	}
	
	