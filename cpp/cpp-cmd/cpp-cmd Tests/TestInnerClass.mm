//
//  TestInnerClass.mm
//  cpp-cmd
//
//  Created by kuttyb on 6/21/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include <iostream>
#include "crtp.h"

using std::cout;
using std::endl;

#pragma mark Interfaces
template <typename SUBTYPE>
class Policy {
public:
    void print() { DISPATCH(SUBTYPE)->print(); }
};

#pragma mark C++
// Inner Classes:
// ==============
//
// [a] They have complete access to private/protected static members of the enclosing class
//
// [b] They have complete access to private/protected members of the enclosing class
//
// [c] They **DON'T** have access to this* of the enclosing class, therefore it needs to be
//     supplied to them via some means.
//
// [d] As you will see, we used this for the Strategy Pattern, its passed in to A and is a member
//     and can be changed while instantiating A without changing code in A
//
template <typename POLICY_TYPE>
class A {
private:
    int localvar;
    
public:
    A() {
        localvar  = 3;
    }
    
    void print() {
        localvar++;
        cout << "value of two is " << localvar << " " <<  endl;
    }
    
#pragma mark inner-class
    template <typename TT>
    class X  : public Policy<X<TT> >  {
    private:
        A* outer;
        int one;
    public:
        X(A * ptr) { outer = ptr; }
        X(X & other) { outer = other.outer; one = 2; }
        int get_one() {
            return one + outer->localvar;
        }
        
        void print() {
            cout << "inner generic policy speaking" << endl;
        }
    };
    
    template <typename TT>
    class Y : public Policy<Y<TT> > {
    public:
        void print() {
            cout << "inner second policy speaking" << endl;
        }
    };
    
    Policy<X<POLICY_TYPE> > * getPolicy() {
        return new X<POLICY_TYPE>(this);
    }
};


#pragma mark Objective-C
@interface TestInnerClass : XCTestCase

@end

@implementation TestInnerClass

- (void)setUp
{
    [super setUp];
}

- (void)tearDown
{
    [super tearDown];
}

- (void)testExample
{
    A<int> a;
    a.getPolicy()->print();
}


@end
