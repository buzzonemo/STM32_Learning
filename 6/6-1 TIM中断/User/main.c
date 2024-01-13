#include "stm32f10x.h"                  
#include "Delay.h"
#include "Timer.h"
#include "OLED.h"

int main(void){

	OLED_Init();
	
	Timer_Init();
	
	extern uint8_t num;
	uint8_t minute;
	while(1){
		OLED_ShowString(1,6,"secends");
		OLED_ShowNum(2,3,num,3);
		OLED_ShowString(3,6,"minute");
		if (num >= 60){
			num = 0;
			minute++;
		}
		OLED_ShowNum(4,3,minute,3);
	}
}
