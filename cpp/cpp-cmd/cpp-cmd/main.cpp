//
//  main.cpp
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

int main(int argc, const char * argv[])
{
    cout << "starting here " << endl;
#if 0
    Base<Derived> b;
    b.start();
#endif
    return 0;
}

