/**
	***********************************************************************
	*@file			led.c
	*@author
	*@version		v1.0
	*@date			2017.01.11
	*@brief			FreeRTOS任务栈溢出检测方法一
	***********************************************************************
	*/
	#include "includes.h"
	
	/*
	*@function:LED_GPIO_Config
	*@param:None
	*@retval:None
	*@brief:LED初始化配置
	*/
	void LED_GPIO_Config(void)
	{
		GPIO_InitTypeDef	GPIO_InitStructure;
		
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF,ENABLE);
		
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOB,&GPIO_InitStructure);
		
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_8;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOF,&GPIO_InitStructure);
	}
		