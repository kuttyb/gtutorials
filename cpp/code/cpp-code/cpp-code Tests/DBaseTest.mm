//
//  DBaseTest.m
//  cpp-code
//
//  Created by Kutty Banerjee on 1/21/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include "DBase.h"
#include "E.hpp"
#include "F.hpp"

@interface DBaseTest : XCTestCase

@end

@implementation DBaseTest {
    DBasex<DDerived> *subject;
    E<F> *b;
}

- (void)setUp
{
    [super setUp];
    subject = new DBasex<DDerived>();
    b = new E<F>();
}

- (void)tearDown
{
    delete b;
    delete subject;
    [super tearDown];
}

- (void)testExample
{
    XCTAssert(subject, "");
    subject->start();
    F x;
    b->start(x);
}

@end
