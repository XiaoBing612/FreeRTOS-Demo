/**
	**************************************************************************
	*@file					includes.h
	*@author				
	*@version				v1.0
	*@date					2016.12.27
	*@brief					ͷ�ļ�����
	**************************************************************************
	*/
	#ifndef __INCLUDES_H_
	#define __INCLUDES_H_
	
	/*
	***************************************************************************
	*														Standard Library
	***************************************************************************
	*/
	#include <stdio.h>
	#include <stdarg.h>
	#include <stdlib.h>
	#include <math.h>
	
	/*
	***************************************************************************
	*																OS
	***************************************************************************
	*/
	#include "FreeRTOS.h"
	#include "task.h"
	#include "queue.h"
	#include "croutine.h"
	
	/*
	***************************************************************************
	*																Other
	***************************************************************************
	*/
	#include "task_led.h"
	#include "led.h"
	#include "board.h"
	#include "key.h"
	#include "task_key.h"
	#include "bitband.h"
	#include "delay.h"
	#include "usart1.h"
	
	#endif	/* __INCLUDES_H_  */
	