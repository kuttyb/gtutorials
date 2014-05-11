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

@implementation TestSetStruct {
    std::set<Event *> subject;
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

    for (std::set<Event*>::iterator x = subject.begin(); x != subject.end(); x++ ){
        Event *ptr = *x;
        printf("0x%llx \n",
               ptr->type);
    }
}

@end
