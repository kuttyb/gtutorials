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
struct MyLiteral
{
	int   first;
	float second;
	constexpr MyLiteral(int a, float b) : first(a), second(b) {}
};

constexpr MyLiteral one = MyLiteral(2, 3.5f);
constexpr MyLiteral two = MyLiteral(5, 10.2f);

constexpr MyLiteral generateType(int a, float b) {
	if (a > 10) {
		return MyLiteral(a, b);
	} else if (a > 5){
		return one;
	} else if (a > 2) {
		return two;
	} else {
		return MyLiteral(0, b);
	}
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
