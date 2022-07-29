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
#ifdef RIGHT_BALL
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
    {   48,   53,   NO_LED, NO_LED,   NO_LED,   NO_LED,   NO_LED,   NO_LED },  \
  },
  {
    // LED Index to Physical Position
    // Left split.
    /* index=0  */ { 112,  48 },
    /* index=1  */ {  93,   0 }, {  93,  16 }, {  93,  32 }, {  93,  48 },
    /* index=5  */ {  74,   0 }, {  74,  16 }, {  74,  32 }, {  74,  48 },
    /* index=9  */ {  56,   0 }, {  56,  16 }, {  56,  32 }, {  56,  48 }, {  56,  64 },
    /* index=14 */ {  37,   0 }, {  37,  16 }, {  37,  32 }, {  37,  48 }, {  37,  64 },
    /* index=19 */ {  19,   0 }, {  19,  16 }, {  19,  32 }, {  19,  48 }, {  19,  64 },
    /* index=24 */ {   0,   0 }, {   0,  16 }, {   0,  32 }, {   0,  48 }, {   0,  64 },
    // Underglow
    /* index=29 */ { 112,  32 }, { 112,  32 }, { 112,  32 }, { 112,  32 }, { 112,  32 }, { 112,  32 }, { 112,  32 }, { 112,  32 }, { 112,  32 }, { 112,  32 }, { 112,  32 }, { 112,  32 }, { 112,  32 }, { 112,  32 }, { 112,  32 },
    // Right split.
    /* index=44 */ { 224,   0 }, { 224,  16 }, { 224,  32 }, { 224,  32 }, { 224,  64 },
    /* index=49 */ { 206,   0 }, { 206,  16 }, { 206,  32 }, { 206,  48 }, { 206,  64 },
    /* index=54 */ { 187,   0 }, { 187,  16 }, { 187,  32 }, { 187,  48 },
    /* index=58 */ { 169,   0 }, { 169,  16 }, { 169,  32 }, { 169,  48 },
    /* index=62 */ { 150,   0 }, { 150,  16 }, { 150,  32 }, { 150,  48 },
    /* index=66 */ { 132,   0 }, { 132,  16 }, { 132,  32 }, { 132,  48 },
    /* index=70 */ { 113,  48 },
  },
  {
    // LED Index to Flag
    // Left split.
    /* index=0  */ 4,
    /* index=1  */ 4, 4, 4, 4,
    /* index=5  */ 4, 4, 4, 4,
    /* index=9  */ 4, 4, 4, 4, 4,
    /* index=14 */ 4, 4, 4, 4, 4,
    /* index=19 */ 4, 4, 4, 4, 4,
    /* index=24 */ 4, 4, 4, 4, 4,
    // Underglow
    /* index=29 */ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    // Right split.
    /* index=44 */ 4, 4, 4, 4, 4,
    /* index=49 */ 4, 4, 4, 4, 4,
    /* index=54 */ 4, 4, 4, 4,
    /* index=58 */ 4, 4, 4, 4,
    /* index=62 */ 4, 4, 4, 4,
    /* index=66 */ 4, 4, 4, 4,
    /* index=70 */ 4,
  }
};
#endif

#ifdef LEFT_BALL
#endif
#ifdef DUAL_BALL
#endif
#ifdef NO_BALL
#endif
#endif