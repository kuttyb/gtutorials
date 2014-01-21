//
//  DBase.cpp
//  cpp-code
//
//  Created by Kutty Banerjee on 1/21/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#include "DBase.h"

template <typename T>
void DBasex<T>::start(void) {
    return static_cast<T*>(this)->start();
}
