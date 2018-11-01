# K104

Pin Usage
-----------------------------------------------------------------------------------------------------------------
PCB to Teensy 2.0++

Matrix pin configuration
------------------------

    col: 0    1    2    3    4    5    6    7    8    9    10   11   12   13   14  15    16   17   18   19   20   
row pin  B6   B5   B7   D0   D1   D2   D3   D4   D5   D6   D7   E0   E1   C0   C1   C2   C3   C4   C5   C6   C7      
  0 F4	 K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C,      K0E, K0F, K10,                     
  1 F3   K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, K1E, K1F, K20, K21, K22, K23, K24, K25, K26, K27, K28, K29,
  2 F2   K2A, K2B, K2C, K2D, K2E, K2F, K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, K3E,
  3 F1   K3F, K40, K41, K42, K43, K44, K45, K46, K47, K48, K49, K4A,      K4C,                K50, K51, K52,
  4 F0   K54, K55, K56, K57, K58, K59, K5A, K5B, K5C, K5D, K5E,           K61,      K63,      K65, K66, K67, K68,
  5 E6   K69, K6A, K6B,                K6F,                K73, K74, K75, K76, K77, K78, K79, K7A,      K7C

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
IC1
pin       2     11    6     7     3     10    5     8
          DIG0  DIG1  DIG2  DIG3  DIG4  DIG5  DIG6  DIG7
 14 SEGA  LCRL  WIN   LALT  SBAR  RALT  RWIN  MENU  RCRL
 16 SEGB  LSFT  Z     X     C     V     B     N     M
 20 SEGC  CAPS  A     S     D     F     G     H     J
 23 SEGD  TAB   Q     W     E     R     T     Y     U
 21 SWGE  `     1     2     3     4     5     6     7
 15 SWGF  ESC   F1    F2    F3    F4    F5    F6    F7
 17 SWGG  F8    F9    F10   F11   F12   PRTSC SLCOK PAUS
 22 SWGDP 8     9     0     -     =     BKSPA INS   HOME

Clock pin 13 ---> pin B0 Teensy
Load  pin 12 ---> pin B1 Teensy
DIN   pin 1  ---> pin 24 IC2 (DOUT)

IC2
pin       2     11    6     7     3     10    5     8
          DIG0  DIG1  DIG2  DIG3  DIG4  DIG5  DIG6  DIG7
 14 SEGA  I     O     P     [     ]     \     DEL   END
 16 SEGB  K     L     ;     '     ENT   NUM4  NUM5  NUM6
 20 SEGC  ,     .     /     RSFT  UARO  NUM1  NMU2  NMU3
 23 SEGD  PGUP  NUMLK NUM/  NUM*  NUM-  NUM. 
 21 SEGE  PGDN  NUM7  NUM8  NUM9  NUM+ 
 15 SEGF  LARO  DARO  RARO  NUM0  NUMENT
 17 SEGG                          
 22 SEGDP

Clock pin 13 ---> pin B0 Teensy
Load  pin 12 ---> pin B1 Teensy
DIN   pin 1  ---> pin B2 Teensy
DOUT  pin 24 ---> pin 1  IC1 (DIN)