/**
	*******************************************************************
	*@file			task_key.c
	*@author		
	*@version		v1.0
	*@date			2017.01.02
	*@brief			FreeRTOS �������
	*******************************************************************
	*/
	#include "includes.h"
	
	TaskHandle_t 	xHandleTaskLED;
	
	/*
	*@function:vTaskKey
	*@param:pvParameters��������������ʱ���ݵ��β�
	*@brief:��������,���°���1��ɾ������vTask LED2
	*@retval:None
	*@priority:4(��ֵԽС�����ȼ�Խ��)
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
					xTaskCreate(vTaskLED,														/*������*/
								"vTask LED2",															/*������*/
								512,																			/*����ջ��С����λword��Ҳ����4���ֽ�*/
								NULL,																			/*�������*/
								3,																				/*�������ȼ�*/
								&xHandleTaskLED);													/*������*/
				}
			}
			vTaskDelay(20);
		}
	}