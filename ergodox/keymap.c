// Based on https://raw.githubusercontent.com/qmk/qmk_firmware/master/layouts/community/ergodox/romanzolotarev-norman-plover-osx-hjkl/keymap.c
#include QMK_KEYBOARD_H
#include "debug.h"

enum unicode_names {
  EURO,
  POUND,
  DOLLAR,
};

enum layers {
  BASE = 0,
  SYMB = 1,
  PLVR = 2,
  ARRW = 3
};

const uint32_t PROGMEM unicode_map[] = {
  [EURO]  = 0x20AC,
  [POUND] = 0x00A3,
  [DOLLAR] = 0x24,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | F1     |   1  |   2  |   3  |   4  |   5  | F14  |           | F15  |   6  |   7  |   8  |   9  |   0  | Plover |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |   D  |   F  |   K  | ' "  |           | \ |  |   J  |   U  |   R  |   L  |  ; : |   -  _ |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | CtlEsc |   A  |   S  |   E  |   T  |   G  |------|           |------|   Y  |   N  |   I  |   O  |   H  |   =  + |
 * |--------+------+------+------+------+------| {    |           | }    |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   P  |   M  |  , < |  . > |  / ? | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | ` ~  | CtlA |      | Alt  | Cmd  |                                       | RAlt |      |   [  |   ]  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | VolD | Mute |       |      |      |
 *                                 ,------+------+------|       |------+------+------.
 *                                 |      |      | VolU |       |      |      |      |
 *                                 |Space |Back  |------|       |------| Tab  |Enter |
 *                                 |      |space | SYMB |       | ARRW |      |      |
 *                                 `--------------------'       `--------------------'
 */
  [BASE] = LAYOUT_ergodox(
    KC_F3,         KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_F14,
    KC_NO,         KC_Q,    KC_W,    KC_D,    KC_F,    KC_K,    KC_QUOT,
    CTL_T(KC_ESC), KC_A,    KC_S,    KC_E,    KC_T,    KC_G,
    KC_LSPO,       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LCBR,
    KC_GRV,    LCTL(KC_A),  KC_NO,   KC_LALT, KC_LGUI,
    /*-*/          /*-*/    /*-*/    /*-*/    /*-*/    KC_VOLD, KC_MUTE,
    /*-*/          /*-*/    /*-*/    /*-*/    /*-*/    /*-*/    KC_VOLU,
    /*-*/          /*-*/    /*-*/    /*-*/    /*-*/    KC_SPC,  KC_BSPC,       TT(SYMB),
    //
    /*-*/          KC_F15,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,          TG(PLVR),
    /*-*/          KC_BSLS, KC_J,    KC_U,    KC_R,    KC_L,    KC_SCLN,       KC_MINS,
    /*-*/          /*-*/    KC_Y,    KC_N,    KC_I,    KC_O,    KC_H,          KC_EQL,
    /*-*/          KC_RCBR, KC_P,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,       KC_RSPC,
    /*-*/          /*-*/    /*-*/    KC_RALT, KC_NO,   KC_LBRC, KC_RBRC,       KC_NO,
    KC_MPLY,       KC_MNXT,
    KC_MPRV,
    TT(ARRW),      KC_TAB,  KC_ENT
  ),
  
/* Keymap 0: Symbol layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   !  |   @  |   #  |   $  |   %  |------|           |------|   ^  |   &  |   *  |   (  |   )  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   €  |   £  |   $  |      |      |      |           |      |      |      |      |      |      |        |
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
  [SYMB] = LAYOUT_ergodox(
    KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,       KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_TRNS,
    KC_TRNS,       KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,
    KC_TRNS,       X(EURO), X(POUND),X(DOLLAR),KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    /*-*/          /*-*/    /*-*/    /*-*/    /*-*/    KC_TRNS, KC_TRNS,
    /*-*/          /*-*/    /*-*/    /*-*/    /*-*/    /*-*/    KC_TRNS,
    /*-*/          /*-*/    /*-*/    /*-*/    KC_TRNS, KC_TRNS, KC_TRNS,
    //
    /*-*/          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,
    /*-*/          KC_TRNS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,          KC_TRNS,
    /*-*/          /*-*/    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,       KC_TRNS,
    /*-*/          KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,        KC_TRNS,
    /*-*/          /*-*/    /*-*/    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,
    KC_TRNS,       KC_TRNS,
    KC_TRNS,
    KC_TRNS,       KC_TRNS, KC_TRNS
  ),
  [PLVR] = LAYOUT_ergodox(
    KC_NO,         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
    KC_NO,         KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_NO,
    KC_NO,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,
    KC_NO,         KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_NO,
    KC_TRNS,       KC_TRNS, KC_TRNS, KC_NO,   KC_NO,
    /*-*/          /*-*/    /*-*/    /*-*/    /*-*/    KC_TRNS, KC_TRNS,
    /*-*/          /*-*/    /*-*/    /*-*/    /*-*/    /*-*/    KC_TRNS,
    /*-*/          /*-*/    /*-*/    /*-*/    KC_C,    KC_V,    KC_NO,
    //
    /*-*/          KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,         KC_TRNS,
    /*-*/          KC_NO,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,          KC_NO,
    /*-*/          /*-*/    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,          KC_LBRC,
    /*-*/          KC_NO,   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,       KC_QUOT,
    /*-*/          /*-*/    /*-*/    KC_NO,   KC_NO,   KC_NO,   KC_NO,         KC_NO,
    KC_TRNS,       KC_TRNS,
    KC_TRNS,
    KC_NO,         KC_N,    KC_M
  ),
/* Keymap 0: Arrow layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | LEFT |  UP  | DOWN | RIGT |      |------|           |------| LEFT | DOWN |  UP  | RIGT |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
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
  [ARRW] = LAYOUT_ergodox(
    KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,       KC_TRNS, KC_MS_L, KC_MS_U, KC_MS_D, KC_MS_R,
    KC_TRNS,       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
    KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    /*-*/          /*-*/    /*-*/    /*-*/    /*-*/    KC_TRNS, KC_TRNS,
    /*-*/          /*-*/    /*-*/    /*-*/    /*-*/    /*-*/    KC_TRNS,
    /*-*/          /*-*/    /*-*/    /*-*/    KC_TRNS, KC_TRNS, KC_TRNS,
    //
    /*-*/          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,
    /*-*/          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,
    /*-*/          /*-*/    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS,       KC_TRNS,
    /*-*/          KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,        KC_TRNS,
    /*-*/          /*-*/    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,       KC_TRNS,
    KC_TRNS,
    KC_TRNS,       KC_TRNS, KC_TRNS
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