/**
	***********************************************************************
	*@file			task_led.c
	*@author
	*@version		v1.0
	*@date			2017.01.11
	*@brief			FreeRTOS任务栈溢出检测方法一
	***********************************************************************
	*/
	#include "includes.h"
	
	/*
	*@function:vTaskLED1
	*@param:pvParameters——创建该任务时传递的形参
	*@brief:LED1灯闪烁处理
	*@retval:None
	*@priority:1(数值越小，优先级越低)
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
	*@param:pvParameters——创建该任务时传递的形参
	*@brief:LED2灯闪烁处理
	*@retval:None
	*@priority:1(数值越小，优先级越低)
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
	*@param:pvParameters——创建该任务时传递的形参
	*@brief:LED3灯闪烁处理
	*@retval:None
	*@priority:1(数值越小，优先级越低)
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
	
	