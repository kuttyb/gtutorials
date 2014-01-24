//
//  BridgeTemplates.cpp
//  cpp-cmd
//
//  Created by Kutty Banerjee on 1/23/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#include "BridgeTemplates.h"
#include "TypeAssert.h"
#include <iostream>

using std::cout;
using std::endl;

#include "NumberTemplates.hpp"

template <typename T, typename U>
class A{
ASSERT_TYPE_START
    ASSERT_TYPE_INHERITS(T, X)
    ASSERT_TYPE_INHERITS(U, Y)
ASSERT_TYPE_END
    
private:
    float _var;
    
public:
    void set(float input) {
        _var = input;
        cout << "yes its working" << endl;
    }
};
