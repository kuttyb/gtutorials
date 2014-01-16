//
//  Function.cpp
//  cpp-code
//
//  Created by Kutty Banerjee on 1/15/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//
#include <iostream>
#include <assert.h>
#include "Function.h"

using std::cout;
using std::endl;

template <class T>
T func(T input) {
    cout<< "generic version " << input << endl;
    return input;
}

template <>
int func(int input) {
    cout << "integer version " << endl;
    return input + 3;
}


int _dummymain(void) {
    // for compile time tricks only, not meant to be invoked at runtime!!
    func<float>(3.0f);
    func<int>(4);
    assert(0);
    return 0;
}

