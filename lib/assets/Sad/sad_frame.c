#include "sad_frame.h"

/// @brief Delays for each frame in the Standby Face animation (in milliseconds)
const uint16_t SAD_DELAYS[SAD_FRAME_COUNT] = {
    /* 15 frames (1..15) */
    50, 50, 50, 50, 50, 50, 50, 50, 50, 50,
    50, 50, 50, 50, 50
};

/// @brief Array of pointers to each frame of the Standby Face animation
const unsigned char* SAD_FRAME[SAD_FRAME_COUNT] = {
    Sad_Sad001, Sad_Sad002, Sad_Sad003, Sad_Sad004, Sad_Sad005,
    Sad_Sad006, Sad_Sad007, Sad_Sad008, Sad_Sad009, Sad_Sad010,
    Sad_Sad011, Sad_Sad012, Sad_Sad013, Sad_Sad014, Sad_Sad015,
};

/// @brief Animated GIF structure for the Standby Face animation
const AnimatedGIF sadFaceGif = {
    .frame_count = SAD_FRAME_COUNT,
    .width = SCREEN_SIZE_WIDTH,
    .height = SCREEN_SIZE_HEIGHT,
    .delays = SAD_DELAYS,
    .frames = SAD_FRAME
};
