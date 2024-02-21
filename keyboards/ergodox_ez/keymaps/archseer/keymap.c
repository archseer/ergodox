// Based on https://raw.githubusercontent.com/qmk/qmk_firmware/master/layouts/community/ergodox/romanzolotarev-norman-plover-osx-hjkl/keymap.c
#include QMK_KEYBOARD_H
#include "debug.h"
#include "achordion.h"

enum layers {
  BASE = 0,
  SYM = 1,
  PLVR = 2,
  NAV = 3,
  NUM = 4
};

#ifdef KEY_OVERRIDE_ENABLE  // If using QMK's key overrides...
#define w_shift(kc, kc_override) &ko_make_basic(MOD_MASK_SHIFT, kc, kc_override)
#define wo_shift(kc, kc_override) &ko_make_with_layers_and_negmods(0, kc, kc_override, ~0, (uint8_t)MOD_MASK_SHIFT)

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    // swap - and _ (_ is more frequent)
    // wo_shift(KC_MINUS, KC_UNDERSCORE),
    // w_shift(KC_MINUS, KC_MINUS),
    // swap " and ' (" is more frequent)
    // wo_shift(KC_QUOTE, KC_DOUBLE_QUOTE),
    // w_shift(KC_QUOTE, KC_QUOTE),
    NULL // Null terminate the array of overrides!
};
#endif

// #define ACHORDION_STREAK

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_E LCTL_T(KC_E)
#define HOME_T LSFT_T(KC_T)

// Right-hand home row mods
#define HOME_N RSFT_T(KC_N)
#define HOME_I RCTL_T(KC_I)
#define HOME_O LALT_T(KC_O)
#define HOME_H RGUI_T(KC_H)

// // Left-hand home row mods
// #define HOME_A KC_A
// #define HOME_S KC_S
// #define HOME_E KC_E
// #define HOME_T KC_T

// // Right-hand home row mods
// #define HOME_N KC_N
// #define HOME_I KC_I
// #define HOME_O KC_O
// #define HOME_H KC_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | F1     |      |      |      |      |      | F14  |           | F15  |      |      |      |      |      | Plover |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |   D  |   F  |   K  | ' "  |           | \ |  |   J  |   U  |   R  |   L  |  ; : |   -  _ |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | CtlEsc |   A  |   S  |   E  |   T  |   G  |------|           |------|   Y  |   N  |   I  |   O  |   H  |   =  + |
 * |--------+------+------+------+------+------| {    |           | }    |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   P  |   M  |  , < |  . > |  / ? | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | ` ~  | CtlA |      | Alt  | Cmd  |                                       | RAlt |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | VolD | Mute |       |      |      |
 *                                 ,------+------+------|       |------+------+------.
 *                                 |      |      | VolU |       |      |      |      |
 *                                 |Space |Back  |------|       |------| Tab  |Enter |
 *                                 |      |space | SYM  |       | NAV  |      |      |
 *                                 `--------------------'       `--------------------'
 */
  [BASE] = LAYOUT_ergodox(
    KC_F3,         KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_F14,
    KC_NO,         KC_Q,    KC_W,    KC_D,    KC_F,    KC_K,    KC_QUOT,
    CTL_T(KC_ESC), HOME_A,  HOME_S,  HOME_E,  HOME_T,  KC_G,
    SC_LSPO,       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LCBR,
    KC_GRV,    LCTL(KC_A),  KC_NO,   KC_LALT, KC_LGUI,
    /*-*/          /*-*/    /*-*/    /*-*/    /*-*/    KC_VOLD, KC_MUTE,
    /*-*/          /*-*/    /*-*/    /*-*/    /*-*/    /*-*/    KC_VOLU,
    /*-*/          /*-*/    /*-*/    /*-*/    /*-*/    LT(SYM, KC_SPC), KC_BSPC, TT(NUM),
    //
    /*-*/          KC_F15,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,          TG(PLVR),
    /*-*/          KC_BSLS, KC_J,    KC_U,    KC_R,    KC_L,    KC_SCLN,       KC_MINS,
    /*-*/          /*-*/    KC_Y,    HOME_N,  HOME_I,  HOME_O,  HOME_H,        KC_EQL,
    /*-*/          KC_RCBR, KC_P,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,       SC_RSPC,
    /*-*/          /*-*/    /*-*/    KC_RALT, KC_NO,   KC_NO,   KC_NO,         KC_NO,
    KC_MPLY,       KC_MNXT,
    KC_MPRV,
    TT(NAV),       KC_TAB,  LT(NAV, KC_ENT)
  ),
  
