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
};

namespace BIG {
    class SELECTOR {
    public:
        typedef One Line;
        typedef Two Linenext;
    };
};

namespace SMALL {
    class SELECTOR {
    public:
        typedef Two Line;
        typedef One Linenext;
    };
};

#pragma mark - Second order Pure Functions
template <typename T>
void operate(T input) {
    cout << "generic version" << endl;
}

template <>
void operate(One input) {
    cout << "One speaking" << endl;
}

template <>
void operate(Two input) {
    cout << "Two speaking" << endl;
    operate(input.b);
}

template <typename X>
void top() {
    typename X::Linenext var;
    operate(var);
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
    top<SMALL::SELECTOR>();
}

@end
