#include "stm32f10x.h"                  // Device header

void Light_Init(void){
	// 一、使能GPIOC
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	// 二、配置端口模式
	// 1. 创建GPIO结构体
	GPIO_InitTypeDef GPIO_initStructure;
	GPIO_initStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_initStructure.GPIO_Pin = GPIO_Pin_5;
	GPIO_initStructure.GPIO_Speed = GPIO_Speed_50MHz;
	// 2. 填入参数
	GPIO_Init(GPIOB, &GPIO_initStructure);
	
	//GPIO_Write(GPIOA, ~0x00FF);
}

uint8_t Light_value(void){
	uint8_t value = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5);
	return value;
}