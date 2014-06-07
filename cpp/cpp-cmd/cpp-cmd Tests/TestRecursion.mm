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

#pragma mark Type Container class -
template <typename... T>
struct ABC {
    std::tuple<T...> args;
    
    ABC(T... input) {
        args = std::make_tuple(input...);
    }
    
    constexpr size_t size() const {
        return std::tuple_size<std::tuple<T...> >::value;
    }
};


#pragma mark Type Processor class -
template <size_t N, typename... T>
class Functor {
public:
    static void method(ABC<T...>& input) {
        std::get<N - 1>(input.args).print();
        
        // Recurse ...
        Functor<N - 1, T...>::method(input);
    }
};

// Class Partial Specialization
template <typename... T>
class Functor<1, T...> {
public:
    static void method(ABC<T...>& input) {
        std::get<0>(input.args).print();
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
        ABC<X, Y, Y> data(a, b, c);
        
        Functor<data.size(), X, Y, Y>::method(data);
    }
}

@end
