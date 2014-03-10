//
//  DART.h
//  cpp-code
//
//  Created by Kutty Banerjee on 3/9/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#ifndef __cpp_code__DART__
#define __cpp_code__DART__

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

#endif /* defined(__cpp_code__DART__) */
