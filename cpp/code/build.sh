#! /bin/sh

export CXXFLAGS="--std=c++98 --stdlib=libc++ -Wall -Weverything -O4"
export LDFLAGS="--std=c++98 --stdlib=libc++ -lc++ -O4"
export CXX=clang++
export BIN="./bin"

${CXX} ${CXXFLAGS} -c *.cpp

${CXX} ${LDFLAGS} main.o -o ${BIN}/test

${CXX} ${LDFLAGS} t.o -o ${BIN}/g

${CXX} ${LDFLAGS} one.o -o ${BIN}/one

${CXX} ${LDFLAGS} duck.o -o ${BIN}/duck
