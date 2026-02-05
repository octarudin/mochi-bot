#ifndef _DRIVERS_OLED13_DISPLAY_H_
#define _DRIVERS_OLED13_DISPLAY_H_

#include "../drivers/utils.h"

#define OLED_ADDRESS 0x3C // Alamat I2C umum untuk OLED 1.3 inch

bool initOledDisplay();

extern U8G2_SH1106_128X64_NONAME_F_HW_I2C* display;

#endif // _DRIVERS_OLED13_DISPLAY_H_