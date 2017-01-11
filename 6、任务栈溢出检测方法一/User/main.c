/**
	****************************************************************************
	*@file			main.c
	*@author		
	*@version		V1.0
	*@date			2017.01.08
	*@brief			FreeRTOS 任务栈溢出检测方法一
	****************************************************************************
	*@attention
	*
	*@实验平台：野火ISO STM32 开发板
	****************************************************************************
	*/
	#include "stm32f10x.h"
	#include "includes.h"
	
	static TaskHandle_t		xHandleTaskLED1 = NULL;
	static TaskHandle_t   xHandleTaskLED2 = NULL;
	static TaskHandle_t   xHandleTaskLED3 = NULL;
	static TaskHandle_t   xHandleTaskKEY = NULL;
	
	void Task_Create(void);
	
	int main(void)
	{
		__set_PRIMASK(1);																	/* 关中断，prvStartFirstTask中会重新打开全局中断 */
		
		Board_Init();
		
		Task_Create();																		/* 创建任务 */
		
		vTaskStartScheduler();														/* 启动任务调度，开始执行任务 */
	}

	void Task_Create(void)
	{
		xTaskCreate(vTaskLED1,														/* 任务函数 */
								"Task LED1",													/* 任务名 */
								512,																	/* 任务栈大小，单位word，也就是4个字节 */
								NULL,																	/* 任务参数 */
								1,																		/* 任务优先级*/
								&xHandleTaskLED1);										/* 任务句柄 */
		
		xTaskCreate(vTaskLED2,														/* 任务函数 */
								"Task LED2",													/* 任务名 */
								512,																	/* 任务栈大小，单位word，也就是4个字节 */
								NULL,																	/* 任务参数 */
								2,																		/* 任务优先级*/
								&xHandleTaskLED2);										/* 任务句柄 */
		
		xTaskCreate(vTaskLED3,														/* 任务函数 */
								"Task LED3",													/* 任务名 */
								512,																	/* 任务栈大小，单位word，也就是4个字节 */
								NULL,																	/* 任务参数 */
								3,																		/* 任务优先级*/
								&xHandleTaskLED3);										/* 任务句柄 */
		
		xTaskCreate(vTaskKey,															/* 任务函数 */
								"Task KEY",														/* 任务名 */
								512,																	/* 任务栈大小，单位word，也就是4个字节 */
								NULL,																	/* 任务参数 */
								3,																		/* 任务优先级*/
								&xHandleTaskKEY);											/* 任务句柄 */
	}
	
	