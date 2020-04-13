all: Program

Program: funcionesCC main
    gcc -o out main.o funcionesCC.o

Funcs: funcionesCC.c funcionesCC.h
    gcc -c funcionesCC.c

main: main.c funcionesCC.h
    gcc -c main.c