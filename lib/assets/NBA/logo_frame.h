#ifndef _ASSETS_NBA_LOGO_FRAME_H_
#define _ASSETS_NBA_LOGO_FRAME_H_

#include "../assets/utils.h"
#include "frames/frame00_24.h"
#include "frames/frame25_39.h"
#include "frames/frame40_54.h"
#include "frames/frame55_69.h"
#include "frames/frame70_74.h"
#include "frames/frame75_79.h"

#define NBA_FRAME_COUNT 80

// NBA Logo animation data
extern const uint16_t NBA_LOGO_DELAYS[NBA_FRAME_COUNT];
extern const unsigned char* NBA_FRAME[NBA_FRAME_COUNT];
extern const AnimatedGIF nbaLogoGif;

#endif // _ASSETS_NBA_LOGO_FRAME_H_