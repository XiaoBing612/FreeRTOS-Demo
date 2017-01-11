/**
	*******************************************************************
	*@file			main.c
	*@author		
	*@version		v1.0
	*@date			2017.01.02
	*@brief			FreeRTOS �������
	*						���°���1��ɾ������vTask LED2,���°���2�����´�������
	*						vTask LED2
	*******************************************************************
	*/
	#include "stm32f10x.h"
	#include "includes.h"
	
	/*
	*************************************************************************
	*																��������
	**************************************************************************
	*/
	static TaskHandle_t 	xHandleTaskUserIF = NULL;
	extern TaskHandle_t   xHandleTaskLED;
	static TaskHandle_t 	xHandleTaskMsgPro = NULL;
	static TaskHandle_t 	xHandleTaskKey = NULL;

	void Task_Create(void);
	
	int main(void)
	{
		__set_PRIMASK(1);																			/*���жϣ�prvStartFirstTask�л����¿���ȫ���ж�*/
		
		Board_Init();																					/*���ӳ�ʼ������*/
		
		Task_Create();																				/*��������*/
		
		vTaskStartScheduler();																/*����������ȣ���ʼִ������*/
		
		while(1);
	}
	
	void Task_Create(void)
	{
		xTaskCreate(vTaskUserIF,															/*������*/
								"vTask LED1",															/*������*/
								512,																			/*����ջ��С����λword,Ҳ����4���ֽ�*/
								NULL,																			/*�������*/
								4,																				/*�������ȼ�*/
								&xHandleTaskUserIF);											/*������*/
		
		xTaskCreate(vTaskLED,																	/*������*/
								"vTask LED2",															/*������*/
								512,																			/*����ջ��С����λword��Ҳ����4���ֽ�*/
								NULL,																			/*�������*/
								3,																				/*�������ȼ�*/
								&xHandleTaskLED);													/*������*/
		
		xTaskCreate(vTaskMsgPro,															/*������*/
								"vTask LED3",															/*������*/
								512,																			/*����ջ��С����λword,Ҳ����4���ֽ�*/
								NULL,																			/*�������*/
								2,																				/*�������ȼ�*/
								&xHandleTaskMsgPro);											/*������*/
		
		xTaskCreate(vTaskKey,																	/*������*/
								"vTask 4",																/*������*/
								512,																			/*����ջ��С����λword,Ҳ����4���ֽ�*/
								NULL,																			/*�������*/
								1,																				/*�������ȼ�*/
								&xHandleTaskKey);													/*������*/
	}
