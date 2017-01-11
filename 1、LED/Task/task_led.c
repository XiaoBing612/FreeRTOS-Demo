#include "task_led.h"
#include "includes.h"

/*
*@function:vTaskUserIF
*@param:pvParameters��������������ʱ���ݵ��β�
*@brief:�ӿ���Ϣ������������LED��˸
*@retval:None
*@priority:1(��ֵԽС�����ȼ�Խ��)
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
*@param:pvParameters��������������ʱ���ݵ��β�
*@brief:LED��˸
*@retval:None
*@priority:2(��ֵԽС�����ȼ�Խ��)
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
*@param:pvParameters��������������ʱ���ݵ��β�
*@brief:��������LED����˸
*@retval:None
*@priority:3(��ֵԽС�����ȼ�Խ��)
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


