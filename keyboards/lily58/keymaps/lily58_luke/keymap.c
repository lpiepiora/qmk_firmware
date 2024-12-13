 /* Copyright 2017 F_YUUCHI
  * Copyright 2020 Drashna Jaelre <@drashna>
  * Copyright 2020 Ben Roesner (keycapsss.com)
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 2 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */

#include QMK_KEYBOARD_H


extern uint8_t is_master;

enum layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_QWERTY] = LAYOUT(
    KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5,                                             KC_6, KC_7, KC_8, KC_9, KC_0, KC_GRV,
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                                            KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
    KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G,                                         KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_SPC,                   KC_ENT, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
    KC_RCTL, KC_LGUI, RAISE, KC_ENT,                                                        KC_SPC, LOWER, KC_RALT, KC_RCTL
),

[_LOWER] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TAB, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
    C(S(KC_TAB)), C(KC_TAB), KC_LCTL, KC_LALT, KC_LGUI, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO,
    KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_END, KC_PGDN, KC_PGUP, KC_HOME, KC_RCTL, KC_DEL,
    KC_TRNS, KC_RGUI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_RALT, KC_TRNS
),

[_RAISE] = LAYOUT(
    KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_NO,
    KC_TAB, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LCBR, KC_RCBR, KC_BSPC,
    KC_ESC, KC_NO,KC_LCTL, KC_LALT, KC_LGUI, KC_NO, KC_PLUS, KC_UNDS, KC_BSLS, KC_LPRN, KC_RPRN, KC_GRV,
    KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_MINS, KC_EQL, KC_PIPE, KC_LBRC, KC_RBRC, KC_TILD,
    KC_TRNS, KC_LGUI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_RALT, KC_TRNS
),

[_ADJUST] = LAYOUT(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, QK_BOOT, QK_BOOT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
    return state;
}

