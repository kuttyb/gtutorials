//
//  TestSFINAE.mm
//  cpp-cmd
//
//  This is a feature used on functions to enfore input types obey certain traits
//
//  Created by Kutty Banerjee on 6/15/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include <iostream>
#include <type_traits>
#include "typeassert.h"

using std::cout;
using std::endl;

#pragma mark Local Class
struct Local {
    bool operator==(const Local & other)  { return true; }
};

struct Global {
    bool operator==(const Global & other) { return true; }
};

class A {};

class B : public A {};

class C {};

// We are enforcing Type Hierarchy (aka Type Assert) as part of the template signature
template <typename T, typename enable_if<std::is_base_of<A, T>::value, T>::type * = nullptr>
void ATypes(T input) {
    cout << "testing inheritance " << endl;
}

#pragma mark Trait checks
template <typename T>
struct is_special_trait {
    static const bool value = false;
};

template <>
struct is_special_trait <Local> {
    static const bool value = true;
};

template <>
struct is_special_trait <int> {
    static const bool value = true;
};

template <>
struct is_special_trait <float> {
	static const bool value = true;
};

#pragma mark Function Overloads
// Place the type assert using the extra typename parameter below. Its similar to your TypeAssert except
// this is handy when you are using type traits (pure structs being passed to generic algorithm/ functions)
template <typename T, typename enable_if<is_special_trait<T>::value, T>::type * = nullptr>
T func(T input) {
    cout << "func speaking : overload 1 " << endl;
    return input;
}

template <typename T, typename enable_if<is_special_trait<T>::value, T>::type * = nullptr>
void func(T input, int arg) {
    cout << " func speaking : overload 2 " << endl;
}

#pragma mark Obj-C
@interface TestSFINAE : XCTestCase

@end

@implementation TestSFINAE

- (void)setUp
{
    [super setUp];
}

- (void)tearDown
{
    [super tearDown];
}

- (void)testBasics
{
    // Ensure Traits are working properly
    cout << "check Global: " << is_special_trait<Global>::value << endl;
    cout << "check Local : " << is_special_trait<Local>::value  << endl;
    
    // Ensure enable_if is working correctly
    enable_if<is_special_trait<Local>::value, Local>::type * x = 0;
    XCTAssert(!x);
    
#if 0
    // This would not compile correctly
    enable_if<is_special_trait<Global>::value, Global>::type  = 0;
    XCTAssert(!y);
#endif
}

- (void)testTypeAssertOnReturnType
{
    Local x;
    Local y = func(x);
    XCTAssert(x == y);
}

- (void)testTypeAssertOnInputType
{
    Local x;
    func<Local>(x, 3); // This should use the second overloaded function
}

- (void)testPrimitiveTypesforTraits
{
	func(3, 2);
	func(3, 2.5f);
}

- (void)testInheritance
{
    A a;
    B b;
    ATypes(a);
    ATypes(b);
#if 0 
    // This obviously does not compile
    C c;
    ATypes(c);
#endif
}

@end
