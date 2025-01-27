// SPDX-License-Identifier: GPL-3.0-or-later

#include QMK_KEYBOARD_H

#include "version.h"
#include "features/mine.c"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_moonlander(
    KC_GRV  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , _______ ,               _______ , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_MINS ,
    KC_ESC  , KC_Q    , KC_W    , KC_F    , KC_P    , KC_B    , _______ ,               _______ , KC_J    , KC_L    , KC_U    , KC_Y    , KC_SCLN , KC_EQL  ,
    KC_BSPC , M_A     , M_R     , M_S     , M_T     , KC_G    , _______ ,               _______ , KC_M    , M_N     , M_E     , M_I     , M_O     , KC_QUOT ,
    _______ , KC_Z    , KC_X    , KC_C    , KC_D    , KC_V    ,                                   KC_K    , KC_H    , KC_COMM , KC_DOT  , KC_SLSH , MO(3)   ,
    _______ , _______ , _______ , _______ , _______ ,           KC_HYPR ,               KC_ESC  , _______ , _______ , _______ , _______ , _______ ,

                                            M_SPC   , KC_TAB  , _______ ,               _______ , KC_ENT  , M_BSPC
  ),
  [SYM] = LAYOUT_moonlander(
    KC_ESC  , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , _______ ,               _______ , KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  ,
    _______ , KC_EXLM , KC_LCBR , KC_RCBR , KC_PIPE , KC_PERC , _______ ,               _______ , KC_7    , KC_8    , KC_9    , KC_MINS , KC_SLSH , KC_F12  ,
    _______ , KC_DLR  , KC_LPRN , KC_RPRN , KC_GRV  , KC_HASH , _______ ,               _______ , KC_4    , KC_5    , KC_6    , KC_PLUS , KC_ASTR , KC_BSPC ,
    _______ , KC_AMPR , KC_LBRC , KC_RBRC , KC_TILD , KC_CIRC ,                                   KC_1    , KC_2    , KC_3    , KC_DOT  , KC_BSLS , KC_ENT  ,
    _______ , _______ , _______ , _______ , _______ ,           _______ ,               _______ ,           _______ , _______ , _______ , _______ , _______ ,
                                            _______ , _______ , _______ ,               _______ , _______ , _______
  ),
  [NUM] = LAYOUT_moonlander(
    _______ , _______ , _______ , _______ , _______ , _______ , _______ ,               _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ ,               _______ , _______ , _______ , KC_UP   , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ ,               _______ , _______ , KC_LEFT , KC_DOWN , KC_RGHT , _______ , _______ ,
    _______ , _______ , M_AE    , M_OE    , M_AA    , _______ ,                                   _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ ,           _______ ,               _______ ,           _______ , _______ , _______ , _______ , _______ ,
                                            _______ , _______ , _______ ,               _______ , _______ , _______
  ),
  [SYS] = LAYOUT_moonlander(
    RM_TOGG , QK_KB   , RM_NEXT , RGB_M_P , UG_VALD , UG_VALU , _______ ,               _______ , _______ , _______ , _______ , _______ , _______ , QK_BOOT ,
    _______ , _______ , KC_VOLD , KC_VOLU , KC_MUTE , _______ , _______ ,               _______ , KC_PGUP , KC_HOME , _______ , KC_END  , _______ , _______ ,
    _______ , KC_MPRV , KC_MNXT , KC_MSTP , KC_MPLY , _______ , _______ ,               _______ , KC_PGDN , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ ,                                   _______ , M_CST   , M_CT    , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ ,           _______ ,               _______ ,           _______ , _______ , _______ , _______ , _______ ,
                                            _______ , _______ , _______ ,               _______ , _______ , _______
  ),
};
