//
//  TestRecursion.m
//  cpp-cmd
//
//  Created by kuttyb on 6/7/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include <iostream>

using std::cout;
using std::endl;

// Class Specialization
template <typename T, size_t N>
class Functor {
public:
    static void method(T input) {
        cout << "generic version value : " << N << endl;
        Functor<T, N - 1> x;
        x.method(input);
    }
};

// Class Partial Specialization
template <typename T>
class Functor<T, 0> {
public:
    static void method(T input) {
        cout << "0 specialized class" << endl;
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

- (void)testExample
{
    Functor<int, 5> x;
    x.method(10);
}

@end
