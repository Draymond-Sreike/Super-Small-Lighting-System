#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "LED.h"
#include "Key.h"
#include "Buzzer.h"
#include "LightSensor.h"

int main()
{
	Buzzer_Init();
	LightSensor_Init();
	while(1)
	{
		//如果环境亮度较低，则蜂鸣器工作
		if(get_LightSensor() == 0)
		{
			on_Buzzer();
		}
		else
		{
			off_Buzzer();
		}
	}
}
