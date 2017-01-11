/**
	**************************************************************************
	*@file					task_timer.c
	*@author				
	*@version				v1.0
	*@date					2016.12.27
	*@brief					FreeRTOS
	**************************************************************************
	*/
	#include "task_timer.h"
	
	#define timerINTERRUPT_FREQUENCY	2000
	
	#define timerHIGHEST_PRIORITY			1
	
	volatile uint32_t ulHighFrequencyTimerTicks = 0UL;
	
	/*
	*@function:vSetupTimerTest
	*@param:None
	*@retval:None
	*@brief:创建定时器
	*/
	void vSetupTimerTest(void)
	{
		
	}