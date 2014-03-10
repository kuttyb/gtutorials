//
//  Range.cpp
//  cpp-code
//
//  Created by Kutty Banerjee on 3/9/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//
#include <iostream>
#include "DART.h"

void Range::print() {
    printf("print: base_addr 0x%llx bytes 0x%llx\n", base_address, bytes);
}

bool Range::is_in_range(uint64_t input, uint64_t  base, uint64_t bytes) const {
    if ((input >= base) && (input <= base + bytes)) {
        return true;
    } else {
        return false;
    }
}

bool Range::operator<(const Range &other) const {
    if (0) {
        printf("comparator: self  addr 0x%llx bytes 0x%llx\n", base_address, bytes);
        printf("comparator: other addr 0x%llx bytes 0x%llx\n", other.base_address, other.bytes);
    }
    
    // -------------------------------------------------------------
    // Check for overlap and return false (to make them look equal)
    //   i.e., Is the other's head in the range or its tail is
    //         is in the range
    // -------------------------------------------------------------
    if (is_in_range(other.base_address, base_address, bytes) ||
        is_in_range(other.base_address + bytes, base_address, bytes)) {
        if (0) printf("equal_case: self: 0x%llx 0x%llx, other: 0x%llx 0x%llx\n",
                      base_address, bytes, other.base_address, other.bytes);
        return false;
    }
    
    if ((base_address + bytes) > other.base_address) {
        return false;
    } else {
        return true;
    }
}
