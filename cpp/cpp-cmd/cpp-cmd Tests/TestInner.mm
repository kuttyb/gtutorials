//
//  TestInner.m
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

#pragma mark Interface
template <typename ST>
class Policy {
public:
    void print() { DISPATCH(ST)->print(); }
};


#pragma mark C++
template <typename T>
class Outer {
private:
    T localvar;
public:
    Outer(int value) : localvar(value) {}
    
    class InnerOne : public Policy<InnerOne>{
        Outer & m_outer;
    public:
        InnerOne(Outer & outer) : m_outer(outer) {}
        void print() { cout << "Inner 1: speaking outer " << m_outer.localvar++ << endl; }
    };
    
    class InnerTwo : public Policy<InnerTwo> {
        Outer & m_outer;
    public:
        InnerTwo(Outer & outer) : m_outer(outer) {}
        void print() { cout << "Inner 2: speaking " << m_outer.localvar++ << endl; }
    };
};

#pragma mark Objective-C
@interface TestInner : XCTestCase

@end

@implementation TestInner

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
    Outer<int> b(9);
    
    Outer<int>::InnerOne a(b);
    a.print();
    
    Outer<int>::InnerTwo x(b);
    x.print();
}

@end
