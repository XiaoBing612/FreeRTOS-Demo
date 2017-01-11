总结：1、在LED工程中所需要的外设有GPIO,外设时钟RCC.
	  2、所需要的外设头文件有stm32f10x_gpio.h,stm32f10x_rcc.h
	  
	  
知识点：
		一、GPIO(以STM32F103为例)
		1、STM32的GPIO有GPIOA,GPIOB,GPIOC,GPIOD,GPIOE,GPIOF.每组端口分为0~15共16个不同的引脚
		2、STM32的工作模式有8种，分别为4种输入，4种输出模式。具体如下：
				4种输入模式：
					输入浮空
					输入上拉
					输入下拉
					模拟输入
				4种输出模式：
					开漏输出
					开漏复用功能
					推挽式输出
					推挽式复用功能
		注意：推挽输出可以输出高低电平，连接数字器件。
			  开漏输出只可以输出强低电平，高电平得靠外部电阻拉高。输出端相当于三极管的集电极，
			要得到高电平状态需要上拉电阻才行，适合于做电流型的驱动，其吸收电流的能力相对强。
			(一般20ma以内)
		3、具有3种最大翻转速度
				2MHz
				10MHz
				50MHz
		4、每组GPIO端口的寄存器有：
				两个32位的配置寄存器(GPIOx_CRL,GPIOx_CRH)
				两个32位的数据寄存器(GPIOx_IDR,GPIOx_ODR)
				一个32位的置位/复位寄存器(GPIOx_BSRR)
				一个16位的复位寄存器(GPIOx_BRR)
				一个32位的锁定寄存器(GPIOx_LCKR)
		注意：每个I/O端口位可以自由编程，然而I/O端口寄存器必须按32位字被访问(不允许半字或字节访问)
		5、GPIO的相关配置寄存器
				GPIOx_CRL:端口配置低寄存器
				GPIOx_CRH:端口配置高寄存器
				GPIOx_IDR:端口输入寄存器
				GPIOx_ODR:端口输出寄存器
				GPIOx_BSRR:端口位设置/清除寄存器
				GPIOx_BRR:端口位清除寄存器
				GPIOx_LCKR:端口配置锁存寄存器
		二、时钟系统
		1、4个时钟源：
				1)高速外设时钟(HSE)：以外部晶振作为时钟源，晶振频率可取范围为4~16MHz，我们一般采用8MHz
				2)高速内部时钟(HSI)：由内部RC振荡器产生，频率为8MHz,但不稳定
				3)低速外部时钟(LSE)：以外部晶振作为时钟源，主要提供给实时时钟模块，所以一般采用32.768kHz
				4)低速内部时钟(LSI)：由内部RC振荡器产生，也主要提供给实时时钟模块，频率大约为40kHz
		2、时钟
				1)SYSCLK：系统时钟，是STM32大部分器件的时钟来源，主要由AHB预分频器分配到各个部件
				2)HCLK：由AHB预分频器直接输出得到，它是高速总线AHB的时钟信号，提供给存储器、DMA及Cortex内
			核，是Cortex内核运行的时钟，CPU主频就是这个信号。它的大小与STM32运算速度、数据存取速度密切相关
				3)FCLK：同样由AHB预分频器输出得到，是内核的"自由运行时钟"。"自由"表现在它不来自时钟HCLK,因
			此在HCLK时钟停止时FCLK也继续运行。它的存在可以保证，在处理器休眠时也能够采样到和跟踪休眠事件，
			它与HCLK互相同步
				4)PCLK1：外设时钟，由APB1预分频器输出得到，最大频率为36MHz，提供给挂载在APB1总线上的外设
				5)PCLK2：外设时钟，由APB2预分频器输出得担，最大频率可为72MHz,提供给挂载在APB2总线上的外设
		说明：GPIO挂载在APB2总线上
		三、所涉及到的C语言知识
		1、volatile：主要是防止编译器优化，具体知识点可参考学习笔记之volatile
		2、结构体：见学习笔记(待续)
		3、枚举：见学习笔记(待续)
		四、所涉及到的一些固件库函数
		void GPIO_SetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
		void GPIO_ResetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
		void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct);
		void RCC_APB2PeriphClockCmd(uint32_t RCC_APB2Periph, FunctionalState NewState);