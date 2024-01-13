#include "stm32f10x.h"                  
#include "Delay.h"
#include "OLED.h"
#include "CounterSensor.h"



int16_t num ;
int main(void){

	CounterSensor_Init();
	OLED_Init();
	OLED_ShowString(1,6,"franky");
	
	while(1){
		num += getNum();
		
		
		OLED_ShowSignedNum(2,5,num,5);
	}
}
