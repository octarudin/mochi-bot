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
    digitalWrite(BUZZER_PIN, HIGH); delay(60);
    digitalWrite(BUZZER_PIN, LOW);  delay(100);
    // second beat
    digitalWrite(BUZZER_PIN, HIGH); delay(120);
    digitalWrite(BUZZER_PIN, LOW);
}

/// @brief Play an error sound pattern on the active buzzer
void errorSound() 
{
    // Short rapid beeps with irregular pauses
    for(int i=0; i<3; i++) {
        digitalWrite(BUZZER_PIN, HIGH); delay(30);
        digitalWrite(BUZZER_PIN, LOW);  delay(30);
    }
    delay(100); // Dramatic pause
    digitalWrite(BUZZER_PIN, HIGH); delay(200); // Long closing sound
    digitalWrite(BUZZER_PIN, LOW);
}

/// @brief Play a shake/vibration sound pattern on the active buzzer (non-blocking)
void shakeSound() 
{
    // Heartbeat pattern - minimized with delayMicroseconds
    // first beat
    digitalWrite(BUZZER_PIN, HIGH); 
    delayMicroseconds(60000);  // 60ms
    digitalWrite(BUZZER_PIN, LOW);  
    delayMicroseconds(100000); // 100ms
    // second beat
    digitalWrite(BUZZER_PIN, HIGH); 
    delayMicroseconds(120000); // 120ms
    digitalWrite(BUZZER_PIN, LOW);
}