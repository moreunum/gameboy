flags=-g -Wall -std=c99

all: main.o parse.o cpu.o
	gcc $(flags) main.o parse.o cpu.o -o gameboy

main.o: main.c
	gcc $(flags) -c main.c

parse.o: parse.c
	gcc $(flags) -c parse.c

cpu.o: cpu.c
	gcc $(flags) -c cpu.c
