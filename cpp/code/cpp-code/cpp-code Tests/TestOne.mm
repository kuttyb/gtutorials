//
//  TestOne.m
//  cpp-code
//
//  Created by Kutty Banerjee on 1/7/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include <iostream>
#include "one.h"

using std::cout;
using std::endl;

@interface TestOne : XCTestCase

@end

@implementation TestOne {
    One<uint64_t> *subject;
}

- (void)setUp
{
    [super setUp];
    subject = new One<uint64_t>(2, 3, 8, 1);
}

- (void)tearDown
{
    delete subject;
    [super tearDown];
}

- (void)testExample
{
    // by value
    subject->value();
    
    One<uint64_t>* list[] =
    {
        new One<uint64_t>(2, 3, 8, 1), new One<uint64_t>(1, 5, 2, 2), new One<uint64_t>(1, 1, 1, 3), new One<uint64_t>(1, 2, 3, 4)
    };
    
    for (uint32_t i = 0; i < sizeof(list) / sizeof(One<uint64_t>); i++)
    {
        cout << list[i]->latest_value() << endl;
    }
    
    for (uint32_t i = 0; i < sizeof(list) / sizeof(list[0]); ++i) {
        delete list[i];
    }
}

@end
