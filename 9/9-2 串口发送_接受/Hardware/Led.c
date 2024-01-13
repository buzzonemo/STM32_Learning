#include "stm32f10x.h"                  // Device header
#include "Delay.h"
void Led_Init(void){
	// 一、使能GPIOC
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	// 二、配置端口模式
	// 1. 创建GPIO结构体
	GPIO_InitTypeDef GPIO_initStructure;
	GPIO_initStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_initStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 |GPIO_Pin_6;
	GPIO_initStructure.GPIO_Speed = GPIO_Speed_50MHz;
	// 2. 填入参数
	GPIO_Init(GPIOA, &GPIO_initStructure);
	
	//GPIO_Write(GPIOA, ~0x00FF);
}



void Led_ON(void){
	GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_SET);
	GPIO_WriteBit(GPIOA, GPIO_Pin_2, Bit_SET);
	GPIO_WriteBit(GPIOA, GPIO_Pin_3, Bit_SET);
	GPIO_WriteBit(GPIOA, GPIO_Pin_4, Bit_SET);
	GPIO_WriteBit(GPIOA, GPIO_Pin_6, Bit_SET);
}

void Led_OFF(void){
	GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_RESET);
	GPIO_WriteBit(GPIOA, GPIO_Pin_2, Bit_RESET);
	GPIO_WriteBit(GPIOA, GPIO_Pin_3, Bit_RESET);
	GPIO_WriteBit(GPIOA, GPIO_Pin_4, Bit_RESET);
	GPIO_WriteBit(GPIOA, GPIO_Pin_6, Bit_RESET);
}

void Led_Turn(void){
	if (GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_0) == 0 ){
		GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_SET);
		GPIO_WriteBit(GPIOA, GPIO_Pin_2, Bit_SET);
		GPIO_WriteBit(GPIOA, GPIO_Pin_3, Bit_SET);
		GPIO_WriteBit(GPIOA, GPIO_Pin_4, Bit_SET);
		GPIO_WriteBit(GPIOA, GPIO_Pin_5, Bit_SET);
		GPIO_WriteBit(GPIOA, GPIO_Pin_6, Bit_SET);
		
	}else{
		GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_RESET);
		GPIO_WriteBit(GPIOA, GPIO_Pin_2, Bit_RESET);
		GPIO_WriteBit(GPIOA, GPIO_Pin_3, Bit_RESET);
		GPIO_WriteBit(GPIOA, GPIO_Pin_4, Bit_RESET);
		GPIO_WriteBit(GPIOA, GPIO_Pin_5, Bit_RESET);
		GPIO_WriteBit(GPIOA, GPIO_Pin_6, Bit_RESET);
	}	
}


void Switch_Init(void){
	// 一、使能GPIOC
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	// 二、配置端口模式
	// 1. 创建GPIO结构体
	GPIO_InitTypeDef GPIO_initStructure;
	GPIO_initStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_initStructure.GPIO_Pin = GPIO_Pin_1;
	GPIO_initStructure.GPIO_Speed = GPIO_Speed_50MHz;
	// 2. 填入参数
	GPIO_Init(GPIOB, &GPIO_initStructure);
	
}

uint8_t Switch_press(void){
	uint8_t Key_Num = 0;
	if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 0){
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 0);
		Delay_ms(20);
		Key_Num = 1;
	}
	return Key_Num;
	
}
