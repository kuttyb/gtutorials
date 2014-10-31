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
#import "Memory.h"

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
    /* There you go, we were right, this should implement hidden [subject release]
     * with ARC or perhaps it does a [subject autorelease], I don't care. It gets
     * the dealloc to be invoked which lets me free the memory that I might be 
     * managing manually at times.
     */
    subject = nil;
    printf("done calling nil\n");
    [super   tearDown];
}

- (void)testExample {
    [subject printIndex:2 COUNT:20];
    subject.delegate = [[Memory alloc] initWithData:20];
    XCTAssert([subject delegate] != nil);
}

@end
