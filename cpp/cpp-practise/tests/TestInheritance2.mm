//
//  TestInheritance2.mm
//  cpp-practise
//
//  Created by kutty banerjee on 11/11/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include <iostream>

using std::cout;
using std::endl;

#pragma mark - BRN1
template <bool val, typename ChipDispatch>
class BRN1 {
public:
	void apply() {}
};

template <typename ChipDispatch>
class BRN1<true, ChipDispatch> {
	int local_value;
public:
	void apply() {
		cout << "BRN1 " << endl;
	}
};

#pragma mark - BRN2
template <bool val, typename ChipDispatch>
class BRN2 {
public:
	void apply() {}
};

template <typename ChipDispatch>
class BRN2<true, ChipDispatch> {
	int value;
public:
	void apply() {
		cout << "BRN2" << endl;
	}
};

#pragma mark - Code
template <typename T, bool brn1, typename ChipDispatch>
class A {
private:
	/* Parent class BRN that could be optionally used by derived classes */
	BRN1<brn1, ChipDispatch> b1;
	
public:
	void first() {
		cout << "ABase: first " << 2 << endl;
		b1.apply();
	}
};

#define SUPER_A4  int, false, int
class A4 : public A<SUPER_A4> {
	BRN2<true, int> b2;
public:
	void first() {
		cout << "A4: first" << endl;
		A<SUPER_A4>::first();

		cout << "size " << sizeof(A4) << endl;
		b2.apply();
	}
};


#pragma mark - Test
@interface TestInheritance2 : XCTestCase

@end

@implementation TestInheritance2

- (void)setUp
{
    [super setUp];
	cout << "===========================" << endl;
}

- (void)tearDown
{
    [super tearDown];
	cout << "===========================" << endl;
}

- (void)testBasic
{
	A4 a;
	a.first();
}

@end
