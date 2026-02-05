#ifndef _DRIVERS_MPU6050_VIBRATIONS_H_
#define _DRIVERS_MPU6050_VIBRATIONS_H_

#include "../drivers/utils.h"

// Shake detection threshold dan settings
#define SHAKE_THRESHOLD 14.0f
#define SHAKE_DEBOUNCE_MS 1000

bool initVibrationSensor(U8G2_SH1106_128X64_NONAME_F_HW_I2C* display);
float getVibrationMagnitude();
void updateDisplay(U8G2_SH1106_128X64_NONAME_F_HW_I2C* display, float magnitude, bool isVibrating);
bool checkShake();
void startShakeMonitorTask();
void IRAM_ATTR handleShakeISR();

extern Adafruit_MPU6050* mpu;
extern volatile bool shakeTriggered;

#endif // _DRIVERS_MPU6050_VIBRATIONS_H_