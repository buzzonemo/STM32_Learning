#include "stm32f10x.h"                  // Device header



void AD_Init(){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

	
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);
	
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AIN;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 1, ADC_SampleTime_55Cycles5);		//规则组序列1的位置，配置为通道0
	ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 2, ADC_SampleTime_55Cycles5);
	
	
	//4配置ADC
	ADC_InitTypeDef ADC_InitStructure;
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;   // 独立模式。单ADC的意思，区别于双ADC
	ADC_InitStructure.ADC_ScanConvMode = ENABLE;   // 扫描模式	
	ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;   // 关闭连续转换
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;   // 禁止外部触发检测，使用软件触发
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;   // 右对齐	
	ADC_InitStructure.ADC_NbrOfChannel = 2;   // 1个转换在规则序列中 也就是只转换规则序列1 
	ADC_Init(ADC1, &ADC_InitStructure);   // ADC初始化
	

	
	//5开启ADC
	ADC_DMACmd(ADC1, ENABLE);
	ADC_Cmd(ADC1, ENABLE); 
	
	//6校准adc
	ADC_ResetCalibration(ADC1);   // 复位指定的ADC的校准寄存器
	while(ADC_GetResetCalibrationStatus(ADC1));   // 获取ADC重置校准寄存器的状态
		
	ADC_StartCalibration(ADC1);   // 开始指定ADC的校准状态
	while(ADC_GetCalibrationStatus(ADC1));   // 获取指定ADC的校准程序
	
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);
	
}

uint16_t AD_GetValue(){
	return ADC_GetConversionValue(ADC1);
}
