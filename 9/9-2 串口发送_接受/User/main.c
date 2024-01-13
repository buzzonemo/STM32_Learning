#include "stm32f10x.h"                  
#include "Delay.h"
#include "OLED.h"
#include "mySerial.h"

extern uint8_t Serial_RxData;
extern uint8_t Serial_RxFlag;
int main(void){

	OLED_Init();
	mySerial_Init();
	
	
	while(1){
		if (Serial_RxFlag == 1){
			Serial_RxFlag = 0;
			OLED_ShowHexNum(1,1,Serial_RxData,4);
		}
	}
}
