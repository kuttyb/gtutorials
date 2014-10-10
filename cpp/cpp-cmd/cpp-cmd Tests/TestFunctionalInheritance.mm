//
//  TestFunctionalInheritance.mm
//  cpp-cmd
//
//  Created by Kutty Banerjee on 9/5/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include <iostream>
#include "TypeAssert.h"
#include "functionalderivation.h"

using std::cout;
using std::endl;

#pragma mark C++ - Using Pure Classes
template <typename T>
void Base<T>::common(T &input) {
    cout << __PRETTY_FUNCTION__ << "int values are " << input.x << " " << input.y << endl;
}

template <typename T>
void Derived<T>::common(T &input) {
    cout << __PRETTY_FUNCTION__ << " float " << input.m <<  endl;
    composite.common(input);
}

#pragma mark C++ - Using Pure Functions
template <>
void common(G4P & input) {
    cout << "G4P version" << endl;
}

template <>
void common(G4G & input) {
    cout << "G4G version" << endl;
    common<G4P>(input);
}

#pragma mark Pointer trait
template <typename T>
struct is_pointer {
   static constexpr T pointer = nullptr;
   static const bool value = true;
};

// TODO: kbb: Need to implement is_value<T>
template <typename T, typename enable_if<is_pointer<T>::value, T>::type * = nullptr>
void deal_with_data(T input) {
    cout << "this is a pointer speaking and its value is " << *input << endl;
}

#pragma mark Objective-C
@interface TestFunctionalInheritance : XCTestCase

@end

@implementation TestFunctionalInheritance

- (void)setUp
{
    [super setUp];
    cout << "====================" << endl;
}

- (void)tearDown
{
    cout << "====================" << endl;
    [super tearDown];
}

- (void)testPointers
{
    int  value = 10;
    int *ptr   = &value;
    deal_with_data(ptr);
}

- (void)testClasses
{
    G4G input(3.2f, 2, 5);
    Derived<G4G> machine;
    machine.common(input);
}

- (void)testFunctionsDerived
{
    G4G input(3.2f, 2, 5);
    common(input);
}

- (void)testFunctionsBase
{
    G4P input(3, 20);
    common(input);
}

@end
