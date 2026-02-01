#ifndef _ASSETS_ANGRY_ANGRY_FRAME_H_
#define _ASSETS_ANGRY_ANGRY_FRAME_H_

#include "../utils.h"

// Angry Face frames
#include "frame00_246.h"

#define ANGRY_FRAME_COUNT 247

// Angry Face animation data
extern const uint16_t ANGRY_DELAYS[ANGRY_FRAME_COUNT];
extern const unsigned char* ANGRY_FRAME[ANGRY_FRAME_COUNT];
extern const AnimatedGIF angryFaceGif;

#endif // _ASSETS_ANGRY_ANGRY_FRAME_H_