/*
Copyright 2021 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

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

#include "lib/keyball/keyball.h"

//////////////////////////////////////////////////////////////////////////////

// clang-format off
matrix_row_t matrix_mask[MATRIX_ROWS] = {
    0b01110111,
    0b01110111,
    0b01110111,
    0b11110111,
    0b11110111,
    0b01110111,
    0b01110111,
    0b01110111,
    0b11110111,
    0b11110111,
};
// clang-format on

void keyball_on_adjust_layout(keyball_adjust_t v) {
#ifdef RGBLIGHT_ENABLE
    // adjust RGBLIGHT's clipping and effect ranges
    uint8_t lednum_this = keyball.this_have_ball ? 34 : 37;
    uint8_t lednum_that = !keyball.that_enable ? 0 : keyball.that_have_ball ? 34 : 37;
    rgblight_set_clipping_range(is_keyboard_left() ? 0 : lednum_that, lednum_this);
    rgblight_set_effect_range(0, lednum_this + lednum_that);
#endif
}

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = {
  {
    // Key Matrix to LED Index
    {   24,   19,   14, NO_LED,   9,   5,   1, NO_LED }, \
    {   25,   20,   15, NO_LED,   10,   6,   2, NO_LED }, \
    {   26,   21,   16, NO_LED,   11,   7,   3, NO_LED }, \
    {   27,   22,   17, NO_LED,   12,   8,   4,   0  }, \
    {   28,   23,   18, NO_LED,   13,   NO_LED,   NO_LED,   NO_LED }, \
    {   44,   49,   54, NO_LED,   58,   62,   66, NO_LED }, \
    {   45,   50,   55, NO_LED,   59,   63,   67, NO_LED }, \
    {   46,   51,   56, NO_LED,   60,   64,   68, NO_LED }, \
    {   47,   52,   57, NO_LED,   61,   65,   69,   70 }, \
    {   48,   53,   NO_LED, NO_LED,   NO_LED,   NO_LED,   NO_LED,   NO_LED }  \
  },
  {
    // LED Index to Physical Position
    { 0,  0 }, { 17,  0 }, { 34,  0 }, {  51,  0 }, {  68,  0 }, { 85,  0 }, 
    { 0,  16 }, { 17,  16 }, { 34,  16 }, {  51,  16 }, {  68,  16 }, { 85,  16 }, 
    { 0,  32 }, { 17,  32 }, { 34,  32 }, {  51,  32 }, {  68,  32 }, { 85,  32 }, 
    { 0,  48 }, { 17,  48 }, { 34,  48 }, {  51,  48 }, {  68,  48 }, { 85,  48 }, { 102,  48 }, 
    { 0,  64 }, { 17,  64 }, { 34,  64 }, { 51,  64 },
    { 112,  32 }, { 112,  32 }, { 112,  32 }, { 112,  32 }, { 112,  32 }, { 112,  32 }, { 112,  32 }, { 112,  32 }, { 112,  32 }, { 112,  32 }, { 112,  32 }, { 112,  32 }, { 112,  32 }, { 112,  32 }, { 112,  32 },
    { 221,  0 }, { 204,  0 }, { 187,  0 }, { 170,  0 }, { 153,  0 }, { 136,  0 },
    { 221,  16 }, { 204,  16 }, { 187,  16 }, { 170,  16 }, { 153,  16 }, { 136,  16 },
    { 221,  32 }, { 204,  32 }, { 187,  32 }, { 170,  32 }, { 153,  32 }, { 136,  32 },
    { 221,  48 }, { 204,  48 }, { 187,  48 }, { 170,  48 }, { 153,  48 }, { 136,  48 }, { 119,  48 },
    { 221,  64 }, { 204,  64 }
  },
  {
    // LED Index to Flag
    4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4,
    4, 4
  }
};
#endif