#include "happy_frame.h"

/// @brief Delays for each frame in the Happy animation (in milliseconds)
const uint16_t HAPPY_DELAYS[HAPPY_FRAME_COUNT] = {
    /* 34 frames (1..34) */
    50, 50, 50, 50, 50, 50, 50, 50, 50, 50,
    50, 50, 50, 50, 50, 50, 50, 50, 50, 50,
    50, 50, 50, 50, 50, 50, 50, 50, 50, 50,
    50, 50, 50, 50
};

/// @brief Array of pointers to each frame of the Happy animation
const unsigned char* HAPPY_FRAME[HAPPY_FRAME_COUNT] = {
    Happy_Happy001, Happy_Happy002, Happy_Happy003, Happy_Happy004, Happy_Happy005,
    Happy_Happy006, Happy_Happy007, Happy_Happy008, Happy_Happy009, Happy_Happy010,
    Happy_Happy011, Happy_Happy012, Happy_Happy013, Happy_Happy014, Happy_Happy015,
    Happy_Happy016, Happy_Happy017, Happy_Happy018, Happy_Happy019, Happy_Happy020,
    Happy_Happy021, Happy_Happy022, Happy_Happy023, Happy_Happy024, Happy_Happy025,
    Happy_Happy026, Happy_Happy027, Happy_Happy028, Happy_Happy029, Happy_Happy030,
    Happy_Happy031, Happy_Happy032, Happy_Happy033, Happy_Happy034
};

/// @brief Animated GIF structure for the Happy animation
const AnimatedGIF happyFaceGif = {
    .frame_count = HAPPY_FRAME_COUNT,
    .width = SCREEN_SIZE_WIDTH,
    .height = SCREEN_SIZE_HEIGHT,
    .delays = HAPPY_DELAYS,
    .frames = HAPPY_FRAME
};