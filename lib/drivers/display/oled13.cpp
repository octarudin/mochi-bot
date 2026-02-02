#include "oled13.h"

U8G2_SH1106_128X64_NONAME_F_HW_I2C* display = nullptr;

/// @brief Initializes the OLED display
/// @return true if initialization is successful, false otherwise
bool initOledDisplay() 
{
    // Initialize display
    display = new U8G2_SH1106_128X64_NONAME_F_HW_I2C(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
    if(!display->begin()) {
        return false;
    }

    display->clearBuffer();
    display->sendBuffer();

    return true;
}