#ifndef CPU_H
#define CPU_H

typedef struct {
  // CPU 8-bit Registers
  unsigned char a;
  unsigned char b;
  unsigned char c;
  unsigned char d;
  unsigned char e;
  unsigned char h;
  unsigned char l;
  unsigned char f;

  // Program counter - stores address of next instruction
  unsigned char pc;

  // Stack pointer
  unsigned char sp;

  // Don't know what these do yet
  unsigned char m;
  unsigned char t;
} Z80;

void testcpu();

#endif

