//
//  DOne.cpp
//  cpp-code
//
//  Created by Kutty Banerjee on 1/21/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#include "BaseOne.hpp"

#include "DOne.h"

// Include BaseOne and instantiate it with type Derived
template class BaseOne<DOne>;

void DOne::start(DOne *input) {
    if (input) ref = input;
}
