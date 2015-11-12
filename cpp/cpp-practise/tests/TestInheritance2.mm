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
template <typename T, typename ChipDispatch>
class A {
private:
public:
    void first() {
        cout << "ABase: first " << 2 << endl;
    }
};

#define SUPER_A4  int, G4
/* G4 Specialization, inherits from the base class */
template <typename ChipDispatch>
class A4 : public A<SUPER_A4> {
    /* Parent class BRN that could be optionally used by derived classes */
    BRN1<ChipDispatch::BRN::brn1, ChipDispatch> b1;
    BRN2<ChipDispatch::BRN::brn2, ChipDispatch> b2;
    
public:
    void first() {
        cout << "A4: first" << endl;
        b1.apply();
        A<SUPER_A4>::first();
        
        cout << "size " << sizeof(A4) << endl;
        b2.apply();
    }
};

template <typename ChipDispatch>
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
//        A4<G4> a;
//        a.first();
    }
    
    {
        A5<G5> a;
        a.first();
    }
}

@end
