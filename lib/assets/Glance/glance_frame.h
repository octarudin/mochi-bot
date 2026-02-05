#ifndef _ASSETS_GLANCE_GLANCE_FRAME_H_
#define _ASSETS_GLANCE_GLANCE_FRAME_H_

#include "../assets/utils.h"
#include "frame01_17.h"

#define GLANCE_FRAME_COUNT 17

// Glance animation data
extern const uint16_t GLANCE_DELAYS[GLANCE_FRAME_COUNT];
extern const unsigned char* GLANCE_FRAME[GLANCE_FRAME_COUNT];
extern const AnimatedGIF glanceFaceGif;

#endif  // _ASSETS_GLANCE_GLANCE_FRAME_H_