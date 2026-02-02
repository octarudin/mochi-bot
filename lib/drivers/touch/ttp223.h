#ifndef _DRIVERS_TOUCH_H_
#define _DRIVERS_TOUCH_H_

#include <Arduino.h>

#define TOUCH_PIN_1  1 // GPIO 1
#define TOUCH_PIN_2  2 // GPIO 2
#define TOUCH_PIN_3  3 // GPIO 3

bool initTouchSensor();
bool checkTouch();
void IRAM_ATTR touchISR();

extern volatile bool touchTriggered;
extern volatile unsigned long lastISRTime;

#endif //_DRIVERS_TOUCH_H_