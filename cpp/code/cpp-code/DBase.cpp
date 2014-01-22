//
//  DBase.cpp
//  cpp-code
//
//  Created by Kutty Banerjee on 1/21/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//
#include <iostream>
#include "DBase.h"

using std::cout;
using std::endl;

template <typename T>
void DBasex<T>::start(void) {
     return static_cast<T*>(this)->start();
}

void DDerived::start(void) {
    cout << "Derived class speaking" << endl;
}

template class DBasex<DDerived>;