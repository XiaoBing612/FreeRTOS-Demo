/**
	**************************************************************************
	*@file					main.c
	*@author				
	*@version				v1.0
	*@date					2016.12.27
	*@brief					FreeRTOS
	**************************************************************************
	*/
	#include "stm32f10x.h"
	#include "includes.h"
	
	/*
	*************************************************************************
	*																��������
	**************************************************************************
	*/
	static TaskHandle_t 	xHandleTaskUserIF = NULL;
	static TaskHandle_t   xHandleTaskLED = NULL;
	static TaskHandle_t 	xHandleTaskUsart1 = NULL;
	static TaskHandle_t 	xHandleTaskMsgPro = NULL;
	

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
								"vTask 1",																/*������*/
								128,																			/*����ջ��С����λword,Ҳ����4���ֽ�*/
								NULL,																			/*�������*/
								1,																				/*�������ȼ�*/
								&xHandleTaskUserIF);											/*������*/
		
		xTaskCreate(vTaskLED,																	/*������*/
								"vTask 2",																/*������*/
								128,																			/*����ջ��С����λword��Ҳ����4���ֽ�*/
								NULL,																			/*�������*/
								2,																				/*�������ȼ�*/
								&xHandleTaskLED);													/*������*/
		
		xTaskCreate(vTaskUsart1,															/*������*/
								"vTask 3",																/*������*/
								512,																			/*����ջ��С����λword,Ҳ����4���ֽ�*/
								NULL,																			/*�������*/
								3,																				/*�������ȼ�*/
								&xHandleTaskUsart1);											/*������*/
		
		xTaskCreate(vTaskMsgPro,															/*������*/
								"vTask 4",																/*������*/
								128,																			/*����ջ��С����λword,Ҳ����4���ֽ�*/
								NULL,																			/*�������*/
								4,																				/*�������ȼ�*/
								&xHandleTaskMsgPro);											/*������*/
	}
	
	