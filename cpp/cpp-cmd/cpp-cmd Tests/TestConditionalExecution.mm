//
//  TestConditionalExecution.mm
//  cpp-cmd
//
//  Created by kuttyb on 6/15/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include <iostream>
#include <functional>

using std::cout;
using std::endl;

#pragma mark C++
template <bool n, typename INPUT>
struct _if {
    static void _do(std::function<void (INPUT input)> func, INPUT args) {
        cout << "executing: input " << args << endl;
        return func(args);
    }
};

template <typename INPUT>
struct _if<false, INPUT> {
    // Do nothing
    static void _do(std::function<void (INPUT input)> func, INPUT args) {
    }
};

#pragma mark Objective-C
@interface TestConditionalExecution : XCTestCase

@end

@implementation TestConditionalExecution

- (void)setUp
{
    [super setUp];
}

- (void)tearDown
{
    [super tearDown];
}

- (void)testExample
{
    _if<true, int>::_do([] (int input)  {
    }, 10);
    
    
    _if<false, int>::_do([] (int input) {
    }, 10);
}


@end
