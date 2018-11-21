/*
K104 Matrix key mapping MAX7219
             |                  IC2 - MAX7219          |    
             0     1     2     3     4     5     6     7    
    pin      2     11    6     7     3     10    5     8     
             DIG0  DIG1  DIG2  DIG3  DIG4  DIG5  DIG6  DIG7  
15  14 SEGA  I     O     P     LBRC  LBRC  BSLS  DEL   END
14  16 SEGB  K     L     SCLN  QUOT  ENT   P4    P5    P6
13  20 SEGC  COMM  DOT   SLS   RSFT  Up    P1    P2    P3
12  23 SEGD  PGUP  LNUM  PSLS  PAST  PMNS  PDOT
11  21 SWGE  PGDN  P7    P8    P9    PPLS
10  15 SWGF  LEFT  DOWN  RGHT  P0    PENT
 9  17 SWGG 
 8  22 SWGDP
              |                  IC1 - MAX7219          |
              0     1     2     3     4     5     6     7    
 7  14 SEGA  LCTL  LGUI  LALT  SPC   RALT  RGUI  FN0   RCRL  
 6  16 SEGB  LSFT  Z     X     C     V     B     N     M     
 5  20 SEGC  CAPS  A     S     D     F     G     H     J     
 4  23 SEGD  TAB   Q     W     E     R     T     Y     U     
 3  21 SWGE  GRV   1     2     3     4     5     6     7      
 2  15 SWGF  ESC   F1    F2    F3    F4    F5    F6    F7    
 1  17 SWGG  F8    F9    F10   F11   F12   PSCR  SLCK  PAUS
 0  22 SWGDP 8     9     0     MINS  EQL   BSPC  INS   HOME
*/

// IC2 - MAX7219   
#define LED_I     15,0
#define LED_O     15,1
#define LED_P     15,2
#define LED_LBRC  15,3
#define LED_RBRC  15,4
#define LED_BSLS  15,5
#define LED_DEL   15,6
#define LED_END   15,7
#define LED_K     14,0
#define LED_L     14,1
#define LED_SCLN  14,2
#define LED_QUOT  14,3
#define LED_ENT   14,4
#define LED_P4    14,5
#define LED_P5    14,6
#define LED_P6    14,7
#define LED_COMM  13,0
#define LED_DOT   13,1
#define LED_SLSH  13,2
#define LED_RSFT  13,3
#define LED_UP    13,4
#define LED_P1    13,5
#define LED_P2    13,6
#define LED_P3    13,7
#define LED_PGUP  12,0
#define LED_LNUM  12,1
#define LED_PSLS  12,2 
#define LED_PAST  12,3
#define LED_PMNS  12,4
#define LED_PDOT  12,5
#define LED_PGDN  11,0
#define LED_P7    11,1
#define LED_P8    11,2
#define LED_P9    11,3
#define LED_PPLS  11,4
#define LED_LEFT  10,0
#define LED_DOWN  10,1
#define LED_RGHT  10,2
#define LED_P0    10,3
#define LED_PENT  10,4
// IC2 - MAX7219  
#define LED_LCTL  7,0
#define LED_LGUI  7,1
#define LED_LALT  7,2
#define LED_SPC   7,3
#define LED_RALT  7,4
#define LED_RGUI  7,5
#define LED_FN0   7,6
#define LED_RCTL  7,7
#define LED_LSFT  6,0
#define LED_Z     6,1
#define LED_X     6,2
#define LED_C     6,3
#define LED_V     6,4
#define LED_B     6,5
#define LED_N     6,6
#define LED_M     6,7
#define LED_CAPS  5,0
#define LED_A     5,1
#define LED_S     5,2
#define LED_D     5,3
#define LED_F     5,4
#define LED_G     5,5
#define LED_H     5,6
#define LED_J     5,7
#define LED_TAB   4,0
#define LED_Q     4,1
#define LED_W     4,2
#define LED_E     4,3
#define LED_R     4,4
#define LED_T     4,5
#define LED_Y     4,6
#define LED_U     4,7
#define LED_GRV   3,0
#define LED_1     3,1
#define LED_2     3,2
#define LED_3     3,3
#define LED_4     3,4
#define LED_5     3,5
#define LED_6     3,6
#define LED_7     3,7
#define LED_ESC   2,0
#define LED_F1    2,1
#define LED_F2    2,2
#define LED_F3    2,3
#define LED_F4    2,4
#define LED_F5    2,5
#define LED_F6    2,6
#define LED_F7    2,7
#define LED_F8    1,0
#define LED_F9    1,1
#define LED_F10   1,2
#define LED_F11   1,3
#define LED_F12   1,4
#define LED_PSCR  1,5
#define LED_SLCK  1,6
#define LED_PAUS  1,7
#define LED_8     0,0
#define LED_9     0,1
#define LED_0     0,2
#define LED_MINS  0,3
#define LED_EQL   0,4
#define LED_BSPC  0,5
#define LED_INS   0,6
#define LED_HOME  0,7

uint8_t LEDARR [104][2] = {{LED_ESC}, {LED_F1}, {LED_F2}, {LED_F3}, {LED_F4}, {LED_F5}, {LED_F6}, {LED_F7}, {LED_F8}, {LED_F9}, {LED_F10}, {LED_F11}, {LED_F12}, {LED_PSCR}, {LED_SLCK}, {LED_PAUS},\
    {LED_GRV}, {LED_1}, {LED_2}, {LED_3}, {LED_4}, {LED_5}, {LED_6}, {LED_7}, {LED_8}, {LED_9}, {LED_0}, {LED_MINS}, {LED_EQL}, {LED_BSPC}, {LED_INS}, {LED_HOME}, {LED_PGUP}, {LED_LNUM}, {LED_PSLS}, {LED_PAST}, {LED_PMNS},\
    {LED_TAB}, {LED_Q}, {LED_W}, {LED_E}, {LED_R}, {LED_T}, {LED_Y}, {LED_U}, {LED_I}, {LED_O}, {LED_P}, {LED_LBRC}, {LED_RBRC}, {LED_BSLS}, {LED_DEL}, {LED_END}, {LED_PGDN}, {LED_P7}, {LED_P8}, {LED_P9}, {LED_PPLS},\
    {LED_CAPS}, {LED_A}, {LED_S}, {LED_D}, {LED_F}, {LED_G}, {LED_H}, {LED_J}, {LED_K}, {LED_L}, {LED_SCLN}, {LED_QUOT}, {LED_ENT}, {LED_P4}, {LED_P5}, {LED_P6},\
    {LED_LSFT}, {LED_Z}, {LED_X}, {LED_C}, {LED_V}, {LED_B}, {LED_N}, {LED_M}, {LED_COMM}, {LED_DOT}, {LED_SLSH}, {LED_RSFT}, {LED_UP}, {LED_P1}, {LED_P2}, {LED_P3}, {LED_PENT},\
    {LED_LCTL}, {LED_LGUI}, {LED_LALT}, {LED_SPC}, {LED_RALT}, {LED_RGUI}, {LED_FN0}, {LED_RCTL}, {LED_LEFT}, {LED_DOWN}, {LED_RGHT}, {LED_P0}, {LED_PDOT}};
