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

#pragma mark - C++ (Virtual Functions)
class Interface {
public:
	virtual int execute(int input) = 0;
	virtual ~Interface() {}
};

class Worker : public Interface {
public:
	int execute(int input) override {
		return input * 3;
	}
};

class Subworker : public Worker {
public:
	int execute(int input) override {
		return Worker::execute(input);
	}
};

#pragma mark - C++ (Templates)
template <typename T>
class TInterface {
	T helper;
public:
	int execute(int input) {
		return helper.execute(input);
	}
};

class HelperOne {
public:
	int execute(int input) {
		return input * 3;
	}
};

class HelperTwo : public HelperOne {
	
public:
	int execute(int input) {
		return HelperOne::execute(input);
	}
};

#pragma mark - Test
#define  MAX_ITERATIONS (1'000'000)
//#define  MAX_ITERATIONS (100)

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

- (void) testTemplatesChild {
	for (int j = 0 ; j < 4; ++j) {
		int counter = 0;
		TInterface<HelperOne> helper;
		
		perf::profile<std::chrono::microseconds>()([&counter, &helper](){
			int value = 0;
			
			for (int i = 0; i < MAX_ITERATIONS; ++i) {
				value += helper.execute(i);
			}
			
			counter = value;
		}, 100);
		
		cout << "counter value is " << counter << endl;
	}
}

- (void) testTemplatesInnerChild {
	for (int j = 0; j < 4; ++j) {
		int counter = 0;
		TInterface<HelperTwo> helper;
		
		perf::profile<std::chrono::microseconds>()([&counter, &helper](){
			int value = 0;
			
			for (int i = 0; i < MAX_ITERATIONS; ++i) {
				value += helper.execute(i);
			}
			
			counter = value;
		}, 100);
		
		cout << "counter value is " << counter << endl;
	}
}

- (void) testChild {
	for (int j = 0; j < 4; ++j) {
		int counter = 0;
		Interface * worker = new Worker();
		
		perf::profile<std::chrono::microseconds>()([&counter, &worker](){
			int value = 0;
			
			for (int i = 0; i < MAX_ITERATIONS; ++i) {
				value += worker->execute(i);
			}
			
			counter = value;
		}, 1000);
		
		cout << "counter value is " << counter << endl;
	}
}

- (void) testInnerChild {
	for (int j = 0; j < 4; ++j) {
		int counter = 0;
		Interface * worker = new Subworker();
		
		perf::profile<std::chrono::microseconds>()([&counter, &worker](){
			int value = 0;
			
			for (int i = 0; i < MAX_ITERATIONS; ++i) {
				value += worker->execute(i);
			}
			
			counter = value;
		}, 1000);
		
		cout << "counter value is " << counter << endl;
	}
}

@end
