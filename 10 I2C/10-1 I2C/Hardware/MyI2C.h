#ifndef __MY_I2C_H_
#define __MY_I2C_H_

#include "stm32f10x.h"                  // Device header
#include "Delay.h"

//写scl
void write_SCL(BitAction value);

//写sda
void write_SDA(BitAction value);

//读dsa
uint8_t read_SDA(void);

//开始条件
void myI2C_Start();

//终止条件条件
void myI2C_Stop();

void Send_Byte(uint8_t value);

uint8_t myI2C_Receive();

//接受应答
uint8_t myI2C_RACK();

//发送应答
void myI2C_SACK(uint8_t ack);
	

void MyI2C_Init();


#endif
