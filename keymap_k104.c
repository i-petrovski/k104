#include "keymap_common.h"
#include "ledmatrix_common.h"
#include "ledmatrix_k104.h"
#include "timer.h"
#include "led.h"
#include <util/delay.h>

uint16_t my_led_timer=0;
uint16_t array_row=0;
// K104 key map
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
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift      |       |Up  |       |P1  |P2  |P3  |Pent|
     * |------------------------------------------------------------------------------------------------|    |
     * |Ctrl|Win |Alt |          Space         |Alt|Win |  Fn| Ctrl |  |Lef |Dow |Rig |  |P0       |Pdot|    |
     * `-----------------------------------------------------------------------------------------------------'
     */

    KEYMAP(
         ESC,       F1,  F2, F3,   F4,  F5,  F6,  F7,  F8,  F9, F10, F11, F12, PSCR,SLCK,PAUS,                       \
         GRV,   1,   2,   3,   4,   5,   6,   7,   8,   9,   0,MINS, EQL,BSPC,  INS,HOME,PGUP,  LNUM,PSLS,PAST,PMNS, \
         TAB,   Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,LBRC,RBRC,BSLS,  DEL, END,PGDN,  P7,  P8,  P9,PPLS,   \
        CAPS,   A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN, QUOT,  ENT,                  P4,  P5,  P6,        \
        LSFT,   Z,   X,   C,   V,   B,   N,   M,    COMM,DOT, SLSH,      RSFT,        UP,       P1,  P2,  P3,PENT,   \
        LCTL,LGUI,LALT,             SPC,                  RALT,RGUI, FN0,RCTL, LEFT,DOWN,RGHT,  P0,       PDOT),
    /* Keymap 1: FN Layer 2
     * ,-----------------------------------------------------------------------------------------------------.
     * |Esc|   | F1| F2| F3| F4|  | F5|Rev|Pau|Mut|  |VoD|VoU|F11|F12| |Pscr|Slck|Paus|                      |
     * |-----------------------------------------------------------------------------------------------------|
     * |`  |  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp  |  |Ins |Hom |PgU |  |Lnum|Psls|Past|Pmns|
     * |-----------------------------------------------------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \ |  |Del |End |PgD |  |P7  |P8  |P9  |Ppls|
     * |------------------------------------------------------------------------------------------------|    |
     * |Caps  |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return   |                    |P4  |P5  |P6  |    |
     * |-----------------------------------------------------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift      |       |Up  |       |P1  |P2  |P3  |Pent|
     * |------------------------------------------------------------------------------------------------|    |
     * |Ctrl|Win |Alt |          Space         |Alt|Win |  Fn| Ctrl |  |Lef |Dow |Rig |  |P0       |Pdot|    |
     * `-----------------------------------------------------------------------------------------------------'
     */
   
    KEYMAP(
        TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,MRWD,MPLY,MFFD,MUTE,VOLD,VOLU, TRNS,TRNS,TRNS,                       \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,   TRNS, TRNS, TRNS,                  TRNS,TRNS,TRNS,      \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,   TRNS,TRNS, TRNS,      TRNS,      TRNS,       TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,            TRNS,                  TRNS,TRNS,TRNS,TRNS, TRNS,TRNS,TRNS,  TRNS,     TRNS),
};
const action_t PROGMEM fn_actions[] = {
    [0]  = ACTION_LAYER_MOMENTARY(1),
};

// init matrix ics 
void hook_early_init(void) 
{
    led_matrix_init();
    // Power all LED on  
    for (array_row=0; array_row<104; array_row++)
    {
        write(LEDARR[array_row][0],LEDARR[array_row][1],LEDON);
        _delay_ms(10);
    }
 }