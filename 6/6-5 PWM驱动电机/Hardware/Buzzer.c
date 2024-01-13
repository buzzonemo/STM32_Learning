#include "stm32f10x.h"  

void BUZZER_Init(void){
	// 一、使能GPIOC
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	// 二、配置端口模式
	// 1. 创建GPIO结构体
	GPIO_InitTypeDef GPIO_initStructure;
	GPIO_initStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_initStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_initStructure.GPIO_Speed = GPIO_Speed_50MHz;
	// 2. 填入参数
	GPIO_Init(GPIOB, &GPIO_initStructure);
	
	GPIO_SetBits(GPIOB,GPIO_Pin_6);
}

void BUZZER_OFF(void){
	GPIO_SetBits(GPIOB, GPIO_Pin_6);
}

void BUZZER_ON(void){
	GPIO_ResetBits(GPIOB, GPIO_Pin_5);
}
