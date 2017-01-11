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
	*@prarm:pvParameters��������������ʱ���ݵĲ���
	*@retval:None
	*/
	void vTaskUsart1(void *pvParameters)
	{
		uint8_t pcWriteBuffer[500];
		
		while(1)
		{
			printf(" FreeRTOS ���ڴ�ӡ����ִ�����  \r\n");
			printf("������      ����״̬  ���ȼ�  ʣ��ջ  �������\r\n");
			vTaskList((char *)&pcWriteBuffer);
			printf("%s\r\n",pcWriteBuffer);
			
			printf("������  ���м���  ʹ����  \r\n");
//			vTaskGetRunTimeStats((char *)&pcWriteBuffer);
//			printf("%s\r\n",pcWriteBuffer);

			vTaskDelay(20);
		}
	}