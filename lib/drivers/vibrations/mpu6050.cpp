#include "mpu6050.h"

Adafruit_MPU6050* mpu = nullptr;
volatile bool shakeTriggered = false;

// State machine variables for shake detection
typedef enum {
  SHAKE_IDLE,
  SHAKE_DETECTED,
  SHAKE_DEBOUNCING
} ShakeState_t;

static ShakeState_t shakeState = SHAKE_IDLE;
static unsigned long lastShakeTime = 0;
static bool wasVibrating = false;
static TaskHandle_t shakeTaskHandle = nullptr;

bool initVibrationSensor(U8G2_SH1106_128X64_NONAME_F_HW_I2C* display) 
{
  mpu = new Adafruit_MPU6050();  
  if (!mpu->begin()) {
    display->clearDisplay();
    display->setCursor(0, 10);
    display->println("ERROR:");
    display->println("MPU6050 Pointer");
    display->println("Gagal Inisial!");
    display->display();
    return false;
  }

  mpu->setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu->setFilterBandwidth(MPU6050_BAND_21_HZ);
  
  shakeState = SHAKE_IDLE;
  lastShakeTime = 0;
  wasVibrating = false;
  
  // Start background monitoring task
  startShakeMonitorTask();
  
  return true;
}

float getVibrationMagnitude() 
{
  sensors_event_t a, g, temp;
  // Menggunakan operator -> karena mpu adalah pointer
  mpu->getEvent(&a, &g, &temp);
  return sqrt(sq(a.acceleration.x) + sq(a.acceleration.y) + sq(a.acceleration.z));
}

/// @brief Check if shake was triggered
bool checkShake() 
{
  return shakeTriggered;
}

/// @brief FreeRTOS task untuk continuous shake monitoring
/// Berjalan di background independent dari main loop
static void shakeMonitorTask(void *pvParameters) 
{
  const TickType_t xDelay = pdMS_TO_TICKS(10); // Check setiap 10ms (100Hz)
  
  while (true) {
    float magnitude = getVibrationMagnitude();
    bool isVibrating = (magnitude > SHAKE_THRESHOLD);
    unsigned long now = millis();

    switch (shakeState) {
      case SHAKE_IDLE:
        // Tunggu hingga vibration melampaui threshold
        if (isVibrating && !wasVibrating) {
          shakeState = SHAKE_DETECTED;
          lastShakeTime = now;
          shakeTriggered = true; // Set flag immediately
        }
        break;

      case SHAKE_DETECTED:
        // Transition ke debouncing setelah shake terdeteksi
        shakeState = SHAKE_DEBOUNCING;
        break;

      case SHAKE_DEBOUNCING:
        // Tunggu debounce time sebelum bisa detect shake lagi
        if (now - lastShakeTime >= SHAKE_DEBOUNCE_MS) {
          shakeState = SHAKE_IDLE;
        }
        break;
    }

    wasVibrating = isVibrating;
    vTaskDelay(xDelay); // Yield ke scheduler untuk task lain
  }
}

/// @brief Start background shake monitoring task
void startShakeMonitorTask() 
{
  if (shakeTaskHandle == nullptr) {
    xTaskCreatePinnedToCore(
      shakeMonitorTask,      // Function
      "ShakeMonitor",        // Name
      2048,                  // Stack size
      nullptr,               // Parameters
      3,                     // Priority (HIGHEST - lebih tinggi dari touch)
      &shakeTaskHandle,      // Handle
      0                      // Core 0 (App core)
    );
  }
}

void updateDisplay(U8G2_SH1106_128X64_NONAME_F_HW_I2C* display, float magnitude, bool isVibrating) 
{
  display->clearBuffer();
  display->setFont(u8g2_font_ncenB08_tr);
  
  display->drawStr(0, 10, "VIBRATION MONITOR");
  display->drawLine(0, 12, 128, 12);

  display->setFont(u8g2_font_ncenB14_tr);
  char magnitude_str[16];
  snprintf(magnitude_str, sizeof(magnitude_str), "%.2f", magnitude);
  display->drawStr(0, 32, magnitude_str);
  display->setFont(u8g2_font_ncenB08_tr);
  display->drawStr(50, 32, "m/s2");

  if (isVibrating) {
    display->drawBox(0, 45, 128, 19);
    display->setDrawColor(0);
    display->drawStr(15, 58, "!!! VIBRATION !!!");
    display->setDrawColor(1);
  } else {
    display->drawStr(30, 58, "Status: Safe");
  }
  
  display->sendBuffer();
}