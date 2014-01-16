//
//  Function.cpp
//  cpp-code
//
//  Created by Kutty Banerjee on 1/15/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//
#include <iostream>
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

int _main(void) {
    func(3.0f);
    return func(4);
}
