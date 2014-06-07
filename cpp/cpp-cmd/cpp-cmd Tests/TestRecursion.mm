//
//  TestRecursion.m
//  cpp-cmd
//
//  Created by kuttyb on 6/7/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include <iostream>
#include <tuple>
#include <utility>

using std::cout;
using std::endl;

class X { public: void print() { cout << "X speaking" << endl; } };
class Y { public: void print() { cout << "Y speaking" << endl; } };


// Class Specialization
template <size_t N, typename... T>
class Functor {
public:
    void method(T... input) {
        std::tuple<T...> args(input...);
        std::get<N>(args).print();
        Functor<N - 1, T...> x;
        x.method(input...);
    }
};

// Class Partial Specialization
template <typename... T>
class Functor<0, T...> {
public:
    void method(T... input) {
        std::tuple<T...> args(input...);
        std::get<0>(args).print();
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
    X a; Y b; Y c;
    {
        Functor<2, X, Y, Y> m;
        m.method(a, b, c);
    }
    
    {
        Functor<4, X, X, X, Y, Y> m;
        m.method(a, a, a, b, b);
    }
}

@end
