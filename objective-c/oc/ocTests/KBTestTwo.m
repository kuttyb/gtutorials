//
//  KBTestTwo.m
//  oc
//
//  Created by kutty banerjee on 1/6/14.
//  Copyright (c) 2014 kutty banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#import "KBTest.h"
#import "KBFactory.h"
#import "KBNode.h"

@interface KBTestTwo : XCTestCase

@end

@implementation KBTestTwo {
	id<KBNode> subject;
}

- (void)setUp
{
    [super setUp];
	subject = [KBFactory initTwo];
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
