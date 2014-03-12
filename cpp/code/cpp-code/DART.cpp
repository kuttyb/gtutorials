//
//  Range.cpp
//  cpp-code
//
//  Created by Kutty Banerjee on 3/9/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//
#include <iostream>
#include "DART.h"

#pragma mark Range class elements
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

    if ((other.base_address > base_address) &&
        (other.base_address >= base_address + bytes))
    {
        return true;
    }
    else
    {
        return false;
    }
}

#pragma mark DART class elements
void DART::clear() {
    // Invalidate all addresses
    table.clear();
    is_overlapping = false;
}

void DART::add_write_range(uint64_t base, uint64_t length) {
    if (is_overlapping) return;
    
    Range range(base, length);
    // Insertion failures imply there is an overlap (WAW)
    if (table.insert(range).second == false) {
        is_overlapping = true;
    }
}

void DART::add_read_range(uint64_t base, uint64_t length) {
    if (is_overlapping) return;
 
    Range range(base, length);
    if (table.find(range) != table.end()) {
        // Meaning the Range exists so this is an overlap (RAW)
        is_overlapping = true;
    }
}

bool DART::overlapping() const {
    return is_overlapping;
}

void DART::print() const {
    printf("DART: is_overlapping : %d\n", is_overlapping);
    
    printf("DART: ================\n");
    printf("DART: Dirty Addresses (%ld elements)\n", table.size());
    for (std::set<Range>::iterator itr = table.begin(); itr != table.end(); itr++) {
        static_cast<Range>(*itr).print();
    }
    printf("DART: ================\n");
}
