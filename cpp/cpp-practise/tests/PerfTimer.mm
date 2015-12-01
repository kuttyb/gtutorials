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
#include "atomics.h"

@interface PerfTimer : XCTestCase

@end

@implementation PerfTimer

- (void)setUp
{
    [super setUp];
	cout << "================" << endl;
}

- (void)tearDown
{
	cout << "================" << endl;
    [super tearDown];
}

- (void)testWithCAS
{
	int value = 0;
	
	perf::profile<std::chrono::microseconds>()([&value](){
		int x = 0;
		for (int i = 0 ; i < 1000; ++i) {
			int y = x;
			CAS(&x, y, y + 1);
		}
		value = x;
	}, 5);

	cout << "value is " << value << endl;
}

- (void)testWoCAS
{
	int value = 0;
	
	perf::profile<std::chrono::microseconds>()([&value](){
		int x = 0;
		for (int i = 0 ; i < 1000; ++i) {
			x = x + 1;
		}
		value = x;
	}, 5);
	
	cout << "value is " << value << endl;
}

@end
