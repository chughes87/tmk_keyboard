#include "keymap_common.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: mostly letters */
  KEYMAP(KC_Q,   KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,   KC_U,    KC_I, KC_O, KC_P, \
         KC_A,   KC_S,     KC_D,    KC_F,    KC_G,    KC_H,   KC_J,    KC_K, KC_L, KC_SCLN, \
         KC_Z,   KC_X,     KC_C,    KC_V,    KC_B,    KC_N,   KC_M,    KC_COMM, KC_DOT, KC_SLSH, \
         KC_TAB, KC_LALT,  KC_LCTL, KC_LGUI, KC_LSFT, KC_FN0, KC_ESC,  KC_SPC, KC_BSPC, KC_MINS, KC_QUOT, KC_ENT),  \
  /* 1: punctuation and numbers */
  KEYMAP( \
        KC_1,    KC_2,     KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,      KC_8,         KC_9,           KC_0, \
        KC_F3,   KC_LBRC,  KC_RBRC, SHIFT(KC_LBRC), SHIFT(KC_RBRC),        KC_LEFT, KC_DOWN,   KC_UP,        KC_RIGHT,       KC_F10,   \
        KC_HOME, KC_END,   KC_F7,   KC_F8,   KC_F9,                        KC_F11,  KC_F12,    KC_EQUAL,     SHIFT(KC_DOT),  KC_BSLS,          \
        KC_FN1,  KC_LALT,  KC_LCTL, KC_LGUI, KC_LSFT, KC_FN0, KC_ESC,      KC_SPC,  KC_DEL,    KC_LGUI,      KC_GRAVE,       KC_F2),\
  /* 2: arrows and function keys */
  KEYMAP(KC_INS, KC_HOME,     KC_UP,    KC_END,   KC_PGUP,                 KC_UP, KC_F7, KC_F8, KC_F9, KC_F10,   \
         KC_DEL, KC_LEFT,     KC_DOWN,  KC_RIGHT, KC_PGDN,                 KC_DOWN, KC_F4, KC_F5, KC_F6, KC_F11, \
         KC_NO,  KC__VOLUP,   KC_NO,    KC_NO,    KC_FN3,                  KC_NO, KC_F1, KC_F2, KC_F3, KC_F12,   \
         KC_NO,  KC__VOLDOWN, KC_LCTL,  KC_LGUI,  KC_LSFT, KC_FN2, KC_NO,  KC_SPC, KC_BSPC, KC_PSCREEN, KC_SLCK, KC_PAUSE)
};

const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_LAYER_MOMENTARY(1),  // to Fn overlay
  [1] = ACTION_LAYER_ON(2, 1),  // switch to layer 2
  [2] = ACTION_LAYER_OFF(2, 1),  // switch back to layer 0
  [3] = ACTION_FUNCTION(BOOTLOADER)
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  if (id == BOOTLOADER) {
    bootloader();
  }
}
