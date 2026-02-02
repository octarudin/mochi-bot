#include "ttp223.h"

volatile bool touchTriggered = false;
volatile unsigned long lastISRTime = 0;

bool initTouchSensor() {
    // Use INPUT_PULLDOWN to prevent floating pin noise
    pinMode(TOUCH_PIN_1, INPUT_PULLDOWN);
    pinMode(TOUCH_PIN_2, INPUT_PULLDOWN);
    pinMode(TOUCH_PIN_3, INPUT_PULLDOWN);

    // Attach external interrupt on touch pin (RISING edge only, saat tersentuh)
    attachInterrupt(digitalPinToInterrupt(TOUCH_PIN_1), touchISR, RISING);
    attachInterrupt(digitalPinToInterrupt(TOUCH_PIN_2), touchISR, RISING);
    attachInterrupt(digitalPinToInterrupt(TOUCH_PIN_3), touchISR, RISING);
    
    return true; // Assuming initialization is always successful
}

/// @brief Checks if a touch event has been triggered
/// @return True if a touch event was triggered, false otherwise
bool checkTouch() 
{
  return touchTriggered; 
}

/// @brief Interrupt Service Routine for touch input dengan debouncing
/// @return 
void IRAM_ATTR touchISR() 
{
  unsigned long now = millis();
  // Debounce 50ms di ISR level untuk filter noise
  if (now - lastISRTime > 50) {
    touchTriggered = true;
    lastISRTime = now;
  }
}