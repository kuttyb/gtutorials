#! /bin/sh

CFLAGS="-xO5 -xipo=2 -xipo_archive=writeback -xprefetch_level=3 -xarch=sse2"

suncc ${CFLAGS} -c inline.c -o bin/inline.o
suncc ${CFLAGS} -c tree.c   -o bin/tree.o
suncc ${CFLAGS}  main.c bin/inline.o bin/tree.o -o bin/main

