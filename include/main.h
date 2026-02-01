#ifndef _MAIN_H_
#define _MAIN_H_

#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h> 
#include "assets.h"     // load all GIF assets
#include "helpers.h"    // load helper functions

/// @brief U8G2 display object
U8G2_SH1106_128X64_NONAME_F_HW_I2C* display;


#endif // _MAIN_H_