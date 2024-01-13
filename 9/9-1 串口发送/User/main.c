#include "stm32f10x.h"                  
#include "Delay.h"
#include "OLED.h"
#include "mySerial.h"

int main(void){

	OLED_Init();
	mySerial_Init();
	
	uint8_t data = 0x01;
	
	Send_ByteData(data);
	
	uint8_t array[] = {0x01, 0x05};
	Send_ByteArray(array, 2);
	
	char *string = "Thrall";
	Send_MySrting(string);
	
	while(1){
		
		
	}
}
