//
//  ocTests.m
//  ocTests
//
//  Created by kutty banerjee on 1/6/14.
//  Copyright (c) 2014 kutty banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
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

- (void)testExample
{
	@autoreleasepool {
		NSLog(@"return value is %d", [subject add:3 INPUTTWO:5]);
		[subject dumpState];
		[subject compareThree:20 TWO:10 THREE:3];
		[subject dumpState];
	}
}

@end
