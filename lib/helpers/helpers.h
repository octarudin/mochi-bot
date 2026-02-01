#ifndef _HELPERS_H
#define _HELPERS_H

#include <U8g2lib.h>
#include "assets.h"

/// @brief Plays an animated GIF on the display
/// @param display Pointer to the U8G2 display object
/// @param gif Pointer to the AnimatedGIF structure
/// @param loopCount Number of times to loop the animation
void playGIF(U8G2_SH1106_128X64_NONAME_F_HW_I2C* display, const AnimatedGIF* gif, uint16_t loopCount = 1);


#endif // _HELPERS_H