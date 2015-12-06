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
	
	A(int one, int two) {
		this->one = one;
		this->two = two;
	}
	
//	A(const A& input) = delete;
	A(const A& input) {
		one = input.one;
		two = input.two;
	}
	
//	A& operator=(const A& input) = delete;
	A& operator=(const A& input) {
		one = input.one;
		two = input.two;
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
	XCTAssert(b.one == 4);
	XCTAssert(b.two == 5);
	
	A c = a; // Assignment operator
	XCTAssert(c.one == 4);
	XCTAssert(c.two == 5);
}


@end
