/**
	*************************************************
	*@file		main.c
	*@author	小兵Demo
	*@version	v3.0
	*@date		2015.11.24
	*@brief		调用库函数的方式点亮LED,使其闪烁
	**************************************************
	*@attention
	*
	*@实验平台：野火ISO STM32开发板
	**************************************************
	*/
	#include "stm32f10x.h"
	#include "includes.h"
	
	void delay(__IO uint32_t nCount);
	static void Task_Create(void);
	
	/**
	**********************************************************
	*														变量声明
	**********************************************************
	**/
	static TaskHandle_t	xHandleTaskUserIF = NULL;
	static TaskHandle_t xHandleTaskLED = NULL;
	static TaskHandle_t xHandleTaskMsgPro = NULL;
	
	int main()
	{
		__set_PRIMASK(1);										//关中断，prvStartFirstTask中会重新开启全局中断
		LED_Config();
		
		Task_Create();											//创建任务
		vTaskStartScheduler();							//启动任务调度，开始执行任务
		
		while(1);
	}
	
	/************************************************************
	*延时函数
	*************************************************************/
	void delay(__IO uint32_t nCount)
	{
		for(;nCount > 0 ; nCount--);
	}
	
	static void Task_Create(void)
	{
		xTaskCreate(vTaskTaskUserIF,						/*任务函数*/
								"vTaskUserIF",							/*任务名*/
								128,												/*任务栈大小，单位word,也就是4字节*/
								NULL,												/*任务参数*/
								1,													/*任务优先级*/
								&xHandleTaskUserIF);				/*任务句柄*/
		
		xTaskCreate(vTaskLED,										/*任务函数*/
								"vTaskLED",									/*任务名*/
								128,												/*任务栈大小，单位word,也就是4字节*/
								NULL,												/*任务参数*/
								2,													/*任务优先级*/
								&xHandleTaskLED);						/*任务句柄*/
		
		xTaskCreate(vTaskMsgPro,								/*任务函数*/
								"vTaskMsgPro",							/*任务名*/
								128,												/*任务栈大小，单位word，也就是4个字节*/
								NULL,												/*任务参数*/
								3,													/*任务优先级*/
								&xHandleTaskMsgPro);				/*任务句柄*/
	}
		
	
	/********************************END OF FILE**********************************/