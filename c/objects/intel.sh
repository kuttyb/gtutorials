#! /bin/sh

CC="/home/daji/intel/bin/icc"

CFLAGS="-fast -fno-alias -inline-level=2 -no-inline-max-size -inline-calloc"

${CC} ${CFLAGS} -c inline.c -o bin/inline.o
${CC} ${CFLAGS} -c tree.c   -o bin/tree.o
${CC} ${CFLAGS}  main.c bin/inline.o bin/tree.o -o bin/main

