#include "stm32f10x.h"                  
#include "Delay.h"

#include "OLED.h"
#include "Encoder.h"

int main(void){

	OLED_Init();
	Encoder_Init();
	
	
	int8_t number;
	while(1){
		number += ReturnNum(); 
		OLED_ShowString(1,6,"franky");
		OLED_ShowSignedNum(3,3,number,5);
	}
}
