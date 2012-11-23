#include <stdio.h>
#include "cpu.h"
#include "util.h"

int test_opcodes(){
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

error:
  return 0;
}
