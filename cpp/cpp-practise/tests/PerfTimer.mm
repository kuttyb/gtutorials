//
//  PerfTimer.m
//  cpp-practise
//
//  Created by kuttyb on 12/6/14.
//  Copyright (c) 2014 kbanerjee. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#include <iostream>
#include <functional>
#include <string>
#include "benchmark.h"

@interface PerfTimer : XCTestCase

@end

@implementation PerfTimer

- (void)setUp
{
    [super setUp];
}

- (void)tearDown
{
    [super tearDown];
}

- (void)testExample
{
    int x = 10;
	perf::benchmark<std::chrono::microseconds>([x](){
		cout << "first line of text" << x << " that is the value" << endl;
	}, 5);
}

@end