/* Keymap 0: Symbol layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   !  |   @  |   #  |   %  |   $  |------|           |------|   ^  |   &  |   *  |      |      |        |
 * |--------+------+------+------+------+------| [    |           | ]    |------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
  [SYM] = LAYOUT_ergodox(
    KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,       KC_EXLM, KC_AT,   KC_HASH, KC_PERC,  KC_DLR,
    KC_TRNS,       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_LBRC,
    KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    /*-*/          /*-*/    /*-*/    /*-*/    /*-*/    KC_TRNS, KC_TRNS,
    /*-*/          /*-*/    /*-*/    /*-*/    /*-*/    /*-*/    KC_TRNS,
    /*-*/          /*-*/    /*-*/    /*-*/    KC_TRNS, KC_TRNS, KC_TRNS,
    //
    /*-*/          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,
    /*-*/          KC_TRNS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,          KC_TRNS,
    /*-*/          /*-*/    KC_CIRC, KC_AMPR, KC_ASTR, KC_TRNS, KC_TRNS,       KC_TRNS,
    /*-*/          KC_RBRC, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,        KC_TRNS,
    /*-*/          /*-*/    /*-*/    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,
    KC_TRNS,       KC_TRNS,
    KC_TRNS,
    KC_TRNS,       KC_TRNS, KC_TRNS
  ),
  [PLVR] = LAYOUT_ergodox(
    KC_NO,         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
    KC_NO,         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
    KC_NO,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,
    KC_NO,         KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_NO,
    KC_TRNS,       KC_TRNS, KC_TRNS, KC_NO,   KC_NO,
    /*-*/          /*-*/    /*-*/    /*-*/    /*-*/    KC_TRNS, KC_TRNS,
    /*-*/          /*-*/    /*-*/    /*-*/    /*-*/    /*-*/    KC_TRNS,
    /*-*/          /*-*/    /*-*/    /*-*/    KC_C,    KC_V,    KC_NO,
    //
    /*-*/          KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,         KC_TRNS,
    /*-*/          KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,         KC_TRNS,
    /*-*/          /*-*/    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,          KC_LBRC,
    /*-*/          KC_NO,   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,       KC_QUOT,
    /*-*/          /*-*/    /*-*/    KC_NO,   KC_NO,   KC_NO,   KC_NO,         KC_NO,
    KC_TRNS,       KC_TRNS,
    KC_TRNS,
    KC_NO,         KC_N,    KC_M
  ),
/* Keymap 0: Number layer
 * TODO: add oneshot mods on left side
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      | Reset|           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |   1  |   2  |   3  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Cmd  | Alt  | Shift| Ctrl |      |------|           |------|      |   4  |   5  |   6  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |   7  |   8  |   9  |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|    0   |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
  [NUM] = LAYOUT_ergodox(
    KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, QK_BOOT,
    KC_TRNS,       KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_TRNS,
    KC_TRNS,       OSM(MOD_LGUI),  OSM(MOD_LALT), OSM(KC_LCTL), OSM(KC_LSFT), KC_NO,
    KC_TRNS,       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
    KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    /*-*/          /*-*/    /*-*/    /*-*/    /*-*/    KC_TRNS, KC_TRNS,
    /*-*/          /*-*/    /*-*/    /*-*/    /*-*/    /*-*/    KC_TRNS,
    /*-*/          /*-*/    /*-*/    /*-*/    KC_TRNS, KC_TRNS, KC_TRNS,
    //
    /*-*/          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,
    /*-*/          KC_TRNS, KC_TRNS, KC_1,    KC_2,    KC_3,    KC_TRNS,       KC_TRNS,
    /*-*/          /*-*/    KC_TRNS, KC_4,    KC_5,    KC_6,    KC_TRNS,       KC_TRNS,
    /*-*/          KC_TRNS, KC_TRNS, KC_7,    KC_8,    KC_9,    KC_TRNS,       KC_TRNS,
    /*-*/          /*-*/    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,       KC_TRNS,
    KC_TRNS,
    KC_TRNS,       KC_0, KC_TRNS
  ),
