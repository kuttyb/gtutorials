//
//  BaseUnit.h
//  cpp-code
//
//  Created by Kutty Banerjee on 2/8/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#ifndef __cpp_code__BaseUnit__
#define __cpp_code__BaseUnit__

#include <stdio.h>
#include <inttypes.h>

template <uint32_t base_addr, uint32_t base_length, uint32_t control_addr>
class Base {
public:
    void print() {
        printf("generic version: base_addr 0x%x base_length 0x%x control_addr 0x%x\n",
               base_addr, base_length, control_addr);
    }
};

// Partial specialization
template <uint32_t base_length, uint32_t control_addr>
class Base <1,  base_length, control_addr> {
public:
    void print() {
        printf("1: base_addr 1 base_length 0x%x control_addr 0x%x\n",
               base_length, control_addr);
    }
};

// Full specialization
template <>
class Base<1, 2, 3> {
public:
    void print() {
        printf("Group-A speaking\n");
    }
};

template <>
class Base<2, 1, 3> {
public:
    void print() {
        printf("Group-B speaking\n");
    }
};

#endif /* defined(__cpp_code__BaseUnit__) */
