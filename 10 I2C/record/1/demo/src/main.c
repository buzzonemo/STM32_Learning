#include <stdio.h>
#include <stdint.h>

typedef enum {
    BIT_RESET = 0,
    BIT_RET
} BitAction;

void printf_each_bit(uint8_t byte)
/*
    函数功能：
        输入：输入一个字节
        输出：字节上，每一位如果是1就输出1，否则0
*/
{
    uint8_t x;
    for (uint8_t i = 0; i < 8; i++)
    {
        x = byte & (0x80 >> i);
        printf(" ");
    }
    
}

int main(){
    uint8_t byte = 0x12;
    printf_each_bit(byte);
}