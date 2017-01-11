/**
	***********************************************************************
	*@file			task_led.c
	*@author
	*@version		v1.0
	*@date			2017.01.11
	*@brief			FreeRTOS����ջ�����ⷽ��һ
	***********************************************************************
	*/
	#include "includes.h"
	
	/*
	*@function:vTaskLED1
	*@param:pvParameters��������������ʱ���ݵ��β�
	*@brief:LED1����˸����
	*@retval:None
	*@priority:1(��ֵԽС�����ȼ�Խ��)
	*/
	void vTaskLED1(void *pvParameters)
	{
		while(1)
		{
			GPIO_ResetBits(GPIOB,GPIO_Pin_0);
			vTaskDelay(200);
			GPIO_SetBits(GPIOB,GPIO_Pin_0);
			vTaskDelay(200);
		}
	}
	
	/*
	*@function:vTaskLED2
	*@param:pvParameters��������������ʱ���ݵ��β�
	*@brief:LED2����˸����
	*@retval:None
	*@priority:1(��ֵԽС�����ȼ�Խ��)
	*/
	void vTaskLED2(void *pvParameters)
	{
		while(1)
		{
			GPIO_ResetBits(GPIOF,GPIO_Pin_7);
			vTaskDelay(200);
			GPIO_SetBits(GPIOF,GPIO_Pin_7);
			vTaskDelay(200);
		}
	}
	
	/*
	*@function:vTaskLED3
	*@param:pvParameters��������������ʱ���ݵ��β�
	*@brief:LED3����˸����
	*@retval:None
	*@priority:1(��ֵԽС�����ȼ�Խ��)
	*/
	void vTaskLED3(void *pvParameters)
	{
		while(1)
		{
			GPIO_ResetBits(GPIOF,GPIO_Pin_8);
			vTaskDelay(200);
			GPIO_SetBits(GPIOF,GPIO_Pin_8);
			vTaskDelay(200);
		}
	}
	
	