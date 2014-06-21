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
// Inner classes in C++ are similar to Java's static inner classes, all they have access to is the enclosing classes's
// static members including static private members
class A {
public:
    int globalvar;
private:
    static int two;
    int localvar;
    
    class X {
        A* outer;
    public:
        X(A * ptr) { outer = ptr; }
    private:
        int one;
    public:
        int get_one() {
            /** can't do localvar since we don't have access to enclosing class'es private variables */
//            return one + two + localvar + globalvar;
            /** But if you can have the outer class pointer passed in to you, then you have access to
                anything and everything in the enclosing class object */
            return one + two + outer->localvar + outer->globalvar;
        }
    };
    
    X * x;
public:
    void print() {
        if (!x) {
            x = new X(this);
        }
        two++;
        cout << "value of two is " << two << " " <<  endl;
        cout << " inner value is " << x->get_one() << " " << endl;
    }
};

int A::two = 3;

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
