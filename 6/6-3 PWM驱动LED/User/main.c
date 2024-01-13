#include "stm32f10x.h"                  
#include "Delay.h"

#include "OLED.h"
#include "PWM.h"

int main(void){

	OLED_Init();
	
	PWM_Init();
	
	while(1){
		for(int i = 0; i< 100;i++){
			TIM_SetCompare1(TIM2, i);
			Delay_ms(10);
		}
		for(int i = 100; i>0;i--){
			TIM_SetCompare1(TIM2, i);
			Delay_ms(10);
		}
		
	}
}
