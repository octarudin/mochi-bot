#ifndef _ASSETS_SAD_SAD_FRAME_H_
#define _ASSETS_SAD_SAD_FRAME_H_

#include "../assets/utils.h"
#include "frame01_15.h"

#define SAD_FRAME_COUNT 15

// sad Face animation data
extern const uint16_t SAD_DELAYS[SAD_FRAME_COUNT];
extern const unsigned char* SAD_FRAME[SAD_FRAME_COUNT];
extern const AnimatedGIF sadFaceGif;

#endif // _ASSETS_SAD_SAD_FRAME_H_