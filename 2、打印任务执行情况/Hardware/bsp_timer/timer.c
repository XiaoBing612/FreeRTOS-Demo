/**
	**************************************************************************
	*@file					timer.c
	*@author				
	*@version				v1.0
	*@date					2016.12.27
	*@brief					FreeRTOS
	**************************************************************************
	*/
	#include "includes.h"
	
	volatile uint32_t ulHighFrequencyTimerTicks = 0UL;
	
	/*
	*@function:TIM_Config
	*@param:None
	*@retval:None
	*/
	void TIM_Config(void)
	{
		TIM_TimeBaseInitTypeDef	TIM_TimeBaseStructure;
		
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
		
		TIM_DeInit(TIM3);
		
		TIM_TimeBaseStructure.TIM_Prescaler = 20000-1;
		TIM_TimeBaseStructure.TIM_Period = 0;
		TIM_TimeBaseStructure.TIM_ClockDivision = 0x0;
		TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
		TIM_TimeBaseInit(TIM3,&TIM_TimeBaseStructure);
		
		TIM_ClearFlag(TIM3,TIM_FLAG_Update);
		TIM_Cmd(TIM3,ENABLE);
		TIM_ITConfig(TIM3,TIM_IT_Update,DISABLE);
	}
	
	