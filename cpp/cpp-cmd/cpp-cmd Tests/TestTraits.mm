//
//  TestTraits.m
//  cpp-cmd
//
//  Created by kuttyb on 9/7/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#include <iostream>

using std::cout;
using std::endl;

#pragma mark enable_if
template <bool n, typename T>
struct enable_if {
};

template <typename T>
struct enable_if<true, T> {
    typedef T type;
};

#pragma mark trait
template <typename T>
struct is_this_trait {
    static const bool value = false;
};

template <typename T>
struct is_that_trait {
    static const bool value = false;
};

#pragma mark Test Method
template <typename T, typename enable_if<is_this_trait<T>::value, T>::type * = nullptr>
void method(T input) {
    cout << "is_this_trait version" << endl;
}

template <typename T, typename enable_if<is_that_trait<T>::value, T>::type * = nullptr>
void method(T input) {
    cout << "is_that_trait version" << endl;
}

#pragma mark Specialization using types
template <typename T>
void method_nontrait(T input) {
    cout << "generic version" << endl;
}

template <>
void method_nontrait(int input) {
    cout << "int version" << endl;
}

template <>
void method_nontrait(float input) {
    cout << "float version" << endl;
}

#pragma mark Specialization using traits
template <>
struct is_this_trait<int> {
    static const bool value = true;
};

template <>
struct is_that_trait<float> {
    static const bool value = true;
};


@interface TestTraits : XCTestCase

@end

@implementation TestTraits

- (void)setUp {
    [super setUp];
    cout << "====================" <<endl;
}

- (void)tearDown {
    cout << "====================" <<endl;
    [super tearDown];
}

- (void)testTypeSpecialization {
    method_nontrait(3);
    method_nontrait(2.4f);
}

// Keep in mind, you can only specialize using separate traits for
// functions. Structs/classes do not allow overloading
- (void)testTraitSpecialization {
    method(2);
    method(3.0f);
}

@end
