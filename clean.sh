#!/bin/bash

# Just clean my env

echo "Cleaning: "
rm kernel.bin && echo "* kernel.bin"
rm start.o && echo "* start.o"
rm main.o && echo "* main.o"
rm scrn.o && echo "* scrn.o"
rm gdt.o && echo "* gdt.o"
rm idt.o && echo "* idt.o"
rm isrs.o && echo "* isrs.o"
rm irq.o && echo "* irq.o"
rm timer.o && echo "* timer.o"
rm kb.o && echo "* kb.o"
