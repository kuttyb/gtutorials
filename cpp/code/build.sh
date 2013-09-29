#! /bin/sh

export CXXFLAGS="--std=c++98 --stdlib=libc++ -Wall -Weverything -O4"
export LDFLAGS="--std=c++98 --stdlib=libc++ -lc++ -O4"
export CXX=clang++
export BIN="./bin"

${CXX} ${CXXFLAGS} -c *.cpp

${CXX} ${LDFLAGS} *.o -o ${BIN}/test
