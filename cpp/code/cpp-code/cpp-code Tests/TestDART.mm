//
//  TestDART.m
//  cpp-code
//
//  Created by Kutty Banerjee on 3/9/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//
#import <XCTest/XCTest.h>
#include "DART.h"

@interface TestDART : XCTestCase

@end

@implementation TestDART {
    DART *subject;
}

- (void)setUp
{
    [super setUp];
    subject = new DART();
    
    // Non overlapping reads
    subject->add_read_range(0x1000, 0x10);
    subject->add_read_range(0x1000, 0x10);
    
    // Non overlapping writes
    subject->add_write_range(0x1000, 0x10);
    subject->add_write_range(0x2000, 0x10);
}

- (void)tearDown
{
    delete subject;
    [super tearDown];
}

- (void)testWAR_CompleteOverlap
{
    XCTAssert(!subject->overlapping(), "Should not have an overlap at this point");
    subject->add_write_range(0x1000, 0x10);
    XCTAssert(subject->overlapping(), "Should have had an overlap at this point");
}

- (void)testWAR_PartialOverlap
{
    XCTAssert(!subject->overlapping(), "Should not have an overlap at this point");
    subject->add_write_range(0x900, 0x1000);
    XCTAssert(subject->overlapping(), "Should have had an overlap at this point");
}

- (void)testRAW_CompleteOverlap
{
    XCTAssert(!subject->overlapping(), "Should not have an overlap at this point");
    subject->add_write_range(0x1000, 0x10);
    XCTAssert(subject->overlapping());
}

- (void)testRAW_PartialOverlap
{
    XCTAssert(!subject->overlapping(), "Should not have an overlap at this point");
    subject->add_write_range(0x900, 0x1000);
    XCTAssert(subject->overlapping());
}

@end
