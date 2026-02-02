#ifndef _ASSETS_STANDBY_STANDBY_FRAME_H__
#define _ASSETS_STANDBY_STANDBY_FRAME_H_

#include "../assets/utils.h"
#include "frame01_28.h"

#define STANDBY_FRAME_COUNT 28

// standby Face animation data
extern const uint16_t STANDBY_DELAYS[STANDBY_FRAME_COUNT];
extern const unsigned char* STANDBY_FRAME[STANDBY_FRAME_COUNT];
extern const AnimatedGIF standbyFaceGif;

#endif // _ASSETS_STANDBY_STANDBY_FRAME_H__