#ifndef _ASSETS_INTRO_INTRO_FRAME_H_
#define _ASSETS_INTRO_INTRO_FRAME_H_

#include "../assets/utils.h"
#include "frame01_24.h"

#define INTRO_FRAME_COUNT 24

// Intro animation data
extern const uint16_t INTRO_DELAYS[INTRO_FRAME_COUNT];
extern const unsigned char* INTRO_FRAME[INTRO_FRAME_COUNT];
extern const AnimatedGIF introFaceGif;

#endif  // _ASSETS_INTRO_INTRO_FRAME_H_