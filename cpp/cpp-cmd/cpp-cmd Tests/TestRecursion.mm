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

// Class Specialization
template <size_t N, typename... T>
class Functor {
public:
    static void method(T... input) {
        cout << "generic version value : " << N << endl;
        Functor<N - 1, T...> x;
        
        std::tuple<T...> args(input...);
        cout << "kbb: printing value " << std::get<N>(args) << endl;
        
        x.method(input...);
    }
};

// Class Partial Specialization
template <typename... T>
class Functor<0, T...> {
public:
    static void method(T... input) {
        cout << "0 specialized class" << endl;
        std::tuple<T...> args(input...);
        cout << "kbb: printing value " << std::get<0>(args) << endl;
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
    Functor<2, int, int, float> x;
    x.method(2, 3, 4.3f);
}

@end
