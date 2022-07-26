#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "LED.h"
#include "Key.h"

//设置按键变量，用于记录从key_GetKeyNum()函数中返回的某个按键
uint8_t keyFlag = 0;

int main()
{
	LED_Init();
	key_Init(); 
	
	while(1)
	{
		//接收按键函数返回的按键信息
		keyFlag = key_GetKeyNum();
		
		//如果是按键1按下，翻转LED1的引脚电平状态
		if(keyFlag == 1)
		{
			turn_LED1();
		}
		
		//如果是按键2按下，翻转LED2的引脚电平状态
		if(keyFlag == 2)
		{
			turn_LED2();
		}
	}
}
