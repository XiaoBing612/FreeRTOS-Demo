/**
	********************************************************
	*@file				key.h
	*@author			
	*@version     v1.0
	*@date        2017.01.11
	*@brief       FreeRTOS ÈÎÎñÕ»Òç³ö¼ì²â
	*********************************************************
	*/
	#ifndef __KEY_H_
	#define __KEY_H_
	
	#include "stm32f10x.h"
	
	void KEY_GPIO_Config(void);
	uint8_t Key1_Scan(void);
	uint8_t Key2_Scan(void);
	
	#endif /* __KEY_H_ */