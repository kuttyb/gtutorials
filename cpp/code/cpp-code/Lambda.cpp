//
//  Closure.cpp
//  cpp-code
//
//  Created by Kutty Banerjee on 1/25/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//
#include <functional>
#include <assert.h>
#include "Lambda.h"

using std::function;

// Can't use function pointers for lmabda that capture state
// So the lambda HAS TO HAVE [] i.e., EMPTY BRACKET for it
// to use function pointers
static int func(int(*aptr)(int, int), int one, int two) {
    return aptr(one, two);
}

// For the sake of clarity, please always stick to std::function<return_type(input_args)>
// instead of Function Pointers unless we find out otherwise.
static int state_func(std::function<int (int, int)> aptr, int one, int two) {
    return aptr(one, two);
}

int test_nonstate_lambda(void) {
    auto a = [] (int a, int b) {
        return a + b;
    };
    
    func(a, 3, 4);
    
    return 0;
}


int test_state_lambda(void) {
    int x = 3;
    std::function<int (int, int)> a = [&x] (int a, int b) -> int {
        return a + b + x;
    };
    
    auto bbb = [&x] (int m, int n) ->int {
        return m + 2 + n + x;
    };
    
    ++x;
    state_func(a, 3, 4);
    state_func(bbb, 3, 4);
    ++x;
    state_func(a, 3, 4);
    
    std::function<int (int, int)>  local_functor = [&] (int j, int k) -> int {
        return j * k + x;
    };
    ++x;
    state_func(local_functor, 9, 1);
    ++x;
    
    return 0;
}
