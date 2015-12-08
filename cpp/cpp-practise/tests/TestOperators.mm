//
//  TestOperators.mm
//  cpp-practise
//
//  Created by kuttyb on 12/6/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include <iostream>
#include <memory>

using std::cout;
using std::endl;

#pragma mark - C++
class A {
public:
	int one;
	int two;
	
	explicit A(int one, int two) {
		this->one = one;
		this->two = two;
	}
	
//	A(const A& input) = delete;
	A(const A& input) {
		one = input.one + 1;
		two = input.two + 1;
	}
	
//	A& operator=(const A& input) = delete;
	A& operator=(const A& input) {
		one = input.one + 2;
		two = input.two + 2;
		return *this;
	}
};

#pragma mark - Test
@interface TestOperators : XCTestCase

@end

@implementation TestOperators

- (void)setUp {
    [super setUp];
}

- (void)tearDown {
    [super tearDown];
}

- (void) testCopy {
	A a(4, 5);
	
	A b(a);  // Copy constructor
	XCTAssert(b.one == 5);
	XCTAssert(b.two == 6);
	
	A c = a; // Assignment operator
	XCTAssert(c.one == 5);
	XCTAssert(c.two == 6);
}

@end
