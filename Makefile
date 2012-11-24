flags=-g -Wall -std=c99 
objects=main.o parse.o cpu.o cpu_test.o mmu.o
all: $(objects)
	gcc $(flags) $(objects) -o gameboy

main.o: main.c
	gcc $(flags) -c main.c

parse.o: parse.c
	gcc $(flags) -c parse.c

cpu.o: cpu.c
	gcc $(flags) -c cpu.c

cpu_test.o: cpu_test.c
	gcc $(flags) -c cpu_test.c

mmu.o: mmu.c
	gcc $(flags) -c mmu.c

clean:
	rm gameboy $(objects)
