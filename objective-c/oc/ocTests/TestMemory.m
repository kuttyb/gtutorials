//
//  TestMemory.m
//  oc
//
//  Created by Kutty Banerjee on 10/26/14.
//  Copyright (c) 2014 kutty banerjee. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#import "MemoryWrapper.h"

@interface TestMemory : XCTestCase {
    MemoryWrapper * subject;
}

@end

@implementation TestMemory

- (void)setUp {
    [super setUp];
    subject = [[MemoryWrapper alloc] initWithData:10];
}

- (void)tearDown {
    [subject release];
    [super   tearDown];
}

- (void)testExample {
    [subject printIndex:2 COUNT:20];
}

@end
