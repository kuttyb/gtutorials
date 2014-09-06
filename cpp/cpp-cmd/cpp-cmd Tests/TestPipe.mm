//
//  TestPipe.m
//  cpp-cmd
//
//  Created by Kutty Banerjee on 9/5/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include "Pipe.h"

using std::cout;
using std::endl;

#pragma mark C++
template <typename T, size_t fifo_depth>
void Pipe<T, fifo_depth>::execute(T & input, uint32_t context_id) {
    cout << "Pipe execute" << endl;
}

template <typename T, size_t fifo_depth>
void Pipe<T, fifo_depth>::enqueue(T input, uint32_t context_id) {
    
}

template <typename T, size_t fifo_depth>
void Pipe<T, fifo_depth>::run(void) {
    
}

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
    
}

@end
