//
//  TestFunctionalCompositional.mm
//  cpp-cmd
//
//  Created by kuttyb on 9/8/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#include <iostream>

using std::cout; using std::endl;

#pragma mark - C++ Structs
struct One {
    int x; int y ;
    One(int _x, int _y) : x(_x), y(_y) {}
};

struct Two {
    float a;
    One base;
    Two(float _a, int x, int y) : a(_a), base(x, y) {}
};

#pragma mark - C++ functions (template specialization including Higher Order Functions)
template <typename T> void common(T input) {
    cout << "generic version: " << endl;
}

template <> void common<One>(One input) {
    cout << "One version: " << endl;
}

template <> void common<Two>(Two input) {
    cout << "Two version: " << endl;
    // Higher order functions making this easy. (No CRTP or Virtual functions or OO)
    common(input.base);
}

#pragma mark - C++ functions (trait specialization)
template <bool n, typename T>
struct enable_if {
};

template <typename T>
struct enable_if <true, T> {
    typedef T type;
};

template <typename T> struct is_good { static const bool value = false; };
template <typename T> struct is_bad  { static const bool value = false; };
template <> struct is_good <One> { static const bool value = true; };
template <> struct is_bad<Two>   { static const bool value = true; };

template <typename T, typename enable_if<is_good<T>::value, T>::type * = nullptr>
void print(T input) { cout << "good method" << endl; }

template <typename T, typename enable_if<is_bad<T>::value, T>::type  * = nullptr>
void print(T input) { cout << "bad method"  << endl; print(input.base);}


#pragma mark - Obejctive C
@interface TestFunctional : XCTestCase

@end

@implementation TestFunctional

- (void)setUp
{
    [super setUp];
    cout << "================" <<endl;
}

- (void)tearDown
{
    cout << "================" <<endl;
    [super tearDown];
}

- (void)testSpecialization
{
    One a(2, 3); Two b(3.4, 2, 1);
    common(a);
    common(b);
    common(3);
}

- (void)testTraitSpecialization
{
    One a(2, 3); Two b(3.4, 2, 1);
    print(a);
    print(b);
}

@end
