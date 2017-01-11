/**
	****************************************************************************
	*@file			main.c
	*@author		
	*@version		V1.0
	*@date			2017.01.08
	*@brief			FreeRTOS ����ջ�����ⷽ��һ
	****************************************************************************
	*@attention
	*
	*@ʵ��ƽ̨��Ұ��ISO STM32 ������
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
		__set_PRIMASK(1);																	/* ���жϣ�prvStartFirstTask�л����´�ȫ���ж� */
		
		Board_Init();
		
		Task_Create();																		/* �������� */
		
		vTaskStartScheduler();														/* ����������ȣ���ʼִ������ */
	}

	void Task_Create(void)
	{
		xTaskCreate(vTaskLED1,														/* ������ */
								"Task LED1",													/* ������ */
								512,																	/* ����ջ��С����λword��Ҳ����4���ֽ� */
								NULL,																	/* ������� */
								1,																		/* �������ȼ�*/
								&xHandleTaskLED1);										/* ������ */
		
		xTaskCreate(vTaskLED2,														/* ������ */
								"Task LED2",													/* ������ */
								512,																	/* ����ջ��С����λword��Ҳ����4���ֽ� */
								NULL,																	/* ������� */
								2,																		/* �������ȼ�*/
								&xHandleTaskLED2);										/* ������ */
		
		xTaskCreate(vTaskLED3,														/* ������ */
								"Task LED3",													/* ������ */
								512,																	/* ����ջ��С����λword��Ҳ����4���ֽ� */
								NULL,																	/* ������� */
								3,																		/* �������ȼ�*/
								&xHandleTaskLED3);										/* ������ */
		
		xTaskCreate(vTaskKey,															/* ������ */
								"Task KEY",														/* ������ */
								512,																	/* ����ջ��С����λword��Ҳ����4���ֽ� */
								NULL,																	/* ������� */
								3,																		/* �������ȼ�*/
								&xHandleTaskKEY);											/* ������ */
	}
	
	