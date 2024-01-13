#include "stm32f10x.h"                  
#include "Delay.h"
#include "OLED.h"
#include "AD.h"
#include "myDMA.h"

int main(void){

	OLED_Init();
	
	
	uint16_t value[2];
	myDMA_Init((uint32_t)value);
	AD_Init();
	while(1){
		
		
		OLED_ShowNum(1,6,value[0],6);
		OLED_ShowNum(2,6,value[1],6);
		Delay_ms(200);
	}
}
