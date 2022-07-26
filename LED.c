#include "stm32f10x.h"                  // Device header

void Buzzer_Init()
{
	/*
	 * 除特别的另外说明外，以下其他代码程序注释解析请参考LED_Init() 
	 **/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_InitTypeDef GPIOB_InitStructure;
	GPIOB_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIOB_InitStructure.GPIO_Pin = GPIO_Pin_12;
	GPIOB_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIOB_InitStructure);
	
	/*
	 * 以上初始化IO口的工作完成后，IO口会自动置于低电平状态	
	 * 当蜂鸣器模块的IO口杯输入低电平时会发响，高电平时静置
	 * 下面的函数的配置使得该蜂鸣器初始化函数被调用后不至于就马上开始作响
	 **/
 	GPIO_SetBits(GPIOB, GPIO_Pin_12);
}

void on_Buzzer()
{
	GPIO_ResetBits(GPIOB, GPIO_Pin_12);
}

void off_Buzzer()
{
	GPIO_SetBits(GPIOB, GPIO_Pin_12);
}

//用于翻转变化蜂鸣器的状态
void turn_Buzzer()
{
	if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12) == 0)
		GPIO_SetBits(GPIOB, GPIO_Pin_12);
	else
		GPIO_ResetBits(GPIOB, GPIO_Pin_12);
}
	
