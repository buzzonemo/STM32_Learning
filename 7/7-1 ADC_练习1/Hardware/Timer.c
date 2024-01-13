#include "stm32f10x.h"                  // Device header
#include "stdio.h"
#include "Delay.h"
uint8_t num = 0;

void Timer_Init(){
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStruct.TIM_Period = 10000 -1;
	TIM_TimeBaseInitStruct.TIM_Prescaler = 7200 - 1;
	TIM_TimeBaseInitStruct.TIM_RepetitionCounter = 0;
	
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitStruct);
	
	TIM_SelectOutputTrigger(TIM3, TIM_TRGOSource_Update);
	
	
	TIM_Cmd(TIM3, ENABLE);

}

void TIM3_IRQHandler(){
	if (TIM_GetITStatus(TIM3,TIM_IT_Update) == SET){
		TIM3->EGR |=  (uint16_t)0x0000;
		TIM3->EGR |=  (uint16_t)0x0001;
		TIM3->EGR |=  (uint16_t)0x0000;
		num++;
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
	}
	

}
