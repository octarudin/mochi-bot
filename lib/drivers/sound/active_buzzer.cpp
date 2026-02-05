#include "active_buzzer.h"

/// @brief Initialize the active buzzer
/// @return true if initialization is successful
bool initSound() 
{
    pinMode(BUZZER_PIN, OUTPUT);
    heartbeatSound();
    return true; 
}

/// @brief Play a heartbeat sound pattern on the active buzzer
void heartbeatSound()
{
    // first beat
    digitalWrite(BUZZER_PIN, HIGH); delay(1000);
    digitalWrite(BUZZER_PIN, LOW);  delay(300);
    // second beat
    digitalWrite(BUZZER_PIN, HIGH); delay(1000);
    digitalWrite(BUZZER_PIN, LOW);
}

/// @brief Play an error sound pattern on the active buzzer
void errorSound() 
{
    // Short rapid beeps with irregular pauses
    for(int i=0; i<3; i++) {
        digitalWrite(BUZZER_PIN, HIGH); delay(500);
        digitalWrite(BUZZER_PIN, LOW);  delay(500);
    }
    digitalWrite(BUZZER_PIN, LOW);
}

/// @brief Play a shake/vibration sound pattern on the active buzzer (non-blocking)
void shakeSound() 
{
    // Play a fast vibration-like sound for ~1 second (not heartbeat)
    unsigned long startTime = millis();
    digitalWrite(BUZZER_PIN, HIGH);
    while (millis() - startTime < 1000) {
        ;
    }
    digitalWrite(BUZZER_PIN, LOW);
}