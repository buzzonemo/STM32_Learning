#ifndef _MPU6050_H
#define _MPU6050_H

uint8_t MPU6050_ReadReg(uint8_t address);
void MPU6050_WriteReg(uint8_t Reg_address, uint8_t data);
void MPU6050_Init(void);
void MPU6050_GetData(int16_t *AccX, int16_t *AccY, int16_t *AccZ, 
						int16_t *GyroX, int16_t *GyroY, int16_t *GyroZ);
uint8_t MPU6050_GetID(void);

#endif
