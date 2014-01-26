//
//  BaseOne.h
//  cpp-code
//
//  Created by Kutty Banerjee on 1/21/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#ifndef __cpp_code__BaseOne__
#define __cpp_code__BaseOne__

#include <iostream>
#include "BaseOne.h"

using std::cout;
using std::endl;


template <typename T>
void BaseOne<T>::start(T *input) {
    cout << "Base class speaking" << endl;
    return static_cast<T*>(this)->start(input);
}


#endif /* defined(__cpp_code__BaseOne__) */
