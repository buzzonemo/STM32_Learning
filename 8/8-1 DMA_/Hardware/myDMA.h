#ifndef __MY_DMA_H
#define __MY_DMA_H
void MyDMA_Init(uint32_t DMA_MemoryBaseAddr, uint32_t DMA_PeripheralBaseAddr, uint16_t size);
void MyDMA_Transfer();
#endif
