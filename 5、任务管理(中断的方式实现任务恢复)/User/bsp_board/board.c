/**
	**************************************************************************
	*@file					board.c
	*@author				
	*@version				v1.0
	*@date					2016.12.27
	*@brief					FreeRTOS
	**************************************************************************
	*/
	#include "includes.h"
	
	/*
	*@function:Board_Init
	*@param:None
	*@retval:None
	*@brief:ϵͳ��ʼ������
	*/
	void Board_Init(void)
	{
		/*���ȼ���������Ϊ4��������0-15����ռʽ���ȼ���0�����ȼ����������������ȼ���*/
		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
		
		LED_GPIO_Config();																				/*��ʼ��LED����*/
		KEY_GPIO_Config();
	}
	
	
	
	