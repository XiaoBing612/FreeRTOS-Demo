/**
	*******************************************************************
	*@file			delay.c
	*@author		
	*@version		v1.0
	*@date			2017.01.02
	*@brief			FreeRTOS 任务管理
	*******************************************************************
	*/
	#include "includes.h"
	
	/*
	*@function:delay
	*@param:nCount——延时时间
	*@retval:None
	*@brief:软件延时
	*/
	void delay(u32 nCount)
	{
		for(;nCount>0;nCount--)
			__NOP();
	}
	
	