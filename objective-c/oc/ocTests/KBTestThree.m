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

@property(nonatomic, strong) id <KBNode> subject;
@end

@implementation KBTestThree

- (void)setUp
{
    [super setUp];
    self.subject = [KBFactory initThree];
}

- (void)tearDown
{
    [super tearDown];
}

- (void)testExample
{
    [KBTest test_body:self.subject];
}

@end
