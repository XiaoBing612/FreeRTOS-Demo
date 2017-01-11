/**
	******************************************************
	*@file		led.c
	*@author	小兵Demo
	*@date		2015.11.25
	*@version v3.0
	*@brief		led函数
	******************************************************
	*@attention
	*
	*@实验平台：野火ISO STM32开发板
	*
	******************************************************
	*/
	#include "led.h"
	
	/*****************************************************
	*LED灯初始化及配置函数
	******************************************************/
	void LED_Config(void)
	{
		GPIO_InitTypeDef	GPIO_InitStructure;
		
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOF,ENABLE);
		
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOB,&GPIO_InitStructure);
		
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_8;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOF,&GPIO_InitStructure);
	}
	
	