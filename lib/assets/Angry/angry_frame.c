#include "angry_frame.h"

/// @brief Delays for each frame in the Angry Face animation (in milliseconds)
const uint16_t ANGRY_DELAYS[ANGRY_FRAME_COUNT] = {
    50, 50, 50, 50, 50, 50, 50, 50, 50, 50,
    50, 50, 50, 50, 50, 50, 50, 50, 50, 50,
    50, 50
};

/// @brief Array of pointers to each frame of the Angry Face animation
const unsigned char* ANGRY_FRAME[ANGRY_FRAME_COUNT] = {
    Angry_Angry001, Angry_Angry002, Angry_Angry003, Angry_Angry004, Angry_Angry005,
    Angry_Angry006, Angry_Angry007, Angry_Angry008, Angry_Angry009, Angry_Angry010,
    Angry_Angry011, Angry_Angry012, Angry_Angry013, Angry_Angry014, Angry_Angry015,
    Angry_Angry016, Angry_Angry017, Angry_Angry018, Angry_Angry019, Angry_Angry020,
    Angry_Angry021, Angry_Angry022
};

/// @brief Animated GIF structure for the Angry Face animation
const AnimatedGIF angryFaceGif = {
    .frame_count = ANGRY_FRAME_COUNT,
    .width = SCREEN_SIZE_WIDTH,
    .height = SCREEN_SIZE_HEIGHT,
    .delays = ANGRY_DELAYS,
    .frames = ANGRY_FRAME
};