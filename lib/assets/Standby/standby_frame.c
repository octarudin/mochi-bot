#include "standby_frame.h"

/// @brief Delays for each frame in the Standby Face animation (in milliseconds)
const uint16_t STANDBY_DELAYS[STANDBY_FRAME_COUNT] = {
    /* 28 frames (0..27) */
    50, 50, 50, 50, 50, 50, 50, 50, 50, 50,
    50, 50, 50, 50, 50, 50, 50, 50, 50, 50,
    50, 50, 50, 50, 50, 50, 50, 50
};

/// @brief Array of pointers to each frame of the Standby Face animation
const unsigned char* STANDBY_FRAME[STANDBY_FRAME_COUNT] = {
    Standby_Standby001, Standby_Standby002, Standby_Standby003, Standby_Standby004, Standby_Standby005,
    Standby_Standby006, Standby_Standby007, Standby_Standby008, Standby_Standby009, Standby_Standby010,
    Standby_Standby011, Standby_Standby012, Standby_Standby013, Standby_Standby014, Standby_Standby015,
    Standby_Standby016, Standby_Standby017, Standby_Standby018, Standby_Standby019, Standby_Standby020,
    Standby_Standby021, Standby_Standby022, Standby_Standby023, Standby_Standby024, Standby_Standby025,
    Standby_Standby026, Standby_Standby027, Standby_Standby028
};

/// @brief Animated GIF structure for the Standby Face animation
const AnimatedGIF standbyFaceGif = {
    .frame_count = STANDBY_FRAME_COUNT,
    .width = SCREEN_SIZE_WIDTH,
    .height = SCREEN_SIZE_HEIGHT,
    .delays = STANDBY_DELAYS,
    .frames = STANDBY_FRAME
};
