#include "intro_frame.h"

/// @brief Delays for each frame in the Intro animation (in milliseconds)
const uint16_t INTRO_DELAYS[INTRO_FRAME_COUNT] = {
    /* 24 frames (1..24) */
    50, 50, 50, 50, 50, 50, 50, 50, 50, 50,
    50, 50, 50, 50, 50, 50, 50, 50, 50, 50,
    50, 50, 50, 50
};

/// @brief Array of pointers to each frame of the Intro animation
const unsigned char* INTRO_FRAME[INTRO_FRAME_COUNT] = {
    Intro_Intro001, Intro_Intro002, Intro_Intro003, Intro_Intro004, Intro_Intro005,
    Intro_Intro006, Intro_Intro007, Intro_Intro008, Intro_Intro009, Intro_Intro010,
    Intro_Intro011, Intro_Intro012, Intro_Intro013, Intro_Intro014, Intro_Intro015,
    Intro_Intro016, Intro_Intro017, Intro_Intro018, Intro_Intro019, Intro_Intro020,
    Intro_Intro021, Intro_Intro022, Intro_Intro023, Intro_Intro024
};

/// @brief Animated GIF structure for the Intro animation
const AnimatedGIF introFaceGif = {
    .frame_count = INTRO_FRAME_COUNT,
    .width = SCREEN_SIZE_WIDTH,
    .height = SCREEN_SIZE_HEIGHT,
    .delays = INTRO_DELAYS,
    .frames = INTRO_FRAME
};