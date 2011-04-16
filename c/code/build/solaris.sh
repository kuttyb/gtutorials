#! /bin/sh

make -f Makefile.solaris WORDSIZE=-m64 $* --jobs=10

