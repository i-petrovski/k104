# K104

Pin Usage
-----------------------------------------------------------------------------------------------------------------
PCB to Teensy 2.0++

Matrix pin configuration
------------------------

    col: 0    1    2    3    4    5    6    7    8    9    10   11   12   13   14  15    16   17   18   19   20   
row pin  B6   B5   B7   D0   D1   D2   D3   D4   D5   D6   D7   E0   E1   C0   C1   C2   C3   C4   C5   C6   C7      
  0 F4	 ESC,  F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9, F10, F11, F12,     PSCR,SLCK,PAUS,                     
  1 F3     `,   1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   -,   =,BSPC, INS,HOME,PGDN,LNUM,PSLS,PAST,PMNS
  2 F2   TAB,   Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   [,   ],   \, DEL, END,PGUP,  P7,  P8,  P9,PPLS
  3 F1  CAPS,   A,   S,   D,   F,   G,   H,   J,   K,   L,   ;,   ',      ENT,                 P4,  P5,  P6,
  4 F0  LSFT,   Z,   X,   C,   V,   B,   N,   M,   ,,   .,   /,          RSFT,       UP,       P1,  P2,  P3, PENT
  5 E6  LCTL,LGUI,LALT,                SPC,                RALT,LGUI,FN0,LCTL,LEFT,DOWN,RGHT,  PO,       PDOT

Lock LEDs
---------
Num lock    F7
Caps lock   F6
Scroll lock F5

Backlight Tyeensy to MAX7219 
----------------------------
Clock  B0 ---> pin 13 IC1 & IC2
Load   B1 ---> pin 12 IC1 & IC2
Data   B2 ---> pin 1  IC2

MAX7219 pin configuration
-------------------------
IC1 - MAX7219 
-------------
pin       2     11    6     7     3     10    5     8
          DIG0  DIG1  DIG2  DIG3  DIG4  DIG5  DIG6  DIG7
 14 SEGA  LCRL  LGUI  LALT  SPC   RALT  RGUI  FN0   RCRL
 16 SEGB  LSFT  Z     X     C     V     B     N     M
 20 SEGC  CAPS  A     S     D     F     G     H     J
 23 SEGD  TAB   Q     W     E     R     T     Y     U
 21 SWGE  GRV   1     2     3     4     5     6     7
 15 SWGF  ESC   F1    F2    F3    F4    F5    F6    F7
 17 SWGG  F8    F9    F10   F11   F12   PSCR  SLCK  PAUS
 22 SWGDP 8     9     0     MINS  EQL   BSPC  INT   HOME

Clock pin 13 ---> pin B0 Teensy
Load  pin 12 ---> pin B1 Teensy
DIN   pin 1  ---> pin 24 IC2 (DOUT)

IC2 - MAX7219 
-------------
pin       2     11    6     7     3     10    5     8
          DIG0  DIG1  DIG2  DIG3  DIG4  DIG5  DIG6  DIG7
 14 SEGA  I     O     P     [     ]     \     DEL   END
 16 SEGB  K     L     ;     '     ENT   P4    P5    P6
 20 SEGC  ,     .     /     RSFT  UP    P1    P2    P3
 23 SEGD  PGUP  LNUM  PSLS  PAST  PMNS  PDOT 
 21 SEGE  PGDN  P7    P8    P9    PPLS 
 15 SEGF  LEFT  DOWN  RGHT  P0    PENT
 17 SEGG                          
 22 SEGDP


Clock pin 13 ---> pin B0 Teensy
Load  pin 12 ---> pin B1 Teensy
DIN   pin 1  ---> pin B2 Teensy
DOUT  pin 24 ---> pin 1  IC1 (DIN)
