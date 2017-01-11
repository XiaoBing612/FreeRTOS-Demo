/**
	********************************************************
	*@file				task_key.c
	*@author			
	*@version     v1.0
	*@date        2017.01.11
	*@brief       FreeRTOS 任务栈溢出检测
	*********************************************************
	*/
	#include "includes.h"
	
	/*
	*@function:vTaskKey
	*@param:pvParameters——创建该任务时传递的形参
	*@retval:None
	*@brief:按键处理
	*@priority:4(数值越小，优先级越低)
	*/
	void vTaskKey(void *pvParameters)
	{
		uint8_t pcWriteBuf[500];
		
		while(1)
		{
			if(Key1_Scan())																		/* 按下按键1 打印任务运行情况*/
			{
				printf(" \r\n 打印FreeRTOS的任务执行的情况 \r\n");
				printf(" \r\n 任务名  任务状态 优先级 剩余栈 任务序号 \r\n");
				vTaskList((char *)&pcWriteBuf);
				printf("%s\r\n",pcWriteBuf);
			}
			else if(Key2_Scan())															/* 模拟栈溢出检测 */
			{
				printf("\r\n 按下按键2，模拟任务栈溢出 \r\n");
				StackOverFlowTest();
			}
			vTaskDelay(20);
		}
	}
	
	/*
	*@function:StackOverFlowTest
	*@param:None
	*@retval:None
	*@brief:任务栈溢出测试
	*/
	static void StackOverFlowTest(void)
	{
		int16_t i;
		uint8_t buf[2048];
		
		for(i = 2047;i >= 0;i--)
		{
			buf[i] = 0x55;
			vTaskDelay(1);
		}
	}
	
	/*
	*@function:vApplicationStackOverflowHook
	*@param:xTask——任务句柄
	*				pcTaskName——任务名
	*@retval:None
	*@brief:栈溢出钩子函数
	*/
	void vApplicationStackOverflowHook(TaskHandle_t xTask,signed char *pcTaskName)
	{
		printf("\r\n 任务:%s 发现栈溢出 \r\n",pcTaskName);
	}