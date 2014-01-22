//
//  A.cpp
//  cpp-code
//
//  Created by Kutty Banerjee on 1/21/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//
#include <inttypes.h>
#include "A.h"

#define IMPL(T) static_cast<T*>(this)

template<typename T>
uint64_t A<T>::multiply(uint32_t input, uint32_t m)
{
    return IMPL(T)->multiply(input, m);
}

template<typename T>
uint64_t A<T>::passthru(uint64_t val)
{
    return IMPL(T)->passthru(val);
}

