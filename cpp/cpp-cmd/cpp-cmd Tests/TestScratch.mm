//
//  TestScratch.mm
//  cpp-cmd
//
//  Created by kuttyb on 9/9/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#include <iostream>

using std::cout;
using std::endl;

#pragma mark - C++
template <bool n, typename T = void>
struct enable_if {
};

template <typename T>
struct enable_if <true, T> {
    typedef T type;
};

template <typename T>
struct is_bad_trait {
    static const bool value = false;
};

template <>
struct is_bad_trait <int> {
    static const bool value = true;
};

template <typename T>
struct is_good_trait {
    static const bool value = false;
};

template <>
struct is_good_trait <float> {
    static const bool value = true;
};

#pragma mark - C++ client
template <typename T, typename enable_if<is_bad_trait<T>::value, T>::type * = nullptr>
void m(T input) {
    cout << "bad" << endl;
}

template <typename T, typename enable_if<is_good_trait<T>::value, T>::type * = nullptr>
void m(T input) {
    cout << "good" << endl;
    // This will do a type demotion from float to int because you have explicitly specialized it
    m<int>(input);
}

#pragma mark - Objective-C
@interface TestScratch : XCTestCase

@end

@implementation TestScratch

- (void)setUp {
    [super setUp];
    cout << "================" << endl;
}

- (void)tearDown {
    cout << "================" << endl;
    [super tearDown];
}

- (void)testE {
    m(2);
    m(3.5f);
}

@end
