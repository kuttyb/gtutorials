//
//  KBTestThree.m
//  oc
//
//  Created by Kutty Banerjee on 1/6/14.
//  Copyright (c) 2014 kutty banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#import "KBFactory.h"
#import "KBNode.h"
#import "KBTest.h"

@interface KBTestThree : XCTestCase

@end

@implementation KBTestThree {
    id<KBNode> subject;
}

- (void)setUp
{
    [super setUp];
    subject = [KBFactory initThree];
}

- (void)tearDown
{
    [super tearDown];
}

- (void)testExample
{
    [KBTest test_body:subject];
}

@end
