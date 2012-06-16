#! /bin/sh

rm *.o 
rm out


gcc -O3 -flto -fwhole-program  -c inline.c 
gcc -O3 -flto -fwhole-program  -c inline2.c 
gcc -O3 -flto -fwhole-program  inline.o inline2.o -o out
