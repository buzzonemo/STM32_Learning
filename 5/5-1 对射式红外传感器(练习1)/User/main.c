#include "stm32f10x.h"                  
#include "Delay.h"

#include "OLED.h"
#include "InfraredSensor.h"


extern uint8_t num;
int main(void){
	
	OLED_Init();
	InfraredSensor_Init();
	
	
	while(1){
		OLED_ShowString(1,6,"franky");
		OLED_ShowNum(2,2,num,3);
	}
}
