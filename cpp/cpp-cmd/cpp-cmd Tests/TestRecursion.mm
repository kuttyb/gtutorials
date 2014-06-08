//
//  TestRecursion.m
//  cpp-cmd
//
//  Created by kuttyb on 6/7/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include <iostream>
#include "TypeCollection.h"

using std::cout;
using std::endl;

class X {
private:
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
private:
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
    foreach_type<data.size(), int, X, Y, Y, X, X>::method(&value, &data);
}

- (void)testAbstractFactory
{
    typevector<X, Y, X> data(NULL, NULL, NULL);
    
    // Create all the objects using their respective Type Factory methods
    foreach_type<data.size(), voidPtr, X, Y, X>::factory(&data);
    
    // Invoke all of them to ensure they got created properly
    int val = 9;
    foreach_type<data.size(), int, X, Y, X>::method(&val, &data);
}

@end
