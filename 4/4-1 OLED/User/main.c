#include "stm32f10x.h"                  
#include "Delay.h"
#include "OLED.h"


int main(void){

	OLED_Init();
	
	
	uint8_t value;
	while(1){
		OLED_ShowString(1,6,"franky");
		
	}
}
