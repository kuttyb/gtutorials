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
public:
    void print(int x) {
        cout << "X speaking " << x << endl;
    }
    
    static X* create() {
        return new X();
    }
};

class Y {
public:
    void print(int x) {
        cout << "Y speaking " << x << endl;
    }
    
    static Y* create() {
        return new Y();
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
    
    TypeContainer<X, Y, Y, X, X> data(&a, &b, &c, &a, &a);
    
    //
    // You are invoking method which will cause each Type to invoke print
    // on its variable with input parameter value... Classic Observer Pattern
    // (replace print with notify)
    //
    // Also use to store CRTP objects in a collection to operate upon in
    // bulk.
    //
    TypeProcessor<data.size(), int, X, Y, Y, X, X>::method(&value, &data);
}

- (void)testAbstractFactory
{
    TypeContainer<X, Y, X> data(NULL, NULL, NULL);
    
    // Create all the objects using their respective Type Factory methods
    TypeProcessor<data.size(), voidPtr, X, Y, X>::factory(&data);
    
    // Invoke all of them to ensure they got created properly
    int val = 9;
    TypeProcessor<data.size(), int, X, Y, X>::method(&val, &data);
}

@end
