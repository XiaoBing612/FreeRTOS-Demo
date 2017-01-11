/**
	**************************************************************************
	*@file					task_led.c
	*@author				
	*@version				v1.0
	*@date					2016.12.27
	*@brief					FreeRTOS
	**************************************************************************
	*/
	#include "includes.h"
	
	/*
	*@function:vTaskUserIF
	*@param:pvParameters��������������ʱ���ݵ��β�
	*@brief:�ӿ���Ϣ������������LED�Ƶ���˸
	*@retval:None
	*@priority:1(��ֵԽС�����ȼ�Խ��)
	*/
	void vTaskUserIF(void *pvParameters)
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
	*@brief:LED����˸
	*@retval:None
	*@priority:2(��ֵԽС�����ȼ�Խ��)
	*/
	void vTaskLED(void *pvParameters)
	{
		while(1)
		{
			GPIO_SetBits(GPIOF,GPIO_Pin_7);
			vTaskDelay(200);
			GPIO_ResetBits(GPIOF,GPIO_Pin_7);
			vTaskDelay(200);
		}
	}
	
	/*
	*@function:vTaskMsgPro
	*@param:pvParameters��������������ʱ���ݵ��β�
	*@brief:LED3��˸
	*@retval:None
	*@priority:3(��ֵԽС�����ȼ�Խ��)
	*/
	void vTaskMsgPro(void *pvParameters)
	{
		while(1)
		{
			GPIO_SetBits(GPIOF,GPIO_Pin_8);
			vTaskDelay(300);
			GPIO_ResetBits(GPIOF,GPIO_Pin_8);
			vTaskDelay(300);
		}
	}