//
//  TestClosure.m
//  cpp-code
//
//  Created by Kutty Banerjee on 1/26/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include "Lambda.h"

@interface TestClosure : XCTestCase

@end

@implementation TestClosure

- (void)setUp
{
    [super setUp];
}

- (void)tearDown
{
    [super tearDown];
}

- (void)testOne
{
    test_nonstate_lambda();
}

- (void)testTwo
{
    test_state_lambda();
}

@end
