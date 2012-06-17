#! /bin/sh

WARNINGFLAGS="-Wall -Wextra -Winit-self -Wuninitialized -Wswitch-enum -Wswitch-default -fstrict-aliasing   
    -fstrict-overflow -Wstrict-overflow=5 -Wunused-parameter -Wpointer-arith -Wbad-function-cast 
    -Wcast-qual -Wcast-align  -Wlogical-op -Waggregate-return -Wattributes -Winline"

CFLAGS="-O3 -flto -fwhole-program  -fipa-pta -fipa-struct-reorg -fipa-matrix-reorg -fwrapv ${WARNINGFLAGS} -DCOMPILER_GCC"

gcc ${CFLAGS} -c inline.c -o bin/inline.o
gcc ${CFLAGS} -c tree.c   -o bin/tree.o
gcc ${CFLAGS}  main.c bin/inline.o bin/tree.o -o bin/main

