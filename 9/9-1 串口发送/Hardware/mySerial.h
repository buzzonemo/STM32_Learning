#ifndef __MY_SERIAL_H
#define __MY_SERIAL_H

void mySerial_Init(void);
void Send_ByteData(uint8_t data);
void Send_ByteArray(uint8_t *array, uint8_t length);
void Send_MySrting(char *string);
#endif
