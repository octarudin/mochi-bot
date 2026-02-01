#include "helpers.h"

/// @brief Plays an animated GIF on the display
/// @param gif Pointer to the AnimatedGIF structure
/// @param loopCount Number of times to loop the animation (default is 1)
void playGIF(U8G2_SH1106_128X64_NONAME_F_HW_I2C* display, const AnimatedGIF* gif, uint16_t loopCount) 
{
  for (uint16_t loop = 0; loop < loopCount; loop++) {
    for (uint8_t frame = 0; frame < gif->frame_count; frame++) {
      // Xóa buffer trước khi vẽ
      display->clearBuffer();

      // Vẽ từng pixel
      for (uint16_t y = 0; y < gif->height; y++) {
        for (uint16_t x = 0; x < gif->width; x++) {
          uint16_t byteIndex = y * (((gif->width + 7) / 8)) + (x / 8);
          uint8_t  bitIndex  = 7 - (x % 8);
          if (gif->frames[frame][byteIndex] & (1 << bitIndex)) {
            display->drawPixel(x, y);
          }
        }
      }

      // Đẩy buffer ra màn hình
      display->sendBuffer();

      // Chờ theo delay của khung
      delay(gif->delays[frame]);
    }
  }
}