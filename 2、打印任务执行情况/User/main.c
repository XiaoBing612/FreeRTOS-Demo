/**
	**************************************************************************
	*@file					main.c
	*@author				
	*@version				v1.0
	*@date					2016.12.27
	*@brief					FreeRTOS
	**************************************************************************
	*/
	#include "stm32f10x.h"
	#include "includes.h"
	
	/*
	*************************************************************************
	*																变量声明
	**************************************************************************
	*/
	static TaskHandle_t 	xHandleTaskUserIF = NULL;
	static TaskHandle_t   xHandleTaskLED = NULL;
	static TaskHandle_t 	xHandleTaskUsart1 = NULL;
	static TaskHandle_t 	xHandleTaskMsgPro = NULL;
	

	void Task_Create(void);
	
	int main(void)
	{
		__set_PRIMASK(1);																			/*关中断，prvStartFirstTask中会重新开启全局中断*/
		
		Board_Init();																					/*板子初始化配置*/
		
		Task_Create();																				/*创建任务*/
		
		vTaskStartScheduler();																/*启动任务调度，开始执行任务*/
		
		while(1);
	}
	
	void Task_Create(void)
	{
		xTaskCreate(vTaskUserIF,															/*任务函数*/
								"vTask 1",																/*任务名*/
								128,																			/*任务栈大小，单位word,也就是4个字节*/
								NULL,																			/*任务参数*/
								1,																				/*任务优先级*/
								&xHandleTaskUserIF);											/*任务句柄*/
		
		xTaskCreate(vTaskLED,																	/*任务函数*/
								"vTask 2",																/*任务名*/
								128,																			/*任务栈大小，单位word，也就是4个字节*/
								NULL,																			/*任务参数*/
								2,																				/*任务优先级*/
								&xHandleTaskLED);													/*任务句柄*/
		
		xTaskCreate(vTaskUsart1,															/*任务函数*/
								"vTask 3",																/*任务名*/
								512,																			/*任务栈大小，单位word,也就是4个字节*/
								NULL,																			/*任务参数*/
								3,																				/*任务优先级*/
								&xHandleTaskUsart1);											/*任务句柄*/
		
		xTaskCreate(vTaskMsgPro,															/*任务函数*/
								"vTask 4",																/*任务名*/
								128,																			/*任务栈大小，单位word,也就是4个字节*/
								NULL,																			/*任务参数*/
								4,																				/*任务优先级*/
								&xHandleTaskMsgPro);											/*任务句柄*/
	}
	
	