/**
	**************************************************************************
	*@file					task_usart1.c
	*@author				
	*@version				v1.0
	*@date					2016.12.28
	*@brief					FreeRTOS
	**************************************************************************
	*/
	#include "includes.h"
	
	/*
	*@function:vTaskUsart1
	*@prarm:pvParameters——创建该任务时传递的参数
	*@retval:None
	*/
	void vTaskUsart1(void *pvParameters)
	{
		uint8_t pcWriteBuffer[500];
		
		while(1)
		{
			printf(" FreeRTOS 串口打印任务执行情况  \r\n");
			printf("任务名      任务状态  优先级  剩余栈  任务序号\r\n");
			vTaskList((char *)&pcWriteBuffer);
			printf("%s\r\n",pcWriteBuffer);
			
			printf("任务名  运行计数  使用率  \r\n");
//			vTaskGetRunTimeStats((char *)&pcWriteBuffer);
//			printf("%s\r\n",pcWriteBuffer);

			vTaskDelay(20);
		}
	}