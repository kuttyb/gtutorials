//
//  Two.cpp
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
void IA<Two>::print() {
    cout << " Two speaking " << endl;
}


template <>
int IA<Two>::add(int a, int b) {
    return a * 10 + b * 3;
}

template <>
int IA<Two>::multiply(int a, int b) {
    return a * 10 * b * 3;
}

