#pragma once
#ifndef _UTILS_H_
#define _UTILS_H_

// Include necessary standard libraries
#include <stdint.h>
#include <pgmspace.h>

#define SCREEN_SIZE_WIDTH 128
#define SCREEN_SIZE_HEIGHT 64

/// @brief Structure to hold animated GIF data
typedef struct {
    const uint8_t frame_count;      // Total number of frames in the animation
    const uint16_t width;           // Width of each frame in pixels
    const uint16_t height;          // Height of each frame in pixels
    const uint16_t* delays;         // Pointer to array of delay times (in milliseconds)
    const unsigned char** frames;   // Pointer to array of frame data pointers
} AnimatedGIF;

#endif // _UTILS_H_