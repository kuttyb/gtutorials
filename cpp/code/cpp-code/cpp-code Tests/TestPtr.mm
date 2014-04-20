//
//  TestPtr.m
//  cpp-code
//
//  Created by kuttyb on 4/19/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include "SmartPtr.h"

@interface TestPtr : XCTestCase

@end

@implementation TestPtr

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
    test_unique_ptr_reference();
}

@end
