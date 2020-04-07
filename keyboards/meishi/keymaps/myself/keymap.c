/* Copyright 2017 Biacco42
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
// #include "process_unicode.h"

enum custom_keycodes {
    MEISHI_1,
    MEISHI_2,
    MEISHI_3,
    MEISHI_4
};

enum unicode_names {
  BEER,
  HEART,
  STAR,
  FLOWER,
  BEAR
};

const uint32_t PROGMEM unicode_map[] = {
    [BEER] = 0x1f37a,
    [HEART] = 0x2764,
    [STAR] = 0x2B50,
    [FLOWER] = 0x1F338,
    [BEAR] = 0x1F43B

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT(
    MEISHI_1,
    MEISHI_2,
    MEISHI_3,
    MEISHI_4
    // M(0) // MACRO
    // X(BEER)
),
};

const uint16_t PROGMEM fn_actions[] = {

};

void matrix_init_user(void) {
  // OSXのOSにUnicode対応
//   set_unicode_input_mode(UC_WINC);
  set_unicode_input_mode(UC_OSX);
}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MEISHI_1:
      if (record->event.pressed) {
        // SEND_STRING("はじめまして。");
        send_unicode_hex_string("306F 3058 3081 307E 3057 3066 3002");
        // send_unicode_hex_string("306F 3058 3081 307E 3057 3066");
        // SEND_STRING(SS_LALT("D83CDF7A"));  // 🍺Beerのサロゲートペア
      }
      break;
    case MEISHI_2:
      if (record->event.pressed) {
        // SEND_STRING("鈴無蒸と申します。");
        send_unicode_hex_string("9234 7121 84B8 3068 7533 3057 307E 3059 3002");
      }
      break;
    case MEISHI_3:
      if (record->event.pressed) {
        // SEND_STRING("どうぞよろしくお願いいたします。");
        send_unicode_hex_string("3069 3046 305E 3088 308D 3057 304F 304A 9858 3044 3044 305F 3057 307E 3059 3002");
      }
      break;
    case MEISHI_4:
      if (record->event.pressed) {
        // SEND_STRING("まほプリ最高‼♥⭐🌸🐻");
        send_unicode_hex_string("307E 307B 30D7 30EA 5927 597D 304D");
        SEND_STRING(SS_LALT("D83EDDE1")); // 🧡オレンジハートのサロゲートペア
        send_unicode_hex_string("2B50");  // ⭐
        SEND_STRING(SS_LALT("D83CDF38")); // 🌸花のサロゲートペア
        SEND_STRING(SS_LALT("D83DDC3B"));  // 🐻熊のサロゲートペア
        // SEND_STRING(SS_LALT("D83DDCA9"));  // 💩うんこのサロゲートペアでの入力
        // SEND_STRING(SS_DOWN(X_LALT) "D83DDCA9" SS_UP(X_LALT)); // 💩うんこのサロゲートペアでの入力
      }
      break;
  }
  return true;
}

void led_set_user(uint8_t usb_led) {

}

// const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
//   switch (id) {
//     case 0:  // id=0のマクロ定義
//       if (record->event.pressed) {
//         return MACRO(D(LSFT), T(H), U(LSFT), T(E), T(L), T(L), T(O), END);  // keydown時の動作('Hello'と入力)
//       }
//       break;
//     case 1:  // id=1のマクロ定義
//       if (!record->event.pressed) {
//         return MACRO(D(LSFT), T(B), U(LSFT), T(Y), T(E), END);  // keyup時の動作('Bye'と入力)
//       }
//       break;
//   }
//   return MACRO_NONE;
// }
