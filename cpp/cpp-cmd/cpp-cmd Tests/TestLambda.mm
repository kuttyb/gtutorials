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
#include <chrono>

using namespace std;

int test(std::function<int (int, int)> ptr, int one, int two) {
    return ptr(one, two);
}

void microbenchmark(std::function<void (void)> ptr) {
    auto start = chrono::steady_clock::now();
    
    auto end   = chrono::steady_clock::now();
    
    auto diff = chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    cout << "Microbenchmark took " << diff.count() << " nanoseconds" << endl;
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

- (void) testBenchmark
{
    int x = 10;
    microbenchmark([&x](void)
    {
        cout << "spitting out just a few lines of code" << x <<  endl;
    });
}

@end
