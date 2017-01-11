/**
	***********************************************************************
	*@file			board.c
	*@author
	*@version		v1.0
	*@date			2017.01.11
	*@brief			FreeRTOS����ջ�����ⷽ��һ
	***********************************************************************
	*/
	#include "includes.h"
	
	/*
	*@function:Board_Init
	*@param:None
	*@retval:None
	*@brief:���ӳ�ʼ������
	*/
	void Board_Init(void)
	{
		/*���ȼ���������Ϊ4��������0-15����ռʽ���ȼ���0�����ȼ����������������ȼ���*/
		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
		
		LED_GPIO_Config();
	}
	
	