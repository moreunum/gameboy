#include <stdio.h>
#include "cpu.h"
#include "util.h"
#include "mmu.h"

void cpuStart(){
  // Instantiate the CPU struct
  //Z80_t Z80;

  // TODO: start reading instructions here
}

//////////////////////////////////////////////////////////
//
// Opcode instructions
// Each opcode in the table is a separate function
//
//////////////////////////////////////////////////////////

// 0x80 = ADD (A, B)
int ADDa_b(Z80_t* Z80) {
//  debug("Z80->a: %d\n", Z80->a);
//  debug("Z80->b: %d\n", Z80->b);
  // Add registers A and B, store result in A
  Z80->a += Z80->b;

  // Clear the CPU flags
  Z80->f = 0x00;

  // Set the zero bit
  if (Z80->a == 0)
    Z80->f |= 0x80;

  // Set the carry bit
  if (Z80->a > 0xFF)
    Z80->f |= 0x10;

  // Mask result to 8 bits
  Z80->a &= 0xFF;

  return 0;
}

// 0xC5 = PUSH (B, C)
// Pushes registers B and C onto the stack
// Stack seems to start at STACK_MAX, and grow downward
// Stack pointer points to the last filled spot, not the next empty spot
int PUSHb_c(Z80_t* Z80) {
  check_error(Z80->sp > 1, "PUSHb_c stack overflow\n");
  Z80->sp--;
  writeByte(Z80->sp, Z80->b);
  Z80->sp--;
  writeByte(Z80->sp, Z80->c);

  return 0;
error:
  return ERROR;
}
