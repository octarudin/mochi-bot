#include "uwu_frame.h"

/// @brief Delays for each frame in the Uwu animation (in milliseconds)
const uint16_t UWU_DELAYS[UWU_FRAME_COUNT] = {
    /* 18 frames (1..18) */
    50, 50, 50, 50, 50, 50, 50, 50, 50, 50,
    50, 50, 50, 50, 50, 50, 50, 50
};

/// @brief Array of pointers to each frame of the Uwu animation
const unsigned char* UWU_FRAME[UWU_FRAME_COUNT] = {
    Uwu_Uwu001, Uwu_Uwu002, Uwu_Uwu003, Uwu_Uwu004, Uwu_Uwu005,
    Uwu_Uwu006, Uwu_Uwu007, Uwu_Uwu008, Uwu_Uwu009, Uwu_Uwu010,
    Uwu_Uwu011, Uwu_Uwu012, Uwu_Uwu013, Uwu_Uwu014, Uwu_Uwu015,
    Uwu_Uwu016, Uwu_Uwu017, Uwu_Uwu018
};

/// @brief Animated GIF structure for the Uwu animation
const AnimatedGIF uwuFaceGif = {
    .frame_count = UWU_FRAME_COUNT,
    .width = SCREEN_SIZE_WIDTH,
    .height = SCREEN_SIZE_HEIGHT,
    .delays = UWU_DELAYS,
    .frames = UWU_FRAME
};