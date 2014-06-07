//
//  TestRecursion.m
//  cpp-cmd
//
//  Created by kuttyb on 6/7/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include <iostream>
#include "TypeCollection.h"

using std::cout;
using std::endl;

class X { public: void print() { cout << "X speaking" << endl; } };
class Y { public: void print() { cout << "Y speaking" << endl; } };


@interface TestRecursion : XCTestCase

@end

@implementation TestRecursion

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
    X a; Y b; Y c;
    {
        TypeContainer<X, Y, Y, X> data(a, b, c, a);
        
        TypeProcessor<data.size(), X, Y, Y, X>::method(data);
    }
}

@end
