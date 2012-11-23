#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "parse.h"
#include "cpu.h"
#include "cpu_test.h"

int main(int argc, char **argv)
{
	printf("%s ", *argv);
	parseROM(argv[0]); 
  //test_opcodes();
}	
