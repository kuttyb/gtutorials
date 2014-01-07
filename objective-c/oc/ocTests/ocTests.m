//
//  ocTests.m
//  ocTests
//
//  Created by kutty banerjee on 1/6/14.
//  Copyright (c) 2014 kutty banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#import "KBTest.h"
#import "KBNode.h"
#import "KBFactory.h"

@interface ocTests : XCTestCase

@end

@implementation ocTests {
	id<KBNode> subject;
}

- (void)setUp
{
    [super setUp];
	subject = [KBFactory initOne];
}

- (void)tearDown
{
    [super tearDown];
}

- (void)testBasic
{
	[KBTest test_body:subject];
}

@end
