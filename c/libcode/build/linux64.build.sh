#! /bin/sh

make -f Makefile.linux WORDSIZE=-m64 $* --jobs=10
