#include "stm32f10x.h"                  
#include "Delay.h"
#include "OLED.h"
#include "AD.h"

int main(void){

	OLED_Init();
	
	AD_Init();
	
	while(1){
		uint16_t value = AD_GetValue();
		float votage = ( (float)value / 4095) * 3.3;
		OLED_ShowNum(1,1,value,6);
		OLED_ShowNum(2,1,votage,1);
		OLED_ShowNum(2,3,(uint16_t)(votage * 100) % 100,2);
		
		Delay_ms(200);
	}
}
