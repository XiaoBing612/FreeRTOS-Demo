/**
	********************************************************
	*@file				task_key.c
	*@author			
	*@version     v1.0
	*@date        2017.01.11
	*@brief       FreeRTOS ����ջ������
	*********************************************************
	*/
	#include "includes.h"
	
	/*
	*@function:vTaskKey
	*@param:pvParameters��������������ʱ���ݵ��β�
	*@retval:None
	*@brief:��������
	*@priority:4(��ֵԽС�����ȼ�Խ��)
	*/
	void vTaskKey(void *pvParameters)
	{
		uint8_t pcWriteBuf[500];
		
		while(1)
		{
			if(Key1_Scan())																		/* ���°���1 ��ӡ�����������*/
			{
				printf(" \r\n ��ӡFreeRTOS������ִ�е���� \r\n");
				printf(" \r\n ������  ����״̬ ���ȼ� ʣ��ջ ������� \r\n");
				vTaskList((char *)&pcWriteBuf);
				printf("%s\r\n",pcWriteBuf);
			}
			else if(Key2_Scan())															/* ģ��ջ������ */
			{
				printf("\r\n ���°���2��ģ������ջ��� \r\n");
				StackOverFlowTest();
			}
			vTaskDelay(20);
		}
	}
	
	/*
	*@function:StackOverFlowTest
	*@param:None
	*@retval:None
	*@brief:����ջ�������
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
	*@param:xTask����������
	*				pcTaskName����������
	*@retval:None
	*@brief:ջ������Ӻ���
	*/
	void vApplicationStackOverflowHook(TaskHandle_t xTask,signed char *pcTaskName)
	{
		printf("\r\n ����:%s ����ջ��� \r\n",pcTaskName);
	}