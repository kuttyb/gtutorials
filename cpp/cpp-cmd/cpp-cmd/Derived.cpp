//
//  Derived.cpp
//  cpp-cmd
//
//  Created by Kutty Banerjee on 1/21/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//
#include <iostream>
#include "Base.h"
#include "Derived.h"

using std::cout;
using std::endl;

void Derived::start(void) {
    cout <<"derived class speaking" << endl;
}