/* Keymap 0: Arrow layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      | Reset|           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------| LEFT | DOWN |  UP  | RIGT |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
  [NAV] = LAYOUT_ergodox(
    KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, QK_BOOT,
    KC_TRNS,       KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,    KC_TRNS,
    KC_TRNS,       KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,
    KC_TRNS,       KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,    KC_TRNS,
    KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    /*-*/          /*-*/    /*-*/    /*-*/    /*-*/    KC_TRNS, KC_TRNS,
    /*-*/          /*-*/    /*-*/    /*-*/    /*-*/    /*-*/    KC_TRNS,
    /*-*/          /*-*/    /*-*/    /*-*/    KC_TRNS, KC_TRNS, KC_TRNS,
    //
    /*-*/          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,
    /*-*/          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,
    /*-*/          /*-*/    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS,       KC_TRNS,
    /*-*/          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,
    /*-*/          /*-*/    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,       KC_TRNS,
    KC_TRNS,
    KC_TRNS,       KC_0, KC_TRNS
  ),
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case 0:
#ifdef RGBLIGHT_COLOR_LAYER_0
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
            break;
        case 1:
            ergodox_right_led_1_on();
#ifdef RGBLIGHT_COLOR_LAYER_1
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
#endif
            break;
        case 2:
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_2
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
#endif
            break;
        case 3:
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_3
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
#endif
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_4
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
#endif
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_5
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
#endif
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_6
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
#endif
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_7
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
#endif
            break;
        default:
            break;
    }

    return state;
};

// ---- Home Row Mods "Timeless" Config ----
// taken from https://github.com/ratoru/qmk_keymap
#if defined (PERMISSIVE_HOLD_PER_KEY) || defined (TAP_INTERVAL_MS)
#define IS_HOMEROW(r)        (r->event.key.row == 1 || r->event.key.row == 5)

static uint16_t    next_keycode;
static keyrecord_t next_record;

bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Instant Tap Config
    static uint16_t prev_keycode;
    if (record->event.pressed) {
        // Store the previous keycode for instant tap decision
        prev_keycode = next_keycode;
        // Cache the next input for mod-tap decisions
        next_keycode = keycode;
        next_record  = *record;
    }
    // Match home row mod-tap keys when it is not preceded by a Layer key
    if (IS_HOMEROW(record) && IS_QK_MOD_TAP(keycode) && !IS_QK_LAYER_TAP(prev_keycode)) {
        // Tap the mod-tap key instantly when it follows a short interval
        if (record->event.pressed && last_input_activity_elapsed() < TAP_INTERVAL_MS) {
            record->keycode = keycode & 0xff;
            action_tapping_process(*record);
            return false;
        } else { // Send the base keycode key up event
            keyrecord_t base_record   = *record;
            base_record.keycode       = keycode & 0xff;
            base_record.event.pressed = false;
            action_tapping_process(base_record);
        }
    }
    return true;
}
#endif

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
                     uint16_t other_keycode, keyrecord_t* other_record) {
  // Exceptionally consider the following chords as holds, even though they
  // are on the same hand in Magic Sturdy.
  switch (tap_hold_keycode) {
    case CTL_T(KC_ESC):
      return true;
      break;
    // case HOME_X:  // X + D and X + G.
    //   if (other_keycode == HOME_D || other_keycode == KC_G) {
    //     return true;
    //   }
    //   break;
  }

  // Also allow same-hand holds when the other key is in the rows below the
  // alphas. I need the `% (MATRIX_ROWS / 2)` because my keyboard is split.
  if (other_record->event.key.row % (MATRIX_ROWS / 2) >= 4) {
    return true;
  }

  // Otherwise, follow the opposite hands rule.
  return achordion_opposite_hands(tap_hold_record, other_record);
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
  switch (tap_hold_keycode) {
    case LT(SYM, KC_SPC):
    case LT(NAV, KC_ENT):
      return 0;  // Bypass Achordion for these keys.
  }

  return 800;  // Otherwise use a timeout of 800 ms.
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_achordion(keycode, record)) { return false; }
  // Your macros ...

  return true;
}

void matrix_scan_user(void) {
  achordion_task();
}
