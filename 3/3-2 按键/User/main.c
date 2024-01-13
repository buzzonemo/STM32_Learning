#include "stm32f10x.h"                  
#include "Delay.h"
#include "Led.h"


uint8_t KeyNum = 0;
int main(void){
	Led_Init();
	Switch_Init();
	while(1){
		//Led_ON();
		//Led_OFF();
		KeyNum = Switch_press();
		if (KeyNum == 1){
			Led_Turn();
		}
	}
}
