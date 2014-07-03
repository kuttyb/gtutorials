//
//  TestFilter.m
//  cpp-cmd
//
//  Created by kutty banerjee on 7/3/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include <iostream>
#include "typevector.h"

using std::cout;
using std::endl;

struct FilterOne {
	void print(int input) {
		cout << "filter one speaking and you passed me  " << input << endl;
	}
};

struct FilterTwo {
	void print(int input) {
		cout << "Filter two speaking and you passed me " << input << endl;
	}
};

struct FilterThree {
	void print(int input) {
		cout << "Filter three speaking and you passed me " << input << endl;
	}
};

@interface TestFilter : XCTestCase

@end

@implementation TestFilter

- (void)setUp {
    [super setUp];
	cout << endl << "======================================" << endl << endl;
}

- (void)tearDown {
	cout << endl << "======================================" << endl;
    [super tearDown];
}

// For Ray and his blogger friend !!
- (void)testExample {
	typevector<FilterOne, FilterTwo, FilterThree> x;
	
	int input = 3;
	foreach_type<x.size(), int, FilterOne, FilterTwo, FilterThree>::method(&input, &x);
}

@end
