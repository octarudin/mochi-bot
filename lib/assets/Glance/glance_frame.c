#include "glance_frame.h"

/// @brief Delays for each frame in the NBA logo animation (in milliseconds)
const uint16_t GLANCE_DELAYS[GLANCE_FRAME_COUNT] = {
    /* 17 frames (1..17) */
    50, 50, 50, 50, 50, 50, 50, 50, 50, 50,
    50, 50, 50, 50, 50, 50, 50
};

/// @brief Array of pointers to each frame of the NBA logo animation
const unsigned char* GLANCE_FRAME[GLANCE_FRAME_COUNT] = {
    Glance_Glance001, Glance_Glance002, Glance_Glance003, Glance_Glance004, Glance_Glance005,
    Glance_Glance006, Glance_Glance007, Glance_Glance008, Glance_Glance009, Glance_Glance010,
    Glance_Glance011, Glance_Glance012, Glance_Glance013, Glance_Glance014, Glance_Glance015,
    Glance_Glance016, Glance_Glance017
};

/// @brief Animated GIF structure for the NBA logo animation
const AnimatedGIF glanceFaceGif = {
    .frame_count = GLANCE_FRAME_COUNT,
    .width = SCREEN_SIZE_WIDTH,
    .height = SCREEN_SIZE_HEIGHT,
    .delays = GLANCE_DELAYS,
    .frames = GLANCE_FRAME
};