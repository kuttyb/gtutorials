//
//  TestMetaFunction.mm
//  cpp-cmd
//
//  Created by kuttyb on 6/8/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include <iostream>

using std::cout;
using std::endl;

#pragma mark Exercise 1 (factorial)
// template parameters are your function arguments and the static const part is the return value.
// any computation required in its value calculation is the body
template <unsigned int  n>
struct factorial {
	/* META Programming the old school way */
    static const unsigned int value = n * factorial<n-1>::value;

	/* META Programming new school way */
    static constexpr unsigned int fact() {
        return n * factorial<n-1>::fact();
    }
};

template <>
struct factorial<0> {
    static const unsigned int value = 1;
    
    static constexpr unsigned int fact() {
        return 1;
    }
};

#pragma mark Exercise 2 (larger type)
template <typename T1, typename T2,  bool n = (sizeof(T1) > sizeof(T2))>
struct choose_larger {
    T1 largertype;
};

template <typename T1, typename T2>
struct choose_larger <T1, T2, false> {
    T2 largertype;
};

#pragma mark Exercise 3 (if)
template <bool cond, typename T1, typename T2>
struct if_ {
    static void body() {
        cout << "true clause " << endl;
    }
};

// you could either put the body or if its just a type you want to select then
// declare it as a field with the same name. Probably great for checking properties
// of types at compile time to avoid nasty branchy code at runtime.
template <typename T1, typename T2>
struct if_ <false, T1, T2> {
    static void body() {
        cout << "false clause " << endl;
    }
};

#pragma mark Exercise 4 (Higher Order Functions)
// Takes in a Meta Function and returns a Meta Function
template <typename T1, bool n, typename T2, typename T3>
struct higher_ {
    static if_<false, T2, T3> func() {
        if_<n, T2, T3>::body();
        cout << "higher order function internals " << endl;
        if_<false, T2, T3> x;
        return x;
    }
};

@interface TestMetaFunction : XCTestCase

@end

@implementation TestMetaFunction

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
    factorial<3> x;
    cout << "factorial is " << x.value << endl;
    
    cout << "factorial is " << x.fact() << endl;
}

-(void)testLargerType
{
    choose_larger<char, double> x;
    cout << "size is " << sizeof(x) << endl;
}

-(void)testIf
{
    if_<(sizeof(int) > sizeof(double)), int, double> x;
    x.body();
}

-(void)testHigher
{
    higher_<int, true, int, float>::func().body();
}

@end
