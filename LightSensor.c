#include "stm32f10x.h"                  // Device header

void LightSensor_Init()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_InitTypeDef GPIOB_InitStructure;
	GPIOB_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIOB_InitStructure.GPIO_Pin = GPIO_Pin_13;
	GPIOB_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIOB_InitStructure);
}

uint8_t get_LightSensor()
{
	/*
	 * 光敏传感模块当察觉环境亮度较亮时其会对外输出低电平，亮度较暗反之
	 * 为了便于人类逻辑快速反应，我们对其反馈值取反
	 * 即高亮返回高电平，低亮反回低电平
	 **/
	return !(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_13));
}
