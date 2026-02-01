#include "main.h"

#define SERIAL_BAUDRATE 115200
#define I2C_SDA_PIN 20 // GPIO 8
#define I2C_SCL_PIN 21 // GPIO 9
#define TOUCH_PIN    1 // GPIO 1
#define BUZZER_PIN   2 // GPIO 2

// ISR flag for touch
volatile bool touchTriggered = false;

// simple debounce tracker (checked from main loop)
unsigned long lastTouchMillis = 0;

// ISR: mark touch occurred (keep ISR minimal)
void IRAM_ATTR touchISR() {
  touchTriggered = true;
}

void setup() {
  Serial.begin(SERIAL_BAUDRATE);
  Serial.println("Starting up...");
  
  // Initialize pins
  pinMode(TOUCH_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  // Initialize I2C
  Wire.begin(I2C_SDA_PIN, I2C_SCL_PIN);

  // Initialize display
  display = new U8G2_SH1106_128X64_NONAME_F_HW_I2C(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
  display->begin();
  display->clearBuffer();
  display->sendBuffer();

  // splash screen
  playGIF(display, &nbaLogoGif, 1); // Play NBA logo GIF once

  // Attach external interrupt on touch pin (rising edge)
  attachInterrupt(digitalPinToInterrupt(TOUCH_PIN), touchISR, RISING);
}

void loop() {
  // Handle touch triggered by ISR with simple debounce
  if (touchTriggered) {
    unsigned long now = millis();
    if (now - lastTouchMillis > 200) { // 200ms debounce
      lastTouchMillis = now;
      touchTriggered = false;
      Serial.println("Touch detected! Played Angry Face GIF.");
      playGIF(display, &angryFaceGif, 1); // Play Touch Face GIF once
    } else {
      // clear flag if within debounce window
      touchTriggered = false;
    }
  }

  // Regular animation
  playGIF(display, &freeFaceGif, 1); // Play Free Face GIF once
}

