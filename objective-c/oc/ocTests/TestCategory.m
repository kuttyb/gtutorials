//
//  TestCategory.m
//  oc
//
//  Created by kuttyb on 5/26/14.
//  Copyright (c) 2014 kutty banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#import "First.h"
#import "FirstDisplay.h"

@interface TestCategory : XCTestCase

@end

@implementation TestCategory {
    First *subject;
}

- (void)setUp
{
    [super setUp];
    subject = [[First alloc]init];
}

- (void)tearDown
{
    [super tearDown];
}

- (void)testExample
{
    [subject printValues];
    [subject crazyLastMinuteAddition];
    NSLog(@"printing outcome %d\n", [subject addNumbers:2 SECOND:3]);
}

@end
