/**
	********************************************************
	*@file				key.c
	*@author			
	*@version     v1.0
	*@date        2017.01.11
	*@brief       FreeRTOS 任务栈溢出检测
	*********************************************************
	*/
	#include "includes.h"
	
	/*
	*@function:KEY_GPIO_Config
	*@param:None
	*@retval:None
	*@brief:按键初始化配置
	*/
	void KEY_GPIO_Config(void)
	{
		GPIO_InitTypeDef	GPIO_InitStructure;
		
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
		
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
		GPIO_Init(GPIOA,&GPIO_InitStructure);
		
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
		GPIO_Init(GPIOC,&GPIO_InitStructure);
	}
	
	/*
	*@function:Key1_Scan
	*@param:None
	*@retval:None
	*@brief:按键1扫描函数
	*/
	uint8_t Key1_Scan(void)
	{
		if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0) == 1)
		{
			vTaskDelay(100/portTICK_RATE_MS);
			if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0) == 1)
			{
				while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0) == 0);
				vTaskDelay(100/portTICK_RATE_MS);
			}
		}
	}
	
	/*
	*@function:Key2_Scan
	*@param:None
	*@retval:None
	*@brief:按键2扫描函数
	*/
	uint8_t Key2_Scan(void)
	{
		if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_13) == 1)
		{
			vTaskDelay(100/portTICK_RATE_MS);
			if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_13) == 1)
			{
				while(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_13) == 0);
				vTaskDelay(100/portTICK_RATE_MS);
			}
		}
	}