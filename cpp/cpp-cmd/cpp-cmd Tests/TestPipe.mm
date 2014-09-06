//
//  TestPipe.m
//  cpp-cmd
//
//  Created by Kutty Banerjee on 9/5/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include "Pipe.h"
#include "typevector.h"

using std::cout;
using std::endl;

#pragma mark C++
template <typename T, size_t fifo_depth, typename... M>
void Pipe<T, fifo_depth, M...>::execute(T & input, uint32_t context_id) {
    cout << "Pipe execute" << endl;
    foreach_type<std::tuple_size<std::tuple<M...> >::value - 1, T, M...>::executemodule(&input, context_id);
}

template <typename T, size_t fifo_depth, typename... M>
void Pipe<T, fifo_depth, M...>::enqueue(T input, uint32_t context_id) {
    
}

template <typename T, size_t fifo_depth, typename... M>
void Pipe<T, fifo_depth, M...>::run(void) {
    
}

template <typename T, size_t fifo_depth, typename... M>
void Pipe<T, fifo_depth, M...>::init(void) {
    cout << "Initializing locks" << endl;
    foreach_type<std::tuple_size<std::tuple<M...> >::value - 1, uint64_t, M...>::executemodule(&lock_mask, 0);
}

#pragma mark C++ - Module Classes
class One {
public:
    void execute(int * input, uint32_t context_id) {
        cout << " module : input " << *input << " context_id " << context_id << endl;
        *input = 20;
    }
    
    void execute(uint64_t * lock_mask, uint32_t context_id) {
        *lock_mask |= 1;
        cout << " module : preparing lock mask " << *lock_mask << endl;
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
    Pipe<int, 4, One, One> x;
    x.init();
    x.execute(value, 8);
}

@end
