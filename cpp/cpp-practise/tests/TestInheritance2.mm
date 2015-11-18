//
//  TestInheritance2.mm
//  cpp-practise
//
//  Created by kutty banerjee on 11/11/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#if 0
#import <XCTest/XCTest.h>
#include <iostream>
//#include "chipdispatch.h"

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

#pragma mark - BRN3
template <bool val, typename ChipDispatch>
class BRN3 {
public:
	void apply() {}
};

template <typename ChipDispatch>
class BRN3<true, ChipDispatch> {
	int localvalue;
public:
	void apply() {
		cout << " BRN3" << endl;
	}
};

#pragma mark - Code
/* Common Base Class */
template <typename ChipDispatch>
class ABase {
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
class A4 : public ABase<ChipDispatch> {
    BRN2<ChipDispatch::BRN::brn2, ChipDispatch> b2;
	BRN3<ChipDispatch::BRN::brn3, ChipDispatch> b3;
public:
    void first() {
        cout << "A4: first" << endl;
		ABase<ChipDispatch>::first();
        b2.apply();
		b3.apply();
    }
};

template <typename ChipDispatch = G5>
class A5 : public A4<ChipDispatch> {
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
        A5<G5G> a;
        a.first();
    }
}

@end
#endif