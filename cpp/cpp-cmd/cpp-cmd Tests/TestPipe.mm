//
//  TestPipe.m
//  cpp-cmd
//
//  Created by Kutty Banerjee on 9/5/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include "Pipe.hpp"

#pragma mark C++ - Module Classes
class One {
public:
    void execute(int * input, uint32_t context_id) {
        cout << "module_one : input " << *input << " context_id " << context_id << endl;
        *input = 20;
    }
    
    void execute(uint64_t * lock_mask, uint32_t context_id) {
        *lock_mask |= 1;
        cout << "module_one : preparing lock mask " << *lock_mask << endl;
    }
};

class Two {
public:
    void execute(int * input, uint32_t context_id) {
        cout << "module_two : input " << *input << " context_id " << context_id << endl;
        *input = 80;
    }
    
    void execute(uint64_t * lock_mask, uint32_t context_id) {
        *lock_mask |= 4;
        cout << "module_two : preparing lock mask " << *lock_mask << endl;
    }
};

#pragma mark Objective-C
@interface TestPipe : XCTestCase

@end

@implementation TestPipe

- (void)setUp
{
    [super setUp];
    cout << "=============" << endl;
}

- (void)tearDown
{
    cout << "=============" << endl;
    [super tearDown];
}

- (void)testExample
{
    int value = 5;
    // Heres how you setup a new Hardware Pipeline
    Pipe<int, 4, Two, Two, One> x;
    x.setup_locks();
    x.execute(value, 8);
}

@end
