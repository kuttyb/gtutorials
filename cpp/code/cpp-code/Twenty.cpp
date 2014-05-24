//
//  Twenty.cpp
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
void IA<Twenty>::print() {
    cout << " Twenty speaking " << endl;
 }

template <>
int IA<Twenty>::add(int a, int b) {
    return 0;
}

template <>
int IA<Twenty>::multiply(int a, int b) {
    return 0;
}

