#!/bin/bash

# Script to assemble, compile and link our kernel
# Don't forget to add current files into this one

echo "Building kernel:"

# Assembler is done here
echo "* assembling start.asm"
nasm -f aout -o start.o start.asm

# Here go C files with a lot of flags
# GCC must produce 32-bit, not 64 (even on x86_64 machines) ergo -m32
#
# ADD THIS FLAGS FOR SMALLER KERNEL IMAGE SIZE VERSION
# (they suck for debugging though)
# -fomit-frame-pointer -finline-functions

echo "* compiling C files"
gcc -m32 -Wall -O2 -nostdinc -fno-builtin -I./include -c -o main.o main.c
gcc -m32 -Wall -O2 -nostdinc -fno-builtin -I./include -c -o scrn.o scrn.c
gcc -m32 -Wall -O2 -nostdinc -fno-builtin -I./include -c -o gdt.o gdt.c
gcc -m32 -Wall -O2 -nostdinc -fno-builtin -I./include -c -o idt.o idt.c
gcc -m32 -Wall -O2 -nostdinc -fno-builtin -I./include -c -o isrs.o isrs.c
gcc -m32 -Wall -O2 -nostdinc -fno-builtin -I./include -c -o irq.o irq.c
gcc -m32 -Wall -O2 -nostdinc -fno-builtin -I./include -c -o timer.o timer.c
gcc -m32 -Wall -O2 -nostdinc -fno-builtin -I./include -c -o kb.o kb.c

# Don't forget to add rest of .o files after start.o below

echo "* linking binaries"
ld -m i386linux -T link.ld -o kernel.bin start.o \
					  main.o \
					  scrn.o \
					   gdt.o \
					   idt.o \
					  isrs.o \
					   irq.o \
					 timer.o \
					    kb.o

echo "* all finished"

