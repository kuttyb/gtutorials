//
//  TestSetStruct.m
//  cpp-code
//
//  Created by Kutty Banerjee on 5/11/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include <set>
#include <iostream>
#include <array>

@interface TestSetStruct : XCTestCase

@end

typedef struct {
    uint64_t  type;
    uint64_t  timestamp;
    uint64_t  arg0;
    uint64_t  arg1;
    uint64_t  arg2;
} Event;

// This is how you provide your own custom comparator.
// Keep in mind the comparator should take in the same type
// as you would in the Set. Meaning respect if its a value type
// in the Set or a Pointer type.
struct timestamp_compare {
    bool operator()(const Event * x, const Event * y) const {
        return x->timestamp <= y->timestamp;
    }
};

struct type_compare {
    bool operator()(const Event * x, const Event * y) const {
        // keep in mind the '=' in '<=' allows us to make
        // the set look like a bag (aka allowing duplicates)
        // yet ordered.
        return x->type <=  y->type;
    }
};

@implementation TestSetStruct {
    std::set<Event *, timestamp_compare> subject;
}

- (void)setUp
{
    [super setUp];
    subject.clear();
}

- (void)tearDown
{
    [super tearDown];
}

- (void)testBasic
{
    std::array<Event, 5> list{
        {
            {2, 10, 3, 4, 5},
            {2, 5, 3, 4, 5},
            {4, 3, 3, 4, 5},
            {1, 30, 3, 4, 5},
            {1, 1, 3, 4, 5},
        }
    };

    for (auto & temp : list) {
        subject.insert(&temp);
    }

    for (Event * temp : subject) {
        printf(" %lld  %lld  %lld  %lld  %lld\n",
               temp->type, temp->timestamp, temp->arg0, temp->arg1, temp->arg2);
    }
}

@end
