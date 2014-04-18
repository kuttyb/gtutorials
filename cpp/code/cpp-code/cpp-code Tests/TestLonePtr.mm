//
//  TestLonePtr.m
//  cpp-code
//
//  Created by Kutty Banerjee on 4/18/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include "LonePtr.hpp"

@interface TestLonePtr : XCTestCase

@end

template class LonePtr<int>;

@implementation TestLonePtr {
    LonePtr<int> subject;
}

- (void)setUp
{
    [super setUp];
    subject.set(new int());
}

- (void)tearDown
{
    subject.reset();
    [super tearDown];
}

- (void)testExample
{
    XCTAssert(subject.get(), "pointer should not be null");
}

@end
