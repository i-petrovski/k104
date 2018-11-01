/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

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

/*
 * scan matrix
 */
#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>
#include "print.h"
#include "debug.h"
#include "util.h"
#include "matrix.h"

#ifndef DEBOUNCE
#define DEBOUNCE 5
#endif
static uint8_t debouncing = DEBOUNCE;

/* matrix state(1:on, 0:off) */
static matrix_row_t matrix[MATRIX_ROWS];
static matrix_row_t matrix_debouncing[MATRIX_ROWS];

static matrix_row_t read_cols(void);
static void init_cols(void);
static void unselect_rows(void);
static void select_row(uint8_t row);

void matrix_init(void)
{
    // initialize row and col
    unselect_rows();
    init_cols();

    // initialize matrix state: all keys off
    for (uint8_t i=0; i < MATRIX_ROWS; i++) {
        matrix[i] = 0;
        matrix_debouncing[i] = 0;
    }
}

uint8_t matrix_scan(void)
{
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        select_row(i);
        _delay_us(30);  // without this wait read unstable value.
        matrix_row_t cols = read_cols();
        if (matrix_debouncing[i] != cols) {
            matrix_debouncing[i] = cols;
            if (debouncing) {
                debug("bounce!: "); debug_hex(debouncing); debug("\n");
            }
            debouncing = DEBOUNCE;
        }
        unselect_rows();
    }

    if (debouncing) {
        if (--debouncing) {
            _delay_ms(1);
        } else {
            for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
                matrix[i] = matrix_debouncing[i];
            }
        }
    }

    return 1;
}

inline
matrix_row_t matrix_get_row(uint8_t row)
{
    return matrix[row];
}

/* Column pin configuration
 * col: 0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19  20
 * pin: B6  B5  B7  D0  D1  D2  D3  D4  D5  D6  D7  E0  E1  C0  C1  C2  C3  C4  C5  C6  C7
 */
static void init_cols(void)
{
    // Input with pull-up(DDR:0, PORT:1)
    DDRB  &= ~(1<<6 | 1<<5 | 1<<7);
    PORTB |=  (1<<6 | 1<<5 | 1<<7);
    DDRD  &= ~(1<<7 | 1<<6 | 1<<5 | 1<<4 | 1<<3 | 1<<2 | 1<<1 | 1<<0);
    PORTD |=  (1<<7 | 1<<6 | 1<<5 | 1<<4 | 1<<3 | 1<<2 | 1<<1 | 1<<0);
    DDRE  &= ~(1<<1 | 1<<0);
    PORTE |=  (1<<1 | 1<<0);
    DDRC  &= ~(1<<7 | 1<<6 | 1<<5 | 1<<4 | 1<<3 | 1<<2 | 1<<1 | 1<<0);
    PORTC |=  (1<<7 | 1<<6 | 1<<5 | 1<<4 | 1<<3 | 1<<2 | 1<<1 | 1<<0);
}

static matrix_row_t read_cols(void)
{
    return (PINB&(1<<6) ? 0 : (1UL<<0)) |
           (PINB&(1<<5) ? 0 : (1UL<<1)) |
           (PINB&(1<<7) ? 0 : (1UL<<2)) |
           (PIND&(1<<0) ? 0 : (1UL<<3)) |
           (PIND&(1<<1) ? 0 : (1UL<<4)) |
           (PIND&(1<<2) ? 0 : (1UL<<5)) |
           (PIND&(1<<3) ? 0 : (1UL<<6)) |
           (PIND&(1<<4) ? 0 : (1UL<<7)) |
           (PIND&(1<<5) ? 0 : (1UL<<8)) |
           (PIND&(1<<6) ? 0 : (1UL<<9)) |
           (PIND&(1<<7) ? 0 : (1UL<<10)) |
           (PINE&(1<<0) ? 0 : (1UL<<11)) |
           (PINE&(1<<1) ? 0 : (1UL<<12)) |
           (PINC&(1<<0) ? 0 : (1UL<<13)) |
           (PINC&(1<<1) ? 0 : (1UL<<14)) |
           (PINC&(1<<2) ? 0 : (1UL<<15)) |
           (PINC&(1<<3) ? 0 : (1UL<<16)) |
           (PINC&(1<<4) ? 0 : (1UL<<17)) |
           (PINC&(1<<5) ? 0 : (1UL<<18)) |
           (PINC&(1<<6) ? 0 : (1UL<<19)) |
           (PINC&(1<<7) ? 0 : (1UL<<20));
}

/* Row pin configuration
 * row: 0   1   2   3   4   5
 * pin: F4  F3  F2  F1  F0  E6
 */
static void unselect_rows(void)
{
    // Hi-Z(DDR:0, PORT:0) to unselect
    //pin       76543210
    DDRF  &= ~0b00011110;
    PORTF &= ~0b00011110;
    DDRE  &= ~0b01000000;
    PORTE &= ~0b01000000;
}

static void select_row(uint8_t row)
{
    // Output low(DDR:1, PORT:0) to select
    switch (row) {
        case 0:
            DDRF  |= (1<<4);
            PORTF &= ~(1<<4);
            break;
        case 1:
            DDRF  |= (1<<3);
            PORTF &= ~(1<<3);
            break;
        case 2:
            DDRF |= (1<<2);
            PORTF &= ~(1<<2);
            break;
        case 3:
            DDRF |= (1<<1);
            PORTF &= ~(1<<1);
            break;
        case 4:
            DDRF |= (1<<0);
            PORTF &= ~(1<<0);
            break;
        case 5:
            DDRE |= (1<<6);
            PORTE &= ~(1<<6);
            break;
    }
}