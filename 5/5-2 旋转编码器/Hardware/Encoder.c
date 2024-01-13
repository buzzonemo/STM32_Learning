#include "stm32f10x.h"       // Device header

int16_t count;

void CounterSensor_Init(void){
	// 第一步：使能GPIO和AFIO的时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	// 第二步：配置GPIO
	GPIO_InitTypeDef  GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	// 第三步：配置AFIO
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource0);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource1);
	
	// 第四步：配置EXTI
	EXTI_InitTypeDef EXTI_InitStructure;
	EXTI_InitStructure.EXTI_Line = EXTI_Line0 | EXTI_Line1;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	
	EXTI_Init(&EXTI_InitStructure);
	
	// 第五步：配置NVIC
	// 设置中断优先级的组
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	// 创建结构体
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStructure);
	
	

	NVIC_InitStructure.NVIC_IRQChannel = EXTI1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	NVIC_Init(&NVIC_InitStructure);
	

}


int16_t getNum(){
	int16_t temp ;
	temp= count;
	count = 0;
	return temp;
	

}

void EXTI0_IRQHandler(){
	if (EXTI_GetITStatus(EXTI_Line0) == SET){

		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0) == 0){
		
			
			if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 0 ){
			
				count --;
			}
		
		}
		EXTI_ClearITPendingBit(EXTI_Line0);	
		
	}
	
}

void EXTI1_IRQHandler(){
	if (EXTI_GetITStatus(EXTI_Line1) == SET){
		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 0){
			if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0) == 0 ){
				count ++;
			}
		
		}
		EXTI_ClearITPendingBit(EXTI_Line1);	
	}
	
}

