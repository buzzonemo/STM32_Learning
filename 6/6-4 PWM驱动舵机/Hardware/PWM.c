#include "stm32f10x.h"                  // Device header


void PWM_Init(void){
	
	//1. 时钟使能，gpio口使用GPIO0，复用io口。
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
	//2. 选择时钟源，内部时钟还是外部时钟
	TIM_InternalClockConfig(TIM2);
	
	//3. 配置时基单元
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	//舵机输入信号的频率为 1/0.02 = 50hz
	TIM_TimeBaseInitStruct.TIM_Period = 1999-1; //ARR       72000000 / 720 / x = 50
	TIM_TimeBaseInitStruct.TIM_Prescaler = 720-1; // PSC
	TIM_TimeBaseInitStruct.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStruct);
	
	//4.配置输出比较单元
	TIM_OCInitTypeDef TIM_OCInitStruct;
	TIM_OCStructInit(&TIM_OCInitStruct);
	// 输出比较模式
	TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1;
	//CRR值
	TIM_OCInitStruct.TIM_Pulse = 250;
	//输出使能
	TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable;
	
	TIM_OCInitStruct.TIM_OCPolarity =  TIM_OCPolarity_High;
	TIM_OC2Init(TIM2, &TIM_OCInitStruct);
	
	//5. 配置GPIO
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	// 6. 运行控制
	TIM_Cmd(TIM2, ENABLE);
}

void Set_CRR(uint8_t crr){
	TIM_SetCompare2(TIM2, crr);
}
