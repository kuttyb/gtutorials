//
//  TestT.m
//  cpp-code
//
//  Created by Kutty Banerjee on 1/7/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include <iostream>
#include "t.h"

using std::cout;
using std::endl;

@interface TestT : XCTestCase

@end

@implementation TestT {
    X<int> *subject;
}

- (void)setUp
{
    [super setUp];
    subject = new X<int>();
}

- (void)tearDown
{
    delete subject;
    [super tearDown];
}

- (void)testExample
{
    subject->add(3, 4);
    subject->multiply(4, 8);
}

@end
