//
//  Base.cpp
//  cpp-cmd
//
//  Created by Kutty Banerjee on 1/21/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//
#include <iostream>
#include "Base.h"

using std::cout;
using std::endl;

template <typename T>
void Base<T>::start(void) {
    cout << "Base class speaking" << endl;
    static_cast<T*>(this)->start();
}

class Derived;