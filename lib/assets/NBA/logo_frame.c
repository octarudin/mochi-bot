#include "logo_frame.h"

/// @brief Delays for each frame in the NBA logo animation (in milliseconds)
const uint16_t NBA_LOGO_DELAYS[NBA_FRAME_COUNT] = {
    /* 80 frames (0..79) */
    100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
    100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
    100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
    100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
    100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
    100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
    100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
    100, 100, 100, 100, 100, 100, 100, 100, 100, 100
};

/// @brief Array of pointers to each frame of the NBA logo animation
const unsigned char* NBA_FRAME[NBA_FRAME_COUNT] = {
    NBA_Logo00, NBA_Logo01, NBA_Logo02, NBA_Logo03, NBA_Logo04,
    NBA_Logo05, NBA_Logo06, NBA_Logo07, NBA_Logo08, NBA_Logo09,
    NBA_Logo10, NBA_Logo11, NBA_Logo12, NBA_Logo13, NBA_Logo14,
    NBA_Logo15, NBA_Logo16, NBA_Logo17, NBA_Logo18, NBA_Logo19,
    NBA_Logo20, NBA_Logo21, NBA_Logo22, NBA_Logo23, NBA_Logo24,
    NBA_Logo25, NBA_Logo26, NBA_Logo27, NBA_Logo28, NBA_Logo29,
    NBA_Logo30, NBA_Logo31, NBA_Logo32, NBA_Logo33, NBA_Logo34,
    NBA_Logo35, NBA_Logo36, NBA_Logo37, NBA_Logo38, NBA_Logo39,
    NBA_Logo40, NBA_Logo41, NBA_Logo42, NBA_Logo43, NBA_Logo44,
    NBA_Logo45, NBA_Logo46, NBA_Logo47, NBA_Logo48, NBA_Logo49,
    NBA_Logo50, NBA_Logo51, NBA_Logo52, NBA_Logo53, NBA_Logo54,
    NBA_Logo55, NBA_Logo56, NBA_Logo57, NBA_Logo58, NBA_Logo59,
    NBA_Logo60, NBA_Logo61, NBA_Logo62, NBA_Logo63, NBA_Logo64,
    NBA_Logo65, NBA_Logo66, NBA_Logo67, NBA_Logo68, NBA_Logo69, 
    NBA_Logo70, NBA_Logo71, NBA_Logo72, NBA_Logo73, NBA_Logo74,
    NBA_Logo75, NBA_Logo76, NBA_Logo77, NBA_Logo78, NBA_Logo79
};

/// @brief Animated GIF structure for the NBA logo animation
const AnimatedGIF nbaLogoGif = {
    .frame_count = NBA_FRAME_COUNT,
    .width = SCREEN_SIZE_WIDTH,
    .height = SCREEN_SIZE_HEIGHT,
    .delays = NBA_LOGO_DELAYS,
    .frames = NBA_FRAME
};