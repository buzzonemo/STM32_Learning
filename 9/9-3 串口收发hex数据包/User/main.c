#include "stm32f10x.h"                  
#include "Delay.h"
#include "OLED.h"
#include "mySerial.h"


extern uint8_t RxFlag;
extern uint8_t RxData_packet[4];
extern uint8_t debug;

int main(void){

	OLED_Init();
	mySerial_Init();
	
	Send_HexPacket();
	while(1){
		if (RxFlag){
			OLED_ShowHexNum(1,1,RxData_packet[0],2);
			OLED_ShowHexNum(1,4,RxData_packet[1],2);
			OLED_ShowHexNum(1,7,RxData_packet[2],2);
			OLED_ShowHexNum(1,10,RxData_packet[3],2);
			RxFlag = 0;
		}
		
		OLED_ShowHexNum(2,1,debug,2);
		
	}
}
