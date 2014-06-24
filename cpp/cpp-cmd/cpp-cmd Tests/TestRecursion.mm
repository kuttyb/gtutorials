//
//  TestRecursion.m
//  cpp-cmd
//
//  Created by kuttyb on 6/7/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include <iostream>
#include "typevector.h"

using std::cout;
using std::endl;

class X {
public:
    int local;
public:
    void print(int x) {
        cout << "X speaking " << x << " local: " << local << endl;
    }
    
    static X* create() {
        X* t =  new X();
        t->local = 10;
        return t;
    }
};

class Y {
public:
    int local;
public:
    void print(int x) {
        cout << "Y speaking " << x << " local: " << local << endl;
    }
    
    static Y* create() {
        Y* y = new Y();
        y->local = 10;
        return y;
    }
};


@interface TestRecursion : XCTestCase

@end

@implementation TestRecursion

- (void)setUp
{
    [super setUp];
}

- (void)tearDown
{
    [super tearDown];
}

- (void)testObserverPattern
{
    X a; Y b; Y c;
    int value = 3;
    
    typevector<X, Y, Y, X, X> data(&a, &b, &c, &a, &a);
    
    //
    // You are invoking method which will cause each Type to invoke print
    // on its variable with input parameter value... Classic Observer Pattern
    // (replace print with notify)
    //
    // Also use to store CRTP objects in a collection to operate upon in
    // bulk.
    //
    a.local = 20;
    b.local = 20;
    c.local = 20;
    foreach_type<data.size(), int, X, Y, Y, X, X>::method(&value, &data);
}

//
// Q: Why is this an "Abstract" Factory?
// A: Because changing foreach_type<...>::factory(..)
//    to foreach_type<...>::factoryTypeTwo(...)
//    would ensure all my types get a different kind of widget
//
//    Also learn to appreciate that with Templates you can pass type information
//    around and have the factory method invoke a static method in the Type
//    to create the object. Something you could not do with Generics that are
//    wildcard'ed wth Interface.
//
- (void)testAbstractFactory
{
    typevector<X, Y, X> data;
    
    // Create all the objects using their respective Type Factory methods
    foreach_type<data.size(), voidPtr, X, Y, X>::factory(&data);
    
    // Invoke all of them to ensure they got created properly
    int val = 9;
    {
        X* local = std::get<0>(data.args);
        local->local = 15;
    }
    foreach_type<data.size(), int, X, Y, X>::method(&val, &data);
    
    foreach_type<data.size(), int, X, Y, X>::destroy(&data);
}

// Because Templates and Lambdas don't mix we have to do pattern matching as below :-(
// TODO: Find out how the C++14 version helps
-(void)testLambda
{
    typevector<X, Y, X> data(NULL, NULL, NULL);
    foreach_type<data.size(), voidPtr, X, Y, X>::factory(&data);
    
    int value = 102;
    
    auto x = [value] (void *argument, int index)  {
        cout << "lambda getting invoked with index " << index << " " << endl;
        switch (index) {
            case 0:
            {
                X* ptr = static_cast<X*>(argument);
                ptr->print(value);
            }
                break;
                
            case 1:
            {
                Y* ptr = static_cast<Y*>(argument);
                ptr->print(value);
            }
                break;
                
            case 2:
            {
                X * ptr = static_cast<X *>(argument);
                ptr->print(value);
            }
                break;
        }
    };
    
    foreach_type<data.size(), voidPtr, X, Y, X>::execute(&data, x);
}

@end
