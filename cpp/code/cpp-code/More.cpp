//
//  More.cpp
//  cpp-code
//
//  Created by Kutty Banerjee on 1/13/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//
#include <iostream>
#include "More.h"

using std::cout;
using std::endl;

template <class T>
int More<T>::classVar = 3;

template<class T>
const int More<T>::classConstant = 0x10;

template <class T>
void More<T>::print(T data) {
    cout << "the data is " << data << endl;

}

template <class T>
More<T>::More(void) : localvar(2), localconst(3) {
}

template <class T>
void More<T>::printClass(void) {
    cout << "printing class data" << endl;
}

// Apparently it has to be instantiated in the same object file
template class More<uint32_t>;
