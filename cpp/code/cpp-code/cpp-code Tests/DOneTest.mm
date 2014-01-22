//
//  DOneTest.m
//  cpp-code
//
//  Created by Kutty Banerjee on 1/21/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include <vector>
#include "DOne.h"

@interface DOneTest : XCTestCase

@end

using std::vector;

@implementation DOneTest {
    BaseOne<DOne> *subject;
}

- (void)setUp
{
    [super setUp];
    subject = new DOne();
}

- (void)tearDown
{
    delete subject;
    [super tearDown];
}

- (void)testExample
{
    subject->start(nil);
}

@end
