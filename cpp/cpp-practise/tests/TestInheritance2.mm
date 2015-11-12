//
//  TestInheritance2.mm
//  cpp-practise
//
//  Created by kutty banerjee on 11/11/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include <iostream>
#include "chipdispatch.h"

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
/* Common Base Class */
template <typename ChipDispatch>
class A {
private:
	BRN1<ChipDispatch::BRN::brn1, ChipDispatch> b1;
public:
    void first() {
		cout << "ABase: first " << endl;
		b1.apply();
    }
};

/* G4 Specialization, inherits from the base class */
template <typename ChipDispatch = G4>
class A4  {
	A<ChipDispatch> base;	
    BRN2<ChipDispatch::BRN::brn2, ChipDispatch> b2;
    
public:
    void first() {
        cout << "A4: first" << endl;
		base.first();
        b2.apply();
    }
};

template <typename ChipDispatch = G5>
class A5  {
	A4<ChipDispatch> a4;
	
public:
	void first() {
		cout <<"A5 : first" << endl;
		a4.first();
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
    {
        A4<> a;
        a.first();
    }
	
	cout << "==========" << endl;
	
    {
        A5<> a;
        a.first();
    }
}

@end
