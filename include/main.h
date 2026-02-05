#ifndef _MAIN_H_
#define _MAIN_H_

#include <Arduino.h>
#include <Wire.h> 
#include "assets.h"     // load all GIF assets
#include "helpers.h"    // load helper functions
#include "drivers.h"    // load all drivers (OLED, MPU6050, etc.)

// Event queue untuk inter-task communication
enum EventType {
  EVENT_SHAKE,
  EVENT_TOUCH,
  EVENT_STANDBY
};

typedef struct {
  EventType type;
  unsigned long timestamp;
} Event;

// Queue dan mutex handles
extern QueueHandle_t eventQueue;
extern SemaphoreHandle_t displayMutex;

// Interrupt flag untuk stop animasi dengan cepat
extern volatile bool interruptAnimation;

#endif // _MAIN_H_