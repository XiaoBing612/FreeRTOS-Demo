/**
	*******************************************************************
	*@file			delay.c
	*@author		
	*@version		v1.0
	*@date			2017.01.02
	*@brief			FreeRTOS �������
	*******************************************************************
	*/
	#include "includes.h"
	
	/*
	*@function:delay
	*@param:nCount������ʱʱ��
	*@retval:None
	*@brief:�����ʱ
	*/
	void delay(u32 nCount)
	{
		for(;nCount>0;nCount--)
			__NOP();
	}
	
	