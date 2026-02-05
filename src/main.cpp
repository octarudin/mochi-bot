#include "main.h"

#define SERIAL_BAUDRATE 115200
#define I2C_SDA_PIN 20 // GPIO 8
#define I2C_SCL_PIN 21 // GPIO 9

// Gunakan volatile untuk variabel yang dibagikan dengan ISR
extern volatile bool touchTriggered;
volatile int touchPinActive = 0;
extern volatile unsigned long lastISRTime;

// Variabel untuk melacak status Rising Edge pada Touch Pin 2
volatile bool lastTouchState2 = LOW;
volatile int tapCount = 0;
volatile unsigned long lastTapTime = 0;
extern volatile bool shakeDetected;

// ISR Handler untuk Sentuh (Pin 1, 2, 3)
void IRAM_ATTR handleTouchISR() {
  unsigned long now = millis();
  // Debouncing sederhana 50ms
  if (now - lastISRTime > 50) {
    touchTriggered = true;
    lastISRTime = now;
  }
}



void setup() {
  // Serial.begin(SERIAL_BAUDRATE);
  // Serial.println("Starting up...");
  
  // Initialize touch sensor
  initTouchSensor();

  // Initialize sound (buzzer) + sound test
  initSound();

  // Initialize I2C peripheral for OLED and MPU6050
  Wire.begin(I2C_SDA_PIN, I2C_SCL_PIN);

  // Initialize OLED display
  if (!initOledDisplay()) {
    errorSound();
    delay(5000);
    ESP.restart();
  }
  
  // Initialize vibration sensor (MPU6050) - MUST be before RTOS tasks
  if (!initVibrationSensor(display)) {
    errorSound();
    delay(5000);
    ESP.restart();
  }

  // Show splash screen 
  playGIF(display, &nbaLogoGif, 1, false);
  playGIF(display, &introFaceGif, 1, false);

  // normal face
  playGIF(display, &standbyFaceGif, 1, false);  
}

void loop() {
  unsigned long now = millis();
  static unsigned long lastInteractionTime = 0;

  // 1. Polling manual untuk Guncangan (karena tidak pakai pin interrupt)
  if (checkShake()) {
    digitalWrite(BUZZER_PIN, HIGH);
    playGIF(display, &sadFaceGif, 1, touchTriggered);
    digitalWrite(BUZZER_PIN, LOW);
    shakeTriggered = false; // Reset flag internal dari function checkShake
    lastInteractionTime = now;
  }

  // 2. Cek flag dari Interupsi Sentuh
  if (touchTriggered) {
    touchTriggered = false;
    lastInteractionTime = now;

    // Logika Khusus Double Tap (Rising Edge sudah dipicu oleh ISR)
    if (digitalRead(TOUCH_PIN_2) == HIGH) {
      if (now - lastTapTime < 200) {
        tapCount = 2; // Terdeteksi tap kedua
      } else {
        tapCount = 1; // Tap pertama
      }
      lastTapTime = now;
    } 
    // Kombinasi tombol lainnya
    else if (digitalRead(TOUCH_PIN_1) == HIGH && digitalRead(TOUCH_PIN_2) == HIGH && digitalRead(TOUCH_PIN_3) == HIGH) {
      playGIF(display, &grumpyFaceGif, 1, touchTriggered);
    }
    else if (digitalRead(TOUCH_PIN_1) == HIGH && digitalRead(TOUCH_PIN_3) == HIGH) {
      playGIF(display, &glanceFaceGif, 1, touchTriggered);
    }
    else if (digitalRead(TOUCH_PIN_1) == HIGH) {
      playGIF(display, &angryFaceGif, 1, touchTriggered);
    }
    else if (digitalRead(TOUCH_PIN_3) == HIGH) {
      playGIF(display, &giggleFaceGif, 1, touchTriggered);
    }
  }

  // 3. Eksekusi Tap Pin 2 (Single vs Double)
  if (tapCount == 2) {
    playGIF(display, &uwuFaceGif, 1, touchTriggered);
    tapCount = 0;
  } 
  else if (tapCount == 1) {
    playGIF(display, &cuteFaceGif, 1, touchTriggered);
    tapCount = 0;
  }

  // 4. Kondisi Standby jika semua pin LOW
  if (digitalRead(TOUCH_PIN_1) == LOW && 
      digitalRead(TOUCH_PIN_2) == LOW && 
      digitalRead(TOUCH_PIN_3) == LOW) {
      
    if (now - lastInteractionTime > 10000) {
      playGIF(display, &nbaLogoGif, 1, touchTriggered);
      lastInteractionTime = now;
    } else {
      playGIF(display, &standbyFaceGif, 1, touchTriggered);
    }
  }
}