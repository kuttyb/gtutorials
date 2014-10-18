//
// Created by Kutty Banerjee on 1/19/14.
// Copyright (c) 2014 kutty banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#import "KBOne.h"

@interface KBTestFour : XCTestCase

@end

@implementation KBTestFour {
    @private
    KBOne *subject;
}

- (void)setUp
{
    [super setUp];
    subject = [[KBOne alloc]init];
}

- (KBTestFour * ) build
{
    return self;
}

- (void)tearDown
{
    [super tearDown];
}

-(void) testOne {
    XCTAssert(subject, "");
    KBTestFour * data = [self build];
    XCTAssert(data != nil);
}

@end
