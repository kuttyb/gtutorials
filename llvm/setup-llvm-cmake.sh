#! /bin/sh

rm -rf build
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release -DLLVM_TARGETS_TO_BUILD="X86;AArch64" ../llvm

# After compilation, goto build/bin : llc --version to get a list of supported Architectures


