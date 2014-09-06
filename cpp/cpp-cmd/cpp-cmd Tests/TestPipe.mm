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
    void execute(PipeEntry<int, int> * entry) {
        cout << "One: " << entry->pipe_intermediate_data << " " <<
        entry->pipe_input << " " << entry->context_id << endl;
        entry->pipe_intermediate_data *= 10;
    }
    
    void execute(PipeEntry<uint64_t, uint8_t> * entry) {
        entry->pipe_intermediate_data |= 1;
        cout << "module_one : preparing lock mask " << entry->pipe_intermediate_data << endl;
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
    // Heres how you setup a new Hardware Pipeline
    Pipe<int, int, 4, One, One> x;
    x.setup_locks();
    
    PipeEntry<int, int> y (2, 3, 10);
    x.execute(&y);
}

@end
