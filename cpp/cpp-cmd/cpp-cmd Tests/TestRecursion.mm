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

using std::cout;
using std::endl;

class X { public: void print() { cout << "X speaking" << endl; } };
class Y { public: void print() { cout << "Y speaking" << endl; } };


// Class Specialization
template <size_t N, typename... T>
class Functor {
public:
    static void method(T&... input) {
        std::tuple<T...> args(input...);
        std::get<N - 1>(args).print();
        
        // Recurse ...
        Functor<N - 1, T...>::method(input...);
    }
};

// Class Partial Specialization
template <typename... T>
class Functor<1, T...> {
public:
    static void method(T&... input) {
        std::tuple<T...> args(input...);
        std::get<0>(args).print();
    }
};

template <typename... T>
struct ABC {
    std::tuple<T...> args;
    
    ABC(T... input) {
        args = std::make_tuple(input...);
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
        Functor<3, X, Y, Y>::method(a, b, c);
    }
    
    ABC<X, Y, Y> data(a, b, c);
}

@end
