/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>
#include "crkbd.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x5_3(
  //,--------------------------------------------------------------------.                                 ,-----------------------------------------------------------------------------.
      KC_Q,           KC_W,          KC_E,          KC_R,           KC_T,                                    KC_Y,    KC_U,           KC_I,             KC_O,            KC_P,
  //|---------------+--------------+--------------+---------------+------|                                 |--------+---------------+-----------------+----------------+-----------------|
      LSFT_T(KC_A),   KC_S,          KC_D,          KC_F,           KC_G,                                    KC_H,    KC_J,           KC_K,             KC_L,            RSFT_T(KC_SCLN),
  //|---------------+--------------+--------------+---------------+------|                                 |--------+---------------+-----------------+----------------+-----------------|
      LCTL_T(KC_Z),  LALT_T(KC_X),  LGUI_T(KC_C),  KC_V,           KC_B,                                    KC_N,    KC_M,           RGUI_T(KC_COMM),  RALT_T(KC_DOT),  RCTL_T(KC_SLSH),
  //|---------------+--------------+--------------+---------------+------+---------------|  |---------------+--------+---------------+----------------+----------------+-----------------|
                                                    LT(1, KC_ESC), KC_SPC, LT(4, KC_TAB),     LT(3, KC_ENT), KC_BSPC,  LT(2, KC_DEL)
                                              //`----------------------------------------'  '----------------------------------------'

  ),

  [1] = LAYOUT_split_3x5_3(
  //,----------------------------------------------.                    ,----------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_AGAIN,                      XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX,   XXXXXXX,
  //|--------+--------+--------+--------+----------|                    |--------+--------+--------+----------+--------|
      KC_LSFT, KC_CUT, KC_COPY, KC_PASTE, KC_UNDO,                       XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT,  XXXXXXX,
  //|--------+--------+--------+--------+----------|                    |--------+--------+--------+----------+--------|
      KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,
  //|--------+--------+--------+--------+----------+--------|  |--------+--------+--------+--------+----------+--------|
                                 XXXXXXX, XXXXXXX,  XXXXXXX,     KC_ENT, KC_BSPC, KC_DEL
                              //`---------------------------'  `--------------------------'
  ),

  [2] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      KC_PERC, KC_1,    KC_2,    KC_3,    KC_ASTR,                      KC_VOLU, KC_BRMU, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_EQL,  KC_4,    KC_5,    KC_6,    KC_SLSH,                      KC_VOLD, KC_BRMD, XXXXXXX, XXXXXXX, KC_RSFT,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_HASH, KC_7,    KC_8,    KC_9,    KC_PLUS,                      KC_MUTE, XXXXXXX, KC_RGUI, KC_RALT, KC_RCTL,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                KC_COMM, KC_0, KC_MINS,       XXXXXXX, XXXXXXX, XXXXXXX
                             //`--------------------------'  '--------------------------'
  ),

  [3] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,---------------------------------------------.
      KC_EXLM, KC_QUES, KC_QUOT, KC_LABK, KC_RABK,                     KC_VOLU, KC_BRMU, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+---------|
      KC_AMPR, KC_BSLS, KC_DLR, KC_LPRN, KC_RPRN,                      KC_VOLD, KC_BRMD,  XXXXXXX, XXXXXXX, KC_RSFT,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+---------|
      KC_CIRC, KC_GRV,  KC_AT,  KC_LBRC, KC_RBRC,                      KC_MUTE, XXXXXXX, KC_RGUI, KC_RALT, KC_RCTL,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+---------|
                                KC_LCBR, KC_RCBR, KC_UNDS,    XXXXXXX, XXXXXXX, XXXXXXX
                             //`--------------------------'  '--------------------------'
  ),

  [4] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,---------------------------------------------.
     KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX,                      KC_VOLU, KC_BRMU, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+---------|
     KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX,                      KC_VOLD, KC_BRMD, XXXXXXX, XXXXXXX, KC_RSFT,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+---------|
      KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX,                      KC_MUTE, XXXXXXX, KC_RGUI, KC_RALT, KC_RCTL,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+---------|
                                XXXXXXX, XXXXXXX, XXXXXXX,    KC_TAB, KC_SPC, XXXXXXX
                             //`--------------------------'  `--------------------------'
  )
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_90;  // flips the display 180 degrees if offhand
}
bool oled_task_user() {
    oled_set_cursor(0,1);
    oled_write("Layer: ", false);
    return false;
}
#endif // OLED_ENABLE
