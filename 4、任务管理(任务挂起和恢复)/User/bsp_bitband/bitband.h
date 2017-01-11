/**
	*******************************************************************
	*@file			bitband.c
	*@author		
	*@version		v1.0
	*@date			2017.01.02
	*@brief			FreeRTOS 任务管理
	*******************************************************************
	*/
	#ifndef __BITBAND_H_
	#define __BITBAND_H_
	
	#include "stm32f10x.h"
	/*
	*以下一些宏定义为位带操作，实现类似于51的GPIO口的操作
	*/
	//IO 口基本操作宏定义
	#define BITBAND(addr,bitnum)		((addr&0xf0000000)+0x20000000+((addr&0xfffff)<<5)+(bitnum<<2))
	#define MEM_ADDR(addr)			*((volatile unsigned long *)(addr))
	#define BIT_ADDR(addr,bitnum)		MEM_ADDR(BITBAND(addr,bitnum))

	//IO口地址映射
	#define GPIOA_ODR_ADDR		(GPIOA_BASE+12)			//0X4001080C
	#define GPIOB_ODR_ADDR		(GPIOB_BASE+12)			//0X40010C0C
	#define GPIOC_ODR_ADDR		(GPIOC_BASE+12)			//0X4001100C
	#define GPIOD_ODR_ADDR		(GPIOD_BASE+12)			//0X4001140C
	#define GPIOE_ODR_ADDR		(GPIOE_BASE+12)			//0X4001180C
	#define GPIOF_ODR_ADDR		(GPIOF_BASE+12)			//0X40011A0C
	#define GPIOG_ODR_ADDR		(GPIOG_BASE+12)			//0X40011E0C

	#define GPIOA_IDR_ADDR		(GPIOA_BASE+8)			//0X40010808
	#define GPIOB_IDR_ADDR		(GPIOB_BASE+8)			//0X40010C08
	#define GPIOC_IDR_ADDR		(GPIOC_BASE+8)			//0X40011008
	#define GPIOD_IDR_ADDR		(GPIOD_BASE+8)			//0X40011408
	#define GPIOE_IDR_ADDR		(GPIOE_BASE+8)			//0X40011808
	#define GPIOF_IDR_ADDR		(GPIOF_BASE+8)			//0X40011A08
	#define GPIOG_IDR_ADDR		(GPIOG_BASE+8)			//0X40011E08

	//IO口操作，只对单一的IO口，确保n值小于16
	#define PAout(n)		BIT_ADDR(GPIOA_ODR_ADDR,n)			//输出
	#define PAin(n)			BIT_ADDR(GPIOA_IDR_ADDR,n)			//输入

	#define PBout(n)		BIT_ADDR(GPIOB_ODR_ADDR,n)			//输出
	#define PBin(n)			BIT_ADDR(GPIOB_IDR_ADDR,n)			//输入

	#define PCout(n)		BIT_ADDR(GPIOC_ODR_ADDR,n)			//输出
	#define PCin(n)			BIT_ADDR(GPIOC_IDR_ADDR,n)			//输入

	#define PDout(n)		BIT_ADDR(GPIOD_ODR_ADDR,n)			//输出
	#define PDin(n)			BIT_ADDR(GPIOD_IDR_ADDR,n)			//输入

	#define PEout(n)		BIT_ADDR(GPIOE_ODR_ADDR,n)			//输出
	#define PEin(n)			BIT_ADDR(GPIOE_IDR_ADDR,n)			//输入

	#define PFout(n)		BIT_ADDR(GPIOF_ODR_ADDR,n)			//输出
	#define PFin(n)			BIT_ADDR(GPIOF_IDR_ADDR,n)			//输入

	#define PGout(n)		BIT_ADDR(GPIOG_ODR_ADDR,n)			//输出
	#define PGin(n)			BIT_ADDR(GPIOG_IDR_ADDR,n)			//输入


	#endif	/* __BITBAND_H_ */
	