#include "stm32f10x.h"                  

int main(void){
	// 一、使能GPIOC
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	// 二、配置端口模式
	// 1. 创建GPIO结构体
	GPIO_InitTypeDef GPIO_initStructure;
	GPIO_initStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_initStructure.GPIO_Pin = GPIO_Pin_13;
	GPIO_initStructure.GPIO_Speed = GPIO_Speed_50MHz;
	// 2. 填入参数
	GPIO_Init(GPIOC, &GPIO_initStructure);
	// 三、设置端口的高低电平来点灯。
	//设置高电平
	GPIO_SetBits(GPIOC,GPIO_Pin_13);
	//设置低电平
	//GPIO_ResetBits(GPIOC,GPIO_Pin_13);
	while(1){
	
	}
}
