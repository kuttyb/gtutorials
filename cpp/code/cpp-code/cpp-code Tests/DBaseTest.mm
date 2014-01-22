//
//  DBaseTest.m
//  cpp-code
//
//  Created by Kutty Banerjee on 1/21/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include "DBase.h"

@interface DBaseTest : XCTestCase

@end

@implementation DBaseTest {
    DBasex<DDerived> *subject;
}

- (void)setUp
{
    [super setUp];
    subject = new DBasex<DDerived>();
}

- (void)tearDown
{
    delete subject;
    [super tearDown];
}

- (void)testExample
{
    XCTAssert(subject, "");
    subject->start();
}

@end
