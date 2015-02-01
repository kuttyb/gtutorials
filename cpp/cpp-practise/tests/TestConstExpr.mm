//
//  TestConstExpr.mm
//  cpp-practise
//
//  Created by Kutty Banerjee on 1/31/15.
//  Copyright (c) 2015 kbanerjee. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#include <iostream>

using std::cout;
using std::endl;

#pragma mark - C++
/* Important thing being, 
 * [a] C++14 lets you use loops, local variables and multiple returns inside a constexpr
 * [b] Any types it uses must be literal types or user-defined literal types like below
 *     (read simple dtor and constexpr ctor
 */
class literal_str_list {
    const char* const ptr;
    unsigned int      size;
public:
    template <unsigned int N>
    constexpr literal_str_list(const char(&str)[N]) :
    ptr(str), size(N-1){
        static_assert(N >= 1, "Invalid string literal! Length is zero!");
    };
};

constexpr literal_str_list int_type    = "int";
constexpr literal_str_list float_type  = "float";
constexpr literal_str_list double_type = "double";

constexpr literal_str_list getName(int i) {
    if (!i) return int_type;
    if (i == 1) return float_type;
    return double_type;
}

#pragma mark - Selecting a Different Type based on the Input Type
template <int N> struct TypeGenerator{};
template <> struct TypeGenerator<0> {typedef int     type;};
template <> struct TypeGenerator<1> {typedef float   type;};
template <> struct TypeGenerator<2> {typedef double  type;};

struct A {
    int num;
    typename TypeGenerator<0>::type var;
    typename TypeGenerator<1>::type var2;
};

#pragma mark - Test Logic
@interface TestConstExpr : XCTestCase

@end

@implementation TestConstExpr

- (void)setUp {
    [super setUp];
}

- (void)tearDown {
    [super tearDown];
}

- (void)testExample {

}

@end
