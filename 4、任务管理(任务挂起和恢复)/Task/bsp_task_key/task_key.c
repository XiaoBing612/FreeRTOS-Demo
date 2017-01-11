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
	
	TaskHandle_t 	xHandleTaskUserIF = NULL;
	
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
				vTaskSuspend(xHandleTaskUserIF);
			}
			else if(key2Scan())
			{
				vTaskResume(xHandleTaskUserIF);
			}
			vTaskDelay(20);
		}
	}