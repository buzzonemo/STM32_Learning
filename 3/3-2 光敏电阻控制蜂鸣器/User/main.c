#include "stm32f10x.h"                  
#include "Delay.h"
#include "Buzzer.h"
#include "light.h"
#include "Led.h"

int main(void){

	BUZZER_Init();
	Light_Init();
	Led_Init();
	
	
	uint8_t value;
	while(1){
		
		if (Light_value() == 1){
			Led_ON();
		}else{
			Led_OFF();
		}
		
	}
}
