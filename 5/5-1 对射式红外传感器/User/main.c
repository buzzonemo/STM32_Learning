#include "stm32f10x.h"                  
#include "Delay.h"
#include "OLED.h"
#include "CounterSensor.h"

extern uint8_t count;

int main(void){

	CounterSensor_Init();
	OLED_Init();
	while(1){
		OLED_ShowString(1,6,"franky");
		OLED_ShowNum(2,1,count,5);
	}
}
