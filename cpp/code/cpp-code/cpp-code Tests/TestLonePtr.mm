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
    subject.setIfNotSet(new int());
}

- (void)tearDown
{
    [super tearDown];
}

- (void)testMoveDoesNotMove
{
    XCTAssert(subject.get(), "pointer should not be null");
    LonePtr<int> x;
    std::move(subject);
    XCTAssert(subject.get(), "");
}

- (void)testOurMoveWorks
{
    LonePtr<int> x;
    
    XCTAssert(!x.get(), "");
    XCTAssert(subject.get(), "");
    
    subject.move(x);
    XCTAssert(!subject.get(), "");
    XCTAssert(x.get(), "");
}

@end
