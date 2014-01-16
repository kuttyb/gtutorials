//
//  Function.m
//  cpp-code
//
//  Created by Kutty Banerjee on 1/15/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include <iostream>
#include "Function.h"

@interface Function : XCTestCase

@end

@implementation Function

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
    func(2);
    func(3.0f);
    XCTAssert(is_type_valid(2), "type: int mismatched");
    XCTAssert(!is_type_valid(2.0f), "type: float mismatched");
    XCTAssert(is_type_valid('c'), "type: char mismatched");
}

@end
