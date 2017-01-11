代码说明：
	1、程序运行到vTaskList()处时，会进入硬件失效异常HardFault_Handle中，从而导致程序进入HardFault_Handle死循环
	关于HardFalut_Handle，在我的程序中，是由于在创建的任务中定义的任务栈的大小太小导致的，
	2、vTaskList是任务列表函数，此函数的使用需要在FreeRTOSConfig.h中进行如下的宏定义
	#define configUSE_TRACE_FACILITY	1	
	#define configUSE_STATS_FORMATTING_FUNCTIONS						1