//
//  TestT.m
//  cpp-code
//
//  Created by Kutty Banerjee on 1/7/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include <iostream>
#include "Initialization.h"

@interface TestNonTemplate : XCTestCase

@end

@interface TestNonTemplate ()
- (void)testExample;
@end

@implementation TestNonTemplate {
    NonTemplate *subject;
}

- (void)setUp
{
    [super setUp];
    subject = new NonTemplate(3);
}

- (void)tearDown
{
    delete subject;
    [super tearDown];
}

- (void)testExample
{
    subject->print();
}

@end
