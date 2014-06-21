//
//  TestInnerClass.mm
//  cpp-cmd
//
//  Created by kuttyb on 6/21/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include <iostream>

using std::cout;
using std::endl;

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
class A {
public:
private:
    int localvar;
    
#pragma mark inner-class
    class X {
    private:
        A* outer;
        int one;
    public:
        X(A * ptr) { outer = ptr; }
        X(X & other) { outer = other.outer; one = 2; }
        int get_one() {
            return one + outer->localvar;
        }
    };
    
private:
    X  x;
    
public:
    A() : x(this) {
        localvar  = 3;
    }
    
    void print() {
        localvar++;
        cout << "value of two is " << localvar << " " <<  endl;
        cout << " inner value is " << x.get_one() << " " << endl;
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
    A a;
    a.print();
}


@end
