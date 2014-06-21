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

#pragma mark Interface that all Iterators must obey
template <typename ST>
class Iterator {
public:
    void print() { DISPATCH(ST)->print(); }
};


#pragma mark C++
template <typename T>
class Vector {
private:
    T localvar;
public:
    Vector(int value) : localvar(value) {}
    
#pragma mark Iterator Inner classes
    class IteratorOne : public Iterator<IteratorOne>{
        Vector & m_Vector;
    public:
        IteratorOne(Vector & Vector) : m_Vector(Vector) {}
        void print() { cout << "Iterator 1: speaking Vector " << m_Vector.localvar++ << endl; }
    };
    
    class IteratorTwo : public Iterator<IteratorTwo> {
        Vector & m_Vector;
    public:
        IteratorTwo(Vector & Vector) : m_Vector(Vector) {}
        void print() { cout << "Iterator 2: speaking " << m_Vector.localvar++ << endl; }
    };
    
public:
    // Factories to hide the fact that one had to provide Vector & to the Iterator classes
    // for them to get access to private this* state of Vector
    IteratorOne  iteratorOne() { return IteratorOne(*this); }
    IteratorTwo  iteratorTwo() { return IteratorTwo(*this); }
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
    Vector<int> b(9);
    
    b.iteratorOne().print();
    b.iteratorTwo().print();
}

@end
