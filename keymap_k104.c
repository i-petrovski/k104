#include "keymap_common.h"
// K84 key map
//https://github.com/kekstee/tmk_keyboard/tree/master/keyboard/nerd
const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap 0: Default Layer
     * ,-----------------------------------------------------------------------------------------------------.
     * |Esc|   | F1| F2| F3| F4|  | F5| F6| F7| F8|  | F9|F10|F11|F12| |Pscr|Slck|Paus|                      |
     * |-----------------------------------------------------------------------------------------------------|
     * |`  |  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp  |  |Ins |Hom |PgU |  |Lnum|Psls|Past|Pmns|
     * |-----------------------------------------------------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \ |  |Del |End |PgD |  |P7  |P8  |P9  |Ppls|
     * |------------------------------------------------------------------------------------------------|    |
     * |Caps  |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return   |                    |P4  |P5  |P6  |    |
     * |-----------------------------------------------------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift      |      |Up  |        |P1  |P2  |P3  |Pent|
     * |------------------------------------------------------------------------------------------------|    |
     * |Ctrl|Win |Alt |          Space         |Alt|Win |  Fn| Ctrl |  |Lef |Dow |Rig |  |P0       |Pdot|    |
     * `-----------------------------------------------------------------------------------------------------'
     */

    KEYMAP(
         ESC,       F1,  F2, F3,   F4,  F5,  F6,  F7,  F8,  F9, F10, F11, F12, PSCR,SLCK,PAUS, \
         GRV,   1,   2,   3,   4,   5,   6,   7,   8,   9,   0,MINS, EQL,BSPC, INS,HOME,PGUP,     LNUM,PSLS,PAST,PMNS, \
         TAB,   Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,LBRC,RBRC,BSLS, DEL, END,PGDN,     P7,  P8,  P9,PPLS,\
        CAPS,   A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN, QUOT,  ENT,                    P4,  P5,  P6,\
        LSFT,   Z,   X,   C,   V,   B,   N,   M,    COMM,DOT, SLSH,      RSFT,        UP,         P1,  P2,  P3,PENT,\
        LCTL,LGUI,LALT,             SPC,                  RALT,LGUI, FN0,RCTL,  LEFT,DOWN,RGHT,   P0,       PDOT),
    /* Keymap 1: FN Layer 2
     * ,---------------------------------------------------------------------------------=-------------------.
     * |Esc|   | F1| F2| F3| F4|  | F5|Rev|Pau|Mut|  |VoD|VoU|F11|F12| |Pscr|Slck|Paus|                      |
     * |-----------------------------------------------------------------------------------------------------|
     * |`  |  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp  |  |Ins |Hom |PgU |  |Lnum|Psls|Past|Pmns|
     * |-----------------------------------------------------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \ |  |Del |End |PgD |  |P7  |P8  |P9  |Ppls|
     * |------------------------------------------------------------------------------------------------|    |
     * |Caps  |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return   |                    |P4  |P5  |P6  |    |
     * |-----------------------------------------------------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift      |      |Up  |        |P1  |P2  |P3  |Pent|
     * |------------------------------------------------------------------------------------------------|    |
     * |Ctrl|Win |Alt |          Space         |Alt|Win |  Fn| Ctrl |  |Lef |Dow |Rig |  |P0       |Pdot|    |
     * `-----------------------------------------------------------------------------------------------------'
     */
   
    KEYMAP(
        TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,MRWD,MPLY,MFFD,MUTE,VOLD,VOLU, TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,   TRNS, TRNS, TRNS,                    TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,   TRNS,TRNS, TRNS,      TRNS,       TRNS,        TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,            TRNS,                  TRNS,TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS,   TRNS,     TRNS),
};
const action_t PROGMEM fn_actions[] = {
    [0]  = ACTION_LAYER_MOMENTARY(1),
};