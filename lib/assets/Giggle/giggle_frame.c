#include "giggle_frame.h"

/// @brief Delays for each frame in the NBA logo animation (in milliseconds)
const uint16_t GIGGLE_DELAYS[GIGGLE_FRAME_COUNT] = {
    /* 34 frames (1..34) */
    50, 50, 50, 50, 50, 50, 50, 50, 50, 50,
    50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 
    50, 50, 50, 50, 50, 50, 50, 50, 50, 50,
    50, 50, 50, 50
};

/// @brief Array of pointers to each frame of the NBA logo animation
const unsigned char* GIGGLE_FRAME[GIGGLE_FRAME_COUNT] = {
    Giggle_Giggle001, Giggle_Giggle002, Giggle_Giggle003, Giggle_Giggle004, Giggle_Giggle005,
    Giggle_Giggle006, Giggle_Giggle007, Giggle_Giggle008, Giggle_Giggle009, Giggle_Giggle010,
    Giggle_Giggle011, Giggle_Giggle012, Giggle_Giggle013, Giggle_Giggle014, Giggle_Giggle015,
    Giggle_Giggle016, Giggle_Giggle017, Giggle_Giggle018, Giggle_Giggle019, Giggle_Giggle020,
    Giggle_Giggle021, Giggle_Giggle022, Giggle_Giggle023, Giggle_Giggle024, Giggle_Giggle025,
    Giggle_Giggle026, Giggle_Giggle027, Giggle_Giggle028, Giggle_Giggle029, Giggle_Giggle030,
    Giggle_Giggle031, Giggle_Giggle032, Giggle_Giggle033, Giggle_Giggle034
};

/// @brief Animated GIF structure for the NBA logo animation
const AnimatedGIF giggleFaceGif = {
    .frame_count = GIGGLE_FRAME_COUNT,
    .width = SCREEN_SIZE_WIDTH,
    .height = SCREEN_SIZE_HEIGHT,
    .delays = GIGGLE_DELAYS,
    .frames = GIGGLE_FRAME
};