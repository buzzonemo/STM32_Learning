#include "stm32f10x.h"                  // Device header
#include "PWM.h"

void Servo_Init(void){
	PWM_Init();
}

// 0度    50
// 180度  250
void Servo_SetAngle(float angle){
	Set_CRR((angle / 180) * 200 + 50);
}
