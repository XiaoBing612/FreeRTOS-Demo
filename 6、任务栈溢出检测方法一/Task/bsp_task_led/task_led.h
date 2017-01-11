/**
	***********************************************************************
	*@file			task_led.h
	*@author
	*@version		v1.0
	*@date			2017.01.11
	*@brief			FreeRTOS任务栈溢出检测方法一
	***********************************************************************
	*/
	#ifndef __TASK_LED_H_
	#define __TASK_LED_H_
	
	void vTaskLED1(void *pvParameters);
	void vTaskLED2(void *pvParameters);
	void vTaskLED3(void *pvParameters);
	
	#endif	/* __TASK_LED_H_ */