#include "stm32f10x.h"                  
#include "Delay.h"

#include "OLED.h"
#include "PWM.h"
#include "Servo.h"

int main(void){

	OLED_Init();
	
	Servo_Init();

	while(1){
		for(int i = 0 ; i< 180;i+=10){
			Servo_SetAngle(i);
			Delay_ms(150);
			if(i == 180) {i = 0;}
		}
		
	}
}
