#include "stm32f10x.h"                  // Device header

void AD_Init(void){
	//时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1|RCC_APB2Periph_GPIOA, ENABLE);
	
	//ADC分频
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);
	
	//配置GPIO
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AIN; //模拟输入
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	//配置规则组
	ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 1, ADC_SampleTime_55Cycles5);
	
	//配置ADC
	ADC_InitTypeDef ADC_InitStruct;
	ADC_InitStruct.ADC_ContinuousConvMode = DISABLE; //是否为连续模式
	ADC_InitStruct.ADC_DataAlign = ADC_DataAlign_Right; //数据对齐方式
	ADC_InitStruct.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
	ADC_InitStruct.ADC_Mode = ADC_Mode_Independent;
	ADC_InitStruct.ADC_NbrOfChannel = 1;  //需要模数转换的ADC通道的数目
	ADC_InitStruct.ADC_ScanConvMode = DISABLE; //是否为扫描模式
	ADC_Init(ADC1, &ADC_InitStruct);
	
	//开启ADC
	ADC_Cmd(ADC1, ENABLE); 
	
	//校准
	ADC_ResetCalibration(ADC1);   // 复位指定的ADC的校准寄存器
	while(ADC_GetResetCalibrationStatus(ADC1));   // 获取ADC重置校准寄存器的状态
		
	ADC_StartCalibration(ADC1);   // 开始指定ADC的校准状态
	while(ADC_GetCalibrationStatus(ADC1));   // 获取指定ADC的校准程序
	
}

uint16_t AD_GetValue(void){
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);					//软件触发AD转换一次
	while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET);	//等待EOC标志位，即等待AD转换结束
	return ADC_GetConversionValue(ADC1);
}
