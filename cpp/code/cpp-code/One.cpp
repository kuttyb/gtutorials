//
//  One.cpp
//  cpp-code
//
//  Created by Kutty Banerjee on 5/24/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#include <iostream>
#include "IA.h"

using std::cout;
using std::endl;

template <>
void IA<One>::print() {
    cout << " One speaking " << endl;
}

template <>
int IA<One>::add(int a, int b) {
    return a + b;
}

template <>
int IA<One>::multiply(int a, int b) {
    return a * b;
}

