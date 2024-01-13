#include "stm32f10x.h"                  
#include "Delay.h"

unsigned int rotate_left(unsigned int value, int shift) {  
    int bits = (sizeof(value) * 8);  
    return (value << shift) | (value >> (bits - shift));  
}  

int main(void){
	// 一、使能GPIOC
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	// 二、配置端口模式
	// 1. 创建GPIO结构体
	GPIO_InitTypeDef GPIO_initStructure;
	GPIO_initStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_initStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 |GPIO_Pin_6;
	GPIO_initStructure.GPIO_Speed = GPIO_Speed_50MHz;
	// 2. 填入参数
	GPIO_Init(GPIOA, &GPIO_initStructure);
	// 三、设置端口的高低电平来点灯。
	//设置高电平
	//GPIO_SetBits(GPIOA,GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4);
	//设置低电平
	//GPIO_ResetBits(GPIOA,GPIO_Pin_6);
	
	unsigned int number = 0x0001;
	while(1){
		//GPIO_Write(GPIOA, number);
		//number = rotate_left(number,1);
		//Delay_ms(50);
	}
}
