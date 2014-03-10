//
//  DART.h
//  cpp-code
//
//  Created by Kutty Banerjee on 3/9/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#ifndef __cpp_code__DART__
#define __cpp_code__DART__

#include <set>

class Range {
public:
    Range(uint64_t base, uint64_t len) : base_address(base), bytes(len){}
    bool operator<(const Range &other) const;
    void print();
private:
    bool is_in_range(uint64_t input, uint64_t base, uint64_t bytes) const;
    uint64_t base_address;
    uint64_t bytes;
};

class DART {
private:
    std::set<Range> table;
    bool is_overlapping;
    
public:
    DART() : is_overlapping(false) {}
    void clear();
    bool overlapping() const;
    void add_write_range(uint64_t base, uint64_t lenth);
    void add_read_range(uint64_t base, uint64_t length);
};

#endif /* defined(__cpp_code__DART__) */
