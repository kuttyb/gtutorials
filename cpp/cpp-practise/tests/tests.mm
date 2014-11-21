//
//  tests.m
//  tests
//
//  Created by kuttyb on 11/21/14.
//  Copyright (c) 2014 kbanerjee. All rights reserved.
//
#include <iostream>
#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>

using std::cout;
using std::endl;

#pragma mark - Data Classes
struct One
{
    int a;
};

struct Two
{
    float a;
    One b;
};

class ConfigBig
{
public:
    // Each of these classes are DI points, think GUICE annotation points
    typedef One Line;
    typedef Two Linenext;
    // BRN table / Compile time properties etc
    constexpr static bool BRN123 = true;
    constexpr static bool BRN234 = false;
};

class ConfigSmall
{
public:
    typedef Two Line;
    typedef One Linenext;
    // BRN table (override the ones you don't like)
    constexpr static bool BRN123 = false;
    constexpr static bool BRN234 = true;
};

class ConfigBiggish : public ConfigBig
{
public:
    typedef One Linenext;
    // BRN table
    constexpr static bool BRN123 = false;
};

#pragma mark - Second order Pure Functions
namespace Operation
{
    template <typename T>
    void operate(T input)
    {
        cout << "generic version" << endl;
    }
    
    template <>
    void operate(One input)
    {
        cout << "One speaking" << endl;
    }
    
    template <>
    void operate(Two input)
    {
        cout << "Two speaking" << endl;
        operate(input.b);
    }
};

#pragma mark - BRNs
template <bool val>
void applyBRN123() {}

template <>
void applyBRN123<true>()
{
    cout << "Applying BRN123" << endl;
}

template <bool val>
void applyBRN234() {}

template <>
void applyBRN234<true>()
{
    cout << "Applying BRN234" << endl;
}

#pragma mark - Top level function
template <typename TypeFactory>
void top()
{
    typename TypeFactory::Linenext var;
    Operation::operate(var);
    
    applyBRN123<TypeFactory::BRN123>();
    
    applyBRN234<TypeFactory::BRN234>();
}

@interface tests : XCTestCase

@end

@implementation tests

- (void)setUp {
    [super setUp];
}

- (void)tearDown {
    [super tearDown];
}

- (void)testBasic {
    top<ConfigBiggish>();
}

@end
