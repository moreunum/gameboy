#ifndef CPU_H
#define CPU_H

enum {STACK_MAX = 65530};

typedef struct {
  // CPU 8-bit General Purpose Registers
  int a;
  int b;
  int c;
  int d;
  int e;
  int h;
  int l;

  // Flag register
  // 0x80 = zero bit - set if result was zero
  // 0x40 = subtraction operation bit
  // 0x20 = half-carry bit - lower half of result byte overflowed past 15
  // 0x10 = carr bit - set if result was > 255
  unsigned char f;

  // Program counter - stores address of next instruction
  unsigned int pc;
  
  // Stack pointer
  unsigned int sp;

  // Used for time-keeping
  unsigned char m;
  unsigned char t;
} Z80_t;

int ADDa_b(Z80_t* Z80);
int PUSHb_c(Z80_t* Z80);

#endif
