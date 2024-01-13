#include "stm32f10x.h"                  // Device header

uint16_t buffersize;

void MyDMA_Init(uint32_t DMA_MemoryBaseAddr, uint32_t DMA_PeripheralBaseAddr, uint16_t size){
	
	//注意是AHBP
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
	
	buffersize = size;
	DMA_InitTypeDef DMA_InitStruct;
	DMA_InitStruct.DMA_BufferSize = buffersize; //缓存区大小，其实是传输计数器。
	DMA_InitStruct.DMA_DIR = DMA_DIR_PeripheralDST; //传输方向,说明外设是源还是目的
	DMA_InitStruct.DMA_M2M = DMA_M2M_Enable;//是否软件中断
	
	//存储器 地址 数据宽度 是否自增
	DMA_InitStruct.DMA_MemoryBaseAddr = DMA_MemoryBaseAddr;
	DMA_InitStruct.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
	DMA_InitStruct.DMA_MemoryInc = DMA_MemoryInc_Enable; //是否自增
	
	DMA_InitStruct.DMA_Mode = DMA_Mode_Normal; //模式，是循环还是一次
	
	//外设   地址 数据宽度 是否自增
	DMA_InitStruct.DMA_PeripheralBaseAddr = DMA_PeripheralBaseAddr;
	DMA_InitStruct.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
	DMA_InitStruct.DMA_PeripheralInc = DMA_PeripheralInc_Enable;
	
	DMA_InitStruct.DMA_Priority = DMA_Priority_High;

	DMA_Init(DMA1_Channel1, &DMA_InitStruct);
	
	
}

void MyDMA_Transfer(){
	DMA_Cmd(DMA1_Channel1, DISABLE);
	DMA_SetCurrDataCounter(DMA1_Channel1, buffersize);
	DMA_Cmd(DMA1_Channel1, ENABLE);
	
	//等待转运
	while ( DMA_GetFlagStatus(DMA1_FLAG_TC1) == RESET);
	//转运后需要手动把标志位清除了
	DMA_ClearFlag(DMA1_FLAG_TC1);
	
}
