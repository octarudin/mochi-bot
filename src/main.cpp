#include "main.h"

#define SERIAL_BAUDRATE 115200
#define I2C_SDA_PIN 20 // GPIO 8
#define I2C_SCL_PIN 21 // GPIO 9

// Event queue untuk RTOS task communication
QueueHandle_t eventQueue = nullptr;
SemaphoreHandle_t displayMutex = nullptr;

// Task handles
TaskHandle_t touchTaskHandle = nullptr;
TaskHandle_t shakeTaskHandle = nullptr;
TaskHandle_t displayTaskHandle = nullptr;

// Debounce tracking
unsigned long lastTouchMillis = 0;
unsigned long lastShakeMillis = 0;

// Interrupt flag untuk stop animasi dengan cepat
volatile bool interruptAnimation = false;

/// @brief Touch monitoring task - responds instantly to touch events
static void touchMonitorTask(void *pvParameters) 
{
  const TickType_t xDelay = pdMS_TO_TICKS(5); // Check setiap 5ms (200Hz)
  
  while (true) {
    if (touchTriggered) {
      unsigned long now = millis();
      if (now - lastTouchMillis > 200) {
        Event evt = {EVENT_TOUCH, now};
        xQueueSend(eventQueue, &evt, 0);
        lastTouchMillis = now;
        touchTriggered = false; // volatile bool, atomic di ESP32
      }
    }
    vTaskDelay(xDelay);
  }
}

/// @brief Shake monitoring task - high priority untuk responsiveness
static void shakeMonitorTask(void *pvParameters) 
{
  const TickType_t xDelay = pdMS_TO_TICKS(5); // Check setiap 5ms (200Hz)
  
  while (true) {
    if (checkShake()) {
      unsigned long now = millis();
      if (now - lastShakeMillis > 500) { // Reduced from 1000ms untuk response lebih cepat
        // Interrupt animasi yang sedang berjalan
        interruptAnimation = true;
        
        Event evt = {EVENT_SHAKE, now};
        xQueueSend(eventQueue, &evt, portMAX_DELAY); // Wait until sent (high priority)
        lastShakeMillis = now;
        shakeTriggered = false; // volatile bool, atomic di ESP32
      }
    }
    vTaskDelay(xDelay);
  }
}

/// @brief Check jika animasi harus di-interrupt
static bool checkAnimationInterrupt() {
  return interruptAnimation;
}

/// @brief Display/Animation task - handles all visual updates
/// Non-blocking approach dengan event queue
static void displayAnimationTask(void *pvParameters) 
{
  Event evt;
  
  while (true) {
    // Reset interrupt flag sebelum mulai animasi
    interruptAnimation = false;
    
    // Wait for event dengan timeout 100ms
    if (xQueueReceive(eventQueue, &evt, pdMS_TO_TICKS(100))) {
      // Lock display access dengan mutex
      if (xSemaphoreTake(displayMutex, portMAX_DELAY)) {
        switch (evt.type) {
          case EVENT_SHAKE:
            shakeSound(); // Play unique shake sound
            playGIF(display, &angryFaceGif, 1, nullptr);
            break;
          
          case EVENT_TOUCH:
            playGIF(display, &grumpyFaceGif, 1, nullptr);
            break;
          
          case EVENT_STANDBY:
            playGIF(display, &standbyFaceGif, 1, checkAnimationInterrupt);
            break;
        }
        xSemaphoreGive(displayMutex); // Release mutex
      }
    } else {
      // Timeout - show standby animation dengan interrupt check
      if (xSemaphoreTake(displayMutex, portMAX_DELAY)) {
        playGIF(display, &standbyFaceGif, 1, checkAnimationInterrupt);
        xSemaphoreGive(displayMutex);
      }
    }
  }
}

/// @brief Initialize RTOS architecture
static void initRTOS() 
{
  // Create mutex untuk protect display access
  displayMutex = xSemaphoreCreateMutex();
  if (displayMutex == nullptr) {
    // Serial.println("ERROR: Failed to create display mutex!");
    ESP.restart();
  }
  
  // Create event queue (size 10 events)
  eventQueue = xQueueCreate(10, sizeof(Event));
  if (eventQueue == nullptr) {
    // Serial.println("ERROR: Failed to create event queue!");
    ESP.restart();
  }
  
  // Shake monitor task - Core 0 (HIGHEST PRIORITY)
  xTaskCreatePinnedToCore(
    shakeMonitorTask,
    "ShakeMonitor",
    2048,
    nullptr,
    3,  // Priority: highest untuk instant response
    &shakeTaskHandle,
    0   // Core 0
  );
  
  // Touch monitor task - Core 0
  xTaskCreatePinnedToCore(
    touchMonitorTask,
    "TouchMonitor",
    2048,
    nullptr,
    2,  // Priority: medium
    &touchTaskHandle,
    0   // Core 0 (bersama shake monitor)
  );
  
  // Display/Animation task - Core 1
  xTaskCreatePinnedToCore(
    displayAnimationTask,
    "DisplayManager",
    8192,  // Increased stack size untuk GIF rendering + mutex
    nullptr,
    1,  // Priority: lowest (GIF rendering butuh time)
    &displayTaskHandle,
    1   // Core 1 (dedicated untuk display)
  );
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

  // Show splash screen (before RTOS tasks start)
  playGIF(display, &nbaLogoGif, 1, nullptr);

  // Initialize RTOS architecture LAST - tasks will start immediately
  initRTOS();
}

void loop() {
  // Main loop sekarang hanya task scheduler (Arduino default)
  // Semua logic ada di RTOS tasks (shake monitor, touch monitor, display)
  
  // Yield ke scheduler dengan delay minimal
  vTaskDelay(pdMS_TO_TICKS(100)); // Increased delay karena tidak ada logic di sini
}

