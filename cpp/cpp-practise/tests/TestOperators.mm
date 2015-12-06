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
	
	A(const A& input) {
		one = input.one;
		two = input.two;
	}
	
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
	A c = a; // Assignment operator
	
	cout << "value of b: " << b.one << " " << b.two << endl;
	cout << "value of c: " << c.one << " " << c.two << endl;
}


@end
