// Load Pin high and low 
#define clock_low  PORTB &= ~(1 << 0)
#define clock_high PORTB |= (1 << 0)
#define load_low    PORTB &= ~(1 << 1)
#define load_high  PORTB |= (1 << 1)
#define din_low    PORTB &= ~(1 << 2)
#define din_high   PORTB |= (1 << 2)

// Screen Count
// #define screenCount 1;
#define screenCount 2
#define _maximumX 16

// define High and Low bit.
#define LEDON 1
#define LEDOFF 0

// Matrix registers
#define REG_NOOP   0x00
#define REG_DIGIT0 0x01
#define REG_DIGIT1 0x02
#define REG_DIGIT2 0x03
#define REG_DIGIT3 0x04
#define REG_DIGIT4 0x05
#define REG_DIGIT5 0x06
#define REG_DIGIT6 0x07
#define REG_DIGIT7 0x08
#define REG_DECODEMODE  0x09
#define REG_INTENSITY   0x0A
#define REG_SCANLIMIT   0x0B
#define REG_SHUTDOWN    0x0C
#define REG_DISPLAYTEST 0x0F

#include <avr/io.h>
#include <util/delay.h>

//uint8_t _buffer [7] = {0};
uint8_t _buffer [0];

void set_byte(uint8_t data)
{
  uint8_t i = 8;
  uint8_t mask;
  while(i > 0) {
    mask = 0x01 << (i - 1);         // get bitmask
    clock_low;                       // tick
    if (data & mask){               // choose bit
      din_high;                      // set to 1
    }
    else{
      din_low;                       // set to 0
    }
    clock_high;                      // tock
    --i;                            // move to lesser bit
  }
}

void set_register(uint8_t reg, uint8_t data)
{
  uint8_t i;
  load_low ;             // begin
  for(i = 0; i < screenCount; ++i)
  {
    set_byte(reg);     // Send the register data to the ic.
    set_byte(data);    // Send the data to the ic
  }
  // latch in data
  load_high;
  load_low ;
}

void buffer(uint8_t x, uint8_t y, uint8_t value)
{
  // uint8_t's can't be negative, so don't test for negative x and y.
  if (x >= _maximumX || y >= 8) return;

  uint8_t offset = x; // record x
  x %= 8;             // make x relative to a single matrix
  offset -= x;        // calculate buffer offset

  // wrap shift relative x for nexus module layout
  if (x == 0)
  {
    x = 8;
  }
  --x;
  //y = y + 1;
  // record value in buffer
  if(value)
  {
    _buffer[y + offset] |= 0x01 << x;
  }
  else
  {
    _buffer[y + offset] &= ~(0x01 << x);
  }
}

// syncs row of display with buffer
void sync_row(uint8_t row)
{
  uint8_t i;
    
  // uint8_t's can't be negative, so don't test for negative row
  if (row >= 8) return;
  load_low ;
  for(i = 0; i < screenCount; ++i)
  {
    set_byte(row + 1);                // specify register
    //set_byte(row);
    set_byte(_buffer[row + (8 * i)]); // send data
  }
  // latch in data
  load_high;
  // end
  load_low ;
}

void set_brightness(uint8_t value)
{
  set_register(REG_INTENSITY, value & 0x0F);
}

// sets how many digits are displayed
void set_scan_limit(uint8_t value)
{
  set_register(REG_SCANLIMIT, value & 0x07);
}

void clear_screen(void)
{
  // clear buffer
  uint8_t i;
  for(i = 0; i < 8; ++i)
  {
    uint8_t j;
    for(j = 0; j < screenCount; ++j)
    {
      _buffer[i + (8 * j)] = 0x00;
    }
  }

  // clear registers
  for(i = 0; i < 8; ++i)
  {
    sync_row(i);
  }
}

void write(uint8_t x, uint8_t y, uint8_t value)
{
  buffer(x, y, value);
  // update affected row
  sync_row(y);
}

void led_matrix_init(void)
{
  // B0=Clock B1=Load B2=Din
  // Enable ports B0,B1,B2
  DDRB |= (1 << 0) | (1 << 1) | (1 << 2);

  // Start Pins low
  clock_low;
  din_low;
  load_low ;

  // initialize registers
  clear_screen();                      // clear display
  set_scan_limit(0x07);                // use all rows/digits 1:0x00 - 8:0x07
  set_brightness(0x02);                // maximum brightness 0x00 - 0x0F (290ma for 104led max power)
  set_register(REG_SHUTDOWN, 0x01);    // normal operation Disabled:0x00 
  set_register(REG_DECODEMODE, 0x00);  // no decode 0x00 0x00-0xFF
  set_register(REG_DISPLAYTEST, 0x00); // not in test mode
}
