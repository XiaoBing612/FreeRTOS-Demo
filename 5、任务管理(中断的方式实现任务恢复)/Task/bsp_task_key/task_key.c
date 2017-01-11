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
	
	TaskHandle_t 	xHandleTaskUserIF = NULL;
	
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
				vTaskSuspend(xHandleTaskUserIF);
			}
			else if(key2Scan())
			{
				Task_Handle();
			}
			vTaskDelay(20);
		}
	}
	
	/*
	*
	*/
	void Task_Handle(void)
	{
		BaseType_t	xYieldRequired;
	
		xYieldRequired = xTaskResumeFromISR(xHandleTaskUserIF);
		
		if(xYieldRequired == pdTRUE)
		{
			portYIELD_FROM_ISR(xYieldRequired);
		}
	}