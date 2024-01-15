#include "stm32f10x.h"                  // Device header
#include "Delay.h"

//写scl
void write_SCL(BitAction value){
	GPIO_WriteBit(GPIOB, GPIO_Pin_10, value);
	Delay_us(20);
}

//写sda
void write_SDA(BitAction value){
	GPIO_WriteBit(GPIOB, GPIO_Pin_11, value);
	Delay_us(20);
}

//读dsa
uint8_t read_SDA(void){
	uint8_t value;
	value = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11);
	Delay_us(20);
	return value;
}

//开始条件
void myI2C_Start(){
	write_SDA(1);
	write_SCL(1);
	
	write_SDA(0);
	write_SCL(0);
}

//终止条件条件
void myI2C_Stop(){
	write_SDA(0); //终止的条件是SDA发生了变化，如果在scl释放的时候sda就是1，那么就没有变化的过程了。
	write_SCL(1);
	write_SDA(1);//在scl为1的时候，原本sda不许发生变化
}

void Send_Byte(uint8_t value){
	
	for(uint8_t i = 0; i<8;i++){
		write_SDA((BitAction)(value & (0x80 >> i)));
		write_SCL(1);
		//从机读取空隙
		write_SCL(0);
	}
	
}

uint8_t myI2C_Receive(){
	uint8_t byte = 0x00;
	// 假设传过来的是0x 01101101,遵循接受的时候高位先行的原则
	write_SDA(1);
	for(uint8_t i = 0; i<8;i++){
		write_SCL(1);
		//byte =  byte | (read_SDA() << i);
		if (read_SDA() == 1){byte |= (0x80 >> i);}
		write_SCL(0);
	}
	return byte;
}

//接受应答
uint8_t myI2C_RACK(){
	uint8_t ack = 0x00;
	write_SDA(1);
	write_SCL(1);
	ack = read_SDA();
	write_SCL(0);
	return ack;
}

//发送应答
void myI2C_SACK(uint8_t ack){
	write_SDA((BitAction)ack);
	write_SCL(1);
	write_SCL(0);
}
	

void MyI2C_Init(){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_OD;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_OD;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_11;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStruct);
	
	GPIO_SetBits(GPIOB, GPIO_Pin_10|GPIO_Pin_11);
}
