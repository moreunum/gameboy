#include <stdio.h>
#include <string.h>
#include "parse.h"
#include "cpu.h"
#include <stdlib.h>

int main(int argc, char **argv)
{
	printf("%s ", *argv);
	parseROM(argv[0]); 

}	

