//
//  TestFunctionalInheritance.mm
//  cpp-cmd
//
//  Created by Kutty Banerjee on 9/5/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include <iostream>
#include "functionalderivation.h"

using std::cout;
using std::endl;

#pragma mark C++
template <typename T>
void Base<T>::common(T &input) {
    cout << __PRETTY_FUNCTION__ << "int values are " << input.x << " " << input.y << endl;
}

template <typename T>
void Derived<T>::common(T &input) {
    cout << __PRETTY_FUNCTION__ << " float " << input.m <<  endl;
    composite.common(input);
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

- (void)testExample
{
    G4G input(3.2f, 2, 5);
    Derived<G4G> machine;
    machine.common(input);
}

@end
