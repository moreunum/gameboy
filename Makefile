flags=-g -Wall -std=c99

all: main.o parse.o
	gcc $(flags) main.o parse.o -o gameboy

main: main.c
	gcc $(flags) -c main.c

parse: parse.c
	gcc $(flags) -c parse.c
