#ifndef _DRIVERS_ACTIVE_BUZZER_H_
#define _DRIVERS_ACTIVE_BUZZER_H_

#include <Arduino.h>

#define BUZZER_PIN   4 // GPIO 4

bool initSound();
void heartbeatSound();
void errorSound();
void shakeSound();

#endif // _DRIVERS_ACTIVE_BUZZER_H_