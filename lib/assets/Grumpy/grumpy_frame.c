#include "grumpy_frame.h"

/// @brief Delays for each frame in the Grumpy Face animation (in milliseconds)
const uint16_t GRUMPY_DELAYS[GRUMPY_FRAME_COUNT] = {
    50, 50, 50, 50, 50, 50, 50, 50, 50, 50,
    50, 50, 50, 50, 50, 50, 50, 50, 50, 50,
    50, 50, 50, 50, 50, 50, 50
};

/// @brief Array of pointers to each frame of the Grumpy Face animation
const unsigned char* GRUMPY_FRAME[GRUMPY_FRAME_COUNT] = {
    Grumpy_Grumpy001, Grumpy_Grumpy002, Grumpy_Grumpy003, Grumpy_Grumpy004, Grumpy_Grumpy005,
    Grumpy_Grumpy006, Grumpy_Grumpy007, Grumpy_Grumpy008, Grumpy_Grumpy009, Grumpy_Grumpy010,
    Grumpy_Grumpy011, Grumpy_Grumpy012, Grumpy_Grumpy013, Grumpy_Grumpy014, Grumpy_Grumpy015,
    Grumpy_Grumpy016, Grumpy_Grumpy017, Grumpy_Grumpy018, Grumpy_Grumpy019, Grumpy_Grumpy020,
    Grumpy_Grumpy021, Grumpy_Grumpy022, Grumpy_Grumpy023, Grumpy_Grumpy024, Grumpy_Grumpy025,
    Grumpy_Grumpy026, Grumpy_Grumpy027
};

/// @brief Animated GIF structure for the Grumpy Face animation
const AnimatedGIF grumpyFaceGif = {
    .frame_count = GRUMPY_FRAME_COUNT,
    .width = SCREEN_SIZE_WIDTH,
    .height = SCREEN_SIZE_HEIGHT,
    .delays = GRUMPY_DELAYS,
    .frames = GRUMPY_FRAME
};