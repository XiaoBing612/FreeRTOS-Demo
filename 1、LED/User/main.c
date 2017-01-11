/**
	*************************************************
	*@file		main.c
	*@author	С��Demo
	*@version	v3.0
	*@date		2015.11.24
	*@brief		���ÿ⺯���ķ�ʽ����LED,ʹ����˸
	**************************************************
	*@attention
	*
	*@ʵ��ƽ̨��Ұ��ISO STM32������
	**************************************************
	*/
	#include "stm32f10x.h"
	#include "includes.h"
	
	void delay(__IO uint32_t nCount);
	static void Task_Create(void);
	
	/**
	**********************************************************
	*														��������
	**********************************************************
	**/
	static TaskHandle_t	xHandleTaskUserIF = NULL;
	static TaskHandle_t xHandleTaskLED = NULL;
	static TaskHandle_t xHandleTaskMsgPro = NULL;
	
	int main()
	{
		__set_PRIMASK(1);										//���жϣ�prvStartFirstTask�л����¿���ȫ���ж�
		LED_Config();
		
		Task_Create();											//��������
		vTaskStartScheduler();							//����������ȣ���ʼִ������
		
		while(1);
	}
	
	/************************************************************
	*��ʱ����
	*************************************************************/
	void delay(__IO uint32_t nCount)
	{
		for(;nCount > 0 ; nCount--);
	}
	
	static void Task_Create(void)
	{
		xTaskCreate(vTaskTaskUserIF,						/*������*/
								"vTaskUserIF",							/*������*/
								128,												/*����ջ��С����λword,Ҳ����4�ֽ�*/
								NULL,												/*�������*/
								1,													/*�������ȼ�*/
								&xHandleTaskUserIF);				/*������*/
		
		xTaskCreate(vTaskLED,										/*������*/
								"vTaskLED",									/*������*/
								128,												/*����ջ��С����λword,Ҳ����4�ֽ�*/
								NULL,												/*�������*/
								2,													/*�������ȼ�*/
								&xHandleTaskLED);						/*������*/
		
		xTaskCreate(vTaskMsgPro,								/*������*/
								"vTaskMsgPro",							/*������*/
								128,												/*����ջ��С����λword��Ҳ����4���ֽ�*/
								NULL,												/*�������*/
								3,													/*�������ȼ�*/
								&xHandleTaskMsgPro);				/*������*/
	}
		
	
	/********************************END OF FILE**********************************/