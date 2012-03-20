# README.md

This is a simple kernel written in C. It was created thanks to [Bran's Kernel Development Tutorial](http://www.osdever.net/bkerndev/Docs/title.htm) but it's not exactly the same code. Few changes were applied. You have been warned.

## Changes

Compiler GCC, since like 2007 or so, does **NOT** add dash symbol ("_") in front of compiled functions' names. Also few (AFAIR two) compiler options used by Bran were outdated and many, like inline code compilation, are great for production kernel but suck when it comes to debugging.

I also added a nice `make.sh` script which will compile, link and create the file called kernel.bin which later on you can run in Qemu via `qemu -kernel kernel.bin` command. Script called `clean.sh` will also clean your environment (remove .o files and kernel .bin) before next compilation. For Windows users, sorry, you must write your own stuff.

## Usage

It worked with GCC compiler 4.3.3 and proper for this version LD linker and NASM a year ago or so. Now, in Feb 2012, it also works with GCC 4.5.2, LD 2.21 and NASM 2.09.04. Please not spam this repository with any bugs or questions. If you have any problems you can solve them at [OSDever forums](http://forum.osdev.org/), this repo is not maintained!

If you want to modify this code more (it's just a starter) you can follow the great tutorial called [JamesM's kernel development tutorials](http://www.jamesmolloy.co.uk/tutorial_html/) - there you will learn about virtual filesystens, initrd, multitasking and user mode.

Have fun.

