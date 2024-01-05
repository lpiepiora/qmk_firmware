#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/

// OLED settings
#ifdef OLED_ENABLE
#    define OLED_TIMEOUT 20000 // ms
#    define OLED_BRIGHTNESS 64 // Default 100.
#    define SPLIT_WPM_ENABLE   // Enable WPM across split keyboards (+268).
#    define SPLIT_OLED_ENABLE  // Synx on/off OLED state between halves (+100).
#endif

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

#define MASTER_LEFT
#define ENCODER_DIRECTION_FLIP

