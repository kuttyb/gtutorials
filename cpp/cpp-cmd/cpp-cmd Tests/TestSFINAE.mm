//
//  TestSFINAE.mm
//  cpp-cmd
//
//  Created by Kutty Banerjee on 6/15/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include <iostream>

using std::cout;
using std::endl;

#pragma mark C++ enable_if
template <bool n, typename T = void>
struct enable_if {
};

template <typename T>
struct enable_if <true, T> {
    typedef T type;
};

#pragma mark Local Class
class Local {
};

#pragma mark Trait checks
template <typename T>
struct is_special_trait {
    static const bool value = false;
};

template <>
struct is_special_trait <Local> {
    static const bool value = true;
};

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

- (void)testExample
{
    
}

@end
