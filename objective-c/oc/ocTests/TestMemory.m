//
//  TestMemory.m
//  oc
//
//  Created by Kutty Banerjee on 10/26/14.
//  Copyright (c) 2014 kutty banerjee. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#import "Memory.h"

@interface TestMemory : XCTestCase {
    Memory * subject;
    Memory * test;
}

@end

@implementation TestMemory

- (void)setUp {
    [super setUp];
    subject = [[Memory alloc] initWithData:10];
    test    = [Memory newMemory:10];
}

- (void)tearDown {
    [subject release];
    [test    release];
    [super   tearDown];
}

- (void)testExample {
    [subject printIndex:2 COUNT:20];
    [test    printIndex:2 COUNT:20];
}

@end
