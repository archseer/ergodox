#pragma once

#undef TAPPING_TOGGLE
#define TAPPING_TOGGLE 3
// left board started having double inputs
#undef DEBOUNCE
#define DEBOUNCE 45

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

// this is default?
#define TAPPING_TERM 180
#define PERMISSIVE_HOLD
#define QUICK_TAP_TERM 0

// -- "Timeless" config options
// Instant tap setting
#define TAP_INTERVAL_MS 100
