//
//  TestRValues.mm
//  cpp-practise
//
//  Created by kuttyb on 2/1/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#include <iostream>

using std::cout;
using std::endl;

#pragma mark - C++
struct A {
	int   fieldint;
	float fieldfloat;
	
	/* Copy constructor and assignment operator */
	A() = default;
	A& operator=(const A & input) {
		fieldint   = input.fieldint;
		fieldfloat = input.fieldfloat;
		cout << "assignment operator" << endl;
		return *this;
	}
	
	A& operator=(A & input) {
		cout << "swap assignment operator" << endl;
		return *this;
	}
	
	A(const A & input) {
		fieldint   = input.fieldint;
		fieldfloat = input.fieldfloat;
		cout << "copy constructor" << endl;
	}
	
	/* Move constructor and assignment operator */
	A(const A && input) {
		fieldint   = input.fieldint;
		fieldfloat = input.fieldfloat;
		cout << "move constructor" << endl;
	}
	
	A& operator=(const A && input) {
		fieldint   = input.fieldint;
		fieldfloat = input.fieldfloat;
		cout << "move assignment operator" << endl;
		return *this;
	}
};


A factory(int x, float y) {
	A value;
	value.fieldfloat = y;
	value.fieldint   = x;
	return value;
}

void printObject(const A & value) {
	cout << value.fieldfloat << " " << value.fieldint << endl;
}

#pragma mark - Test Logic
@interface TestRValues : XCTestCase

@end

@implementation TestRValues

- (void)setUp {
    [super setUp];
	cout << "===============" << endl;
}

- (void)tearDown {
	cout << "===============" << endl;
    [super tearDown];
}

void func(int & a) {
	a++;
	cout << "func: value is " << a << endl;
}

void func(const int & a) {
	cout << "const_func : value is " << a << endl;
}

int& func(int && a) {
	a++;
	cout <<"rvalue_func: value is " << a << endl;
	++a;
	return a;
}

-(void) testBasics {
	int a   = 3;
	int &b  = a;
	int &&c = a + 1;

	func(b);
	cout << "returned value is " << func(b + 1) << endl;
	func(c);
	func(a);
}

- (void)testExample {
	A value = factory(2, 3.5f);
//	cout << value.fieldfloat << " " << value.fieldint << endl;
	printObject(value);
	printObject(factory(10, 12.2f));
}

@end
