//
//  TestPerf.mm
//  cpp-practise
//
//  Created by kuttyb on 12/1/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include <iostream>
#include "benchmark.h"

#pragma mark - C++


#pragma mark - Test
@interface TestPerf : XCTestCase

@end

@implementation TestPerf

- (void)setUp {
	[super setUp];
	cout << "===============" << endl;
}

- (void)tearDown {
	cout << "===============" << endl;
	[super tearDown];
}

- (void)testBasic {
	int counter = 0;
	
	perf::profile<std::chrono::nanoseconds>()([&counter](){
		int value = 0;
		
		for (int i = 0; i < 1'000'000; ++i) {
			 value += i * 3;
		}
		
		counter = value;
	}, 1000);

	cout << "counter value is " << counter << endl;
}

@end
