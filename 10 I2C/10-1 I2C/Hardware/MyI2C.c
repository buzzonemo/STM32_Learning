#include "stm32f10x.h"                  // Device header
#include "Delay.h"


void write_SCL(BitAction value){
	GPIO_WriteBit(GPIOB, GPIO_Pin_6, value);
	Delay_us(20);
}

void write_SDA(BitAction value){
	GPIO_WriteBit(GPIOB, GPIO_Pin_7, value);
	Delay_us(20);
}

uint8_t read_SDA(void){
	uint8_t value;
	value = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_7);
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
	write_SDA(1);
}

void Send_Byte(uint8_t value){
	
	for(uint8_t i = 0; i<8;i++){
		
	}
	write_SDA(value);
	write_SCL(1);
	write_SCL(0);
	
}

void myI2C_read(){
	
}

void MyI2C_Init(){


}
