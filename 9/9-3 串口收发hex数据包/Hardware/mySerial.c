#include "stm32f10x.h"                  // Device header

uint8_t HexPacket[] = {0x01, 0x02, 0x23, 0x43};
uint8_t Signal = 0;
uint8_t nums;
uint8_t RxData;
uint8_t RxFlag = 0;
uint8_t RxData_packet[4];

uint8_t debug;

void mySerial_Init(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_USART1, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	USART_InitTypeDef USART_InitStruct;
	USART_InitStruct.USART_BaudRate = 9600;
	USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStruct.USART_Parity = USART_Parity_No;
	USART_InitStruct.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
	USART_InitStruct.USART_StopBits = USART_StopBits_1;
	USART_InitStruct.USART_WordLength = USART_WordLength_8b;
	USART_Init(USART1, &USART_InitStruct);
	
	//配置中断位
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
	
	//配置中断优先级
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_InitTypeDef NVIC_InitStruct;
	NVIC_InitStruct.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd = 2;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = ENABLE;
	NVIC_Init(&NVIC_InitStruct);
	
	USART_Cmd(USART1, ENABLE);
}

void Send_ByteData(uint8_t data){
	USART_SendData(USART1, data);
	while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET );
}

void Send_ByteArray(uint8_t *array, uint8_t length){
	for(uint8_t i = 0; i < length ;i++){
		Send_ByteData(array[i]);
	}

}

void Send_MySrting(char *string){
	for(uint8_t i = 0; string[i] != '\0';i++){
		Send_ByteData(string[i]);
	}
}


//发送数据包
void Send_HexPacket(void){
	Send_ByteData(0xFF);
	for(uint8_t i = 0; i < 4; i++){
		Send_ByteData(HexPacket[i]);
	}
	Send_ByteData(0xFE);
}

//接受数据包
void Receive_HexPacket(void){
	
}

void USART1_IRQHandler(){
	debug++;
	if(USART_GetFlagStatus(USART1, USART_IT_RXNE) == SET){
		RxData = USART_ReceiveData(USART1);
		
		switch(Signal){
			case 0 :{
				if (RxData == 0xFF){
					Signal = 1;
					nums = 0;
				}
			}break;
			case 1 :{
				//对数据进行存储
				RxData_packet[nums] = RxData;
				nums++;
				if (nums >= 4){
					Signal = 2;
				}
			}
			case 2 : {
				if (RxData == 0xFE){
					Signal = 0;
					RxFlag = 1;
				}
			}
		}
	
	}
}
