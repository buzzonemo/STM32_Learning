#include "stm32f10x.h"                  
#include "Delay.h"
#include "OLED.h"
#include "PWM.h"
#include "IC.h"
int main(void){

	OLED_Init();
	
	PWM_Init();
	IC_Init();
	
	while(1){
		uint16_t value  = get_frequency();
		OLED_ShowSignedNum(1,2,value,8);
		
	}
}
