#include "task_led.h"
#include "includes.h"

/*
*@function:vTaskUserIF
*@param:pvParameters——创建该任务时传递的形参
*@brief:接口消息处理，这里用作LED闪烁
*@retval:None
*@priority:1(数值越小，优先级越低)
*/
void vTaskTaskUserIF(void *pvParameters)
{
	while(1)
	{
		GPIO_ResetBits(GPIOB,GPIO_Pin_5);
		vTaskDelay(100);
		GPIO_SetBits(GPIOB,GPIO_Pin_5);
		vTaskDelay(100);
	}
}

/*
*@function:vTaskLED
*@param:pvParameters——创建该任务时传递的形参
*@brief:LED闪烁
*@retval:None
*@priority:2(数值越小，优先级越低)
*/
void vTaskLED(void *pvParameters)
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
*@function:vTaskMsgPro
*@param:pvParameters——创建该任务时传递的形参
*@brief:这里用作LED灯闪烁
*@retval:None
*@priority:3(数值越小，优先级越低)
*/
void vTaskMsgPro(void *pvParameters)
{
	while(1)
	{
		GPIO_ResetBits(GPIOF,GPIO_Pin_8);
		vTaskDelay(300);
		GPIO_SetBits(GPIOF,GPIO_Pin_8);
		vTaskDelay(300);
	}
}


