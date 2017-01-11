/**
	*******************************************************************
	*@file			task_key.c
	*@author		
	*@version		v1.0
	*@date			2017.01.02
	*@brief			FreeRTOS 任务管理
	*******************************************************************
	*/
	#include "includes.h"
	
	TaskHandle_t 	xHandleTaskLED;
	
	/*
	*@function:vTaskKey
	*@param:pvParameters——创建该任务时传递的形参
	*@brief:按键处理,按下按键1，删除任务vTask LED2
	*@retval:None
	*@priority:4(数值越小，优先级越低)
	*/
	void vTaskKey(void *pvParameters)
	{
		while(1)
		{
			if(key1Scan())
			{
				if(xHandleTaskLED != NULL)
				{
					vTaskDelete(xHandleTaskLED);
					xHandleTaskLED = NULL;
				}
			}
			else if(key2Scan())
			{
				if(xHandleTaskLED == NULL)
				{
					xTaskCreate(vTaskLED,														/*任务函数*/
								"vTask LED2",															/*任务名*/
								512,																			/*任务栈大小，单位word，也就是4个字节*/
								NULL,																			/*任务参数*/
								3,																				/*任务优先级*/
								&xHandleTaskLED);													/*任务句柄*/
				}
			}
			vTaskDelay(20);
		}
	}