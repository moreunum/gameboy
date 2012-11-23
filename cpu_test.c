#include <stdio.h>
#include "cpu.h"
#include "util.h"

int test_opcodes(){
  Z80_t Z80 = {0};
  Z80.a = 1;
  Z80.b = 2;
  ADDa_b(&Z80);
  test(Z80.a == 3, "Z80.a == %d", Z80.a);
  test(Z80.f == 0x00, "Z80.a == %d", Z80.a);
error:
  return 0;
}
