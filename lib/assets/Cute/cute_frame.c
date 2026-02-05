#include "cute_frame.h"

/// @brief Delays for each frame in the NBA logo animation (in milliseconds)
const uint16_t CUTE_DELAYS[CUTE_FRAME_COUNT] = {
    /* 18 frames (1..18) */
    50, 50, 50, 50, 50, 50, 50, 50, 50, 50,
    50, 50, 50, 50, 50, 50, 50, 50
};

/// @brief Array of pointers to each frame of the NBA logo animation
const unsigned char* CUTE_FRAME[CUTE_FRAME_COUNT] = {
    Cute_Cute001, Cute_Cute002, Cute_Cute003, Cute_Cute004, Cute_Cute005,
    Cute_Cute006, Cute_Cute007, Cute_Cute008, Cute_Cute009, Cute_Cute010,
    Cute_Cute011, Cute_Cute012, Cute_Cute013, Cute_Cute014, Cute_Cute015,
    Cute_Cute016, Cute_Cute017, Cute_Cute018
};

/// @brief Animated GIF structure for the NBA logo animation
const AnimatedGIF cuteFaceGif = {
    .frame_count = CUTE_FRAME_COUNT,
    .width = SCREEN_SIZE_WIDTH,
    .height = SCREEN_SIZE_HEIGHT,
    .delays = CUTE_DELAYS,
    .frames = CUTE_FRAME
};