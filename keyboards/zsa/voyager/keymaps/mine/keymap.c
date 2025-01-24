// SPDX-License-Identifier: GPL-3.0-or-later

#include QMK_KEYBOARD_H

#include "version.h"
#include "features/mine.c"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_voyager(
    KC_GRV  , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,       
    KC_ESC  , KC_Q  , KC_W  , KC_F  , KC_P  , KC_B  ,                                           KC_J,           KC_L,           KC_U,           KC_Y,           KC_SCLN,        KC_EQUAL,       
    MT(MOD_LSFT, KC_BSPC),MT(MOD_LGUI, KC_A),MT(MOD_LALT, KC_R),MT(MOD_LCTL, KC_S),MT(MOD_LSFT, KC_T),KC_G,                                           KC_M,           MT(MOD_RSFT, KC_N),MT(MOD_RCTL, KC_E),MT(MOD_RALT, KC_I),MT(MOD_RGUI, KC_O),MT(MOD_RSFT, KC_QUOTE),
    _______, KC_Z   , KC_X  , KC_C  , KC_D  , KC_V  ,                                           KC_K,           KC_H,           KC_COMMA,       KC_DOT,         KC_SLASH,       MO(3),          
                                              LT(1,KC_SPACE), KC_TAB,                                         KC_ENTER,       LT(2,KC_BSPC)
  ),
  [SYM] = LAYOUT_voyager(
    KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
    KC_ASTR,        KC_EXLM,        KC_LCBR,        KC_RCBR,        KC_PIPE,        KC_PERC,                                        KC_7,           KC_8,           KC_9,           KC_MINUS,       KC_SLASH,       KC_F12,         
    _______, KC_DLR,         KC_LPRN,        KC_RPRN,        KC_GRAVE,       KC_HASH,                                        KC_4,           KC_5,           KC_6,           KC_PLUS,        KC_ASTR,        KC_BSPC,        
    _______, KC_AMPR,        KC_LBRC,        KC_RBRC,        KC_TILD,        KC_CIRC,                                        KC_1,           KC_2,           KC_3,           KC_DOT,         KC_BSLS,        KC_ENTER,       
                                                    _______, _______,                                 _______, KC_0
  ),
  [NUM] = LAYOUT_voyager(
    _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, 
    _______, _______, _______, _______, _______, _______,                                 _______, _______, KC_UP,          _______, _______, _______, 
    _______, _______, _______, _______, _______, _______,                                 _______, KC_LEFT,        KC_DOWN,        KC_RIGHT,       _______, _______, 
    _______, _______, LALT(KC_QUOTE), LALT(KC_O),     LALT(KC_A),     _______,                                 _______, _______, _______, _______, _______, _______, 
                                                    _______, _______,                                 _______, _______
  ),
  [SYS] = LAYOUT_voyager(
    RM_TOGG,        QK_KB,RM_NEXT,RGB_M_P,        UG_VALD,        UG_VALU,                                        _______, _______, _______, _______, _______, QK_BOOT,        
    _______, _______, KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE,  _______,                                 KC_PAGE_UP,     KC_HOME,        _______, KC_END,         _______, _______, 
    _______, KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_MEDIA_STOP,  KC_MEDIA_PLAY_PAUSE,_______,                                 KC_PGDN,        _______, _______, _______, _______, _______, 
    _______, _______, _______, _______, _______, _______,                                 _______, LCTL(LSFT(KC_TAB)),LCTL(KC_TAB),   _______, _______, _______, 
                                                    _______, _______,                                 _______, _______
  ),
};
