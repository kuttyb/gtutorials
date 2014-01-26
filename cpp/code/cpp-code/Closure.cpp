//
//  Closure.cpp
//  cpp-code
//
//  Created by Kutty Banerjee on 1/25/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//
#include <functional>
#include "Closure.h"

using std::function;

static int func(int(*aptr)(int, int), int one, int two) {
    return aptr(one, two);
}

int test_nonstate_lambda(void) {
    auto a = [] (int a, int b) {
        return a + b;
    };
    
    func(a, 3, 4);
    
    return 0;
}

static int state_func(std::function<int (int, int)> aptr, int one, int two) {
    return aptr(one, two);
}

int test_state_lambda(void) {
    int x = 3;
    auto a = [&x] (int a, int b) {
        return a + b + x;
    };
    
    ++x;
    state_func(a, 3, 4);
    ++x;
    
    return 0;
}
