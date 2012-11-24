#include <stdio.h>
#include "cpu.h"
#include "util.h"
#include "mmu.h"

int test_ADDa_b();
int test_PUSHb_c();

// Test start
int test_opcodes(){
  check_error_silent(test_ADDa_b() != ERROR);
  check_error_silent(test_PUSHb_c() != ERROR);

  printf("== All opcode tests passed ==\n");

  return 0;
error:
  return ERROR;
}

int test_ADDa_b(){
  Z80_t Z80 = {0};
  Z80.a = 1;
  Z80.b = 2;
  ADDa_b(&Z80);
  test(Z80.a == 3, "Z80.a == %d", Z80.a);
  test(Z80.f == 0x00, "Z80.f == %d", Z80.f);

  Z80.a = 1;
  Z80.b = 255;
  ADDa_b(&Z80);
  test(Z80.a == 0, "Z80.a == %d", Z80.a);
  test(Z80.f == 0x10, "Z80.f == %d", Z80.f);

  Z80.a = 1;
  Z80.b = 254;
  ADDa_b(&Z80);
  test(Z80.a == 255, "Z80.a == %d", Z80.a);
  test(Z80.f == 0x00, "Z80.f == %d", Z80.f);

  return 0;
error:
  return ERROR;
}

int test_PUSHb_c(){
  Z80_t Z80 = {0};
  Z80.c = 1;
  Z80.b = 2;
  Z80.sp = STACK_MAX;
  PUSHb_c(&Z80);
  test(Z80.sp == STACK_MAX-2, "Z80.sp == %d", Z80.sp);

  Z80.sp = 1;
  int ret = PUSHb_c(&Z80);
  test(ret == ERROR, "Did not return stack overflow error\n");

  return 0;
error:
  return ERROR;
}
