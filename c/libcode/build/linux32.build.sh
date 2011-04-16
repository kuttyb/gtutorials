#! /bin/sh

make -f Makefile.linux WORDSIZE=-m32 $* --jobs=4

