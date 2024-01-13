#include "stm32f10x.h"                  
#include "Delay.h"
#include "OLED.h"
#include "myDMA.h"

uint8_t a[] = {1,2,3,4};
uint8_t b[] = {0,0,0,0};


void show_(int line, uint8_t data[]);

int main(void){
	
	OLED_Init();
	OLED_ShowString(1,1,"DataA");
	OLED_ShowString(2,1,"DataB");
	
	OLED_ShowHexNum(1,7, (uint32_t)a, 8);
	OLED_ShowHexNum(2,7, (uint32_t)b, 8);
	
	MyDMA_Init((uint32_t)a, (uint32_t)b , 4);
	
	uint8_t value;
	while(1){
		a[0]++;
		a[1]++;
		a[2]++;
		a[3]++;
		
		show_(3, a);
		show_(4, b);
		Delay_ms(200);
		
		MyDMA_Transfer();
		
		Delay_ms(200);
		show_(3, a);
		show_(4, b);
		
	}
}

void show_(int line, uint8_t data[]){
	OLED_ShowNum(line,1,data[0],1);
	OLED_ShowNum(line,3,data[1],1);
	OLED_ShowNum(line,5,data[2],1);
	OLED_ShowNum(line,7,data[3],1);
}
