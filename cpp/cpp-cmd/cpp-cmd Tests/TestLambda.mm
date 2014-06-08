//
//  TestLambda.mm
//  cpp-cmd
//
//  Created by kuttyb on 6/8/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include <functional>
#include <iostream>

using std::cout;
using std::endl;

int test(std::function<int (int, int)> ptr, int one, int two) {
    return ptr(one, two);
}

@interface TestLambda : XCTestCase

@end

@implementation TestLambda

- (void)setUp
{
    [super setUp];
    cout << "================" << endl;
}

- (void)tearDown
{
    cout << "================" << endl;
    [super tearDown];
}

- (void)testExample
{
    int localvar = 10;
    
    auto x = [&localvar] (int a, int b) -> int {
        return a * b + localvar;
    };
    
    localvar++;
    XCTAssert(test(x, 3, 5) == 26);
    localvar += 10;
}

@end
