//
//  tests.m
//  tests
//
//  Created by kuttyb on 11/21/14.
//  Copyright (c) 2014 kbanerjee. All rights reserved.
//
#include <iostream>
#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>

using std::cout;
using std::endl;

#pragma mark - Data Classes
struct One {
    int a;
};

struct Two {
    float a;
    One b;
    Two(float input) { a = input; }
};

#pragma mark - Composite Functions
struct X {
    int a;
};

struct Y {
    int a;
};

template <typename T>
void print(T input) { cout << "generic printer" << endl; }

template <>
void print(X input) { cout << "X speaking" << endl; }

template <>
void print(Y input) { cout << "Y speaking" << endl; }

#pragma mark - Second order Pure Functions
template <typename T>
void operate(T input) {
    cout << "generic version" << endl;
}

void operate(One input) {
    cout << "One speaking" << endl;
}

void operate(Two input) {
    cout << "Two speaking" << endl;
    operate(input.b);
}

@interface tests : XCTestCase

@end

@implementation tests

- (void)setUp {
    [super setUp];
}

- (void)tearDown {
    [super tearDown];
}

- (void)testBasic {
    operate(3);
    One a; Two b(2.3f);
    operate(a);
    operate(b);
}

@end
