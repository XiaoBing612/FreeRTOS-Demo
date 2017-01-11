/**
	*******************************************************************
	*@file			key.h
	*@author		
	*@version		v1.0
	*@date			2017.01.02
	*@brief			FreeRTOS 任务管理
	*******************************************************************
	*/
	#ifndef __KEY_H_
	#define __KEY_H_
	
	#include "stm32f10x.h"
	
	void KEY_GPIO_Config(void);
	uint8_t key1Scan(void);
	uint8_t key2Scan(void);
	
	#endif /* __KEY_H_ */