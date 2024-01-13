#include "stm32f10x.h"                  
#include "Delay.h"
#include "OLED.h"
#include "Timer.h"
#include "AD.h"


int main(void){

	OLED_Init();
	
	
	//Adc_Init();
	AD_Init();
	Timer_Init();
	
	
	while(1){
		OLED_ShowNum(1,1,ADC_GetConversionValue(ADC1),4);
		
	}
}
