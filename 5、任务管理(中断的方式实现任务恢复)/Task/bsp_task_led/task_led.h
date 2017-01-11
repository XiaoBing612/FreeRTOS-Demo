/**
	**************************************************************************
	*@file					task_led.h
	*@author				
	*@version				v1.0
	*@date					2016.12.27
	*@brief					FreeRTOS
	**************************************************************************
	*/
	#ifndef __TASK_LED_H_
	#define __TASK_LED_H_
	
	void vTaskUserIF(void *pvParameters);
	void vTaskLED(void *pvParameters);
	void vTaskMsgPro(void *pvParameters);
	
	#endif /* __TASK_LED_H_ */