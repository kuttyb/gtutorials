//
//  TestSpecialization.m
//  cpp-cmd
//
//  Created by kuttyb on 9/7/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#include <iostream>
#include <string>

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
struct is_weird_trait {
    static const bool value = false;
};

template <typename T>
struct is_weirder_trait {
    static const bool value = false;
};

#pragma mark Test methods
template <> struct is_weird_trait<int>   { static const bool value = true; };
template <> struct is_weirder_trait<float> { static const bool value = true; };
template <> struct is_weirder_trait<std::string> { static const bool value = true; };

template <typename T, typename enable_if<is_weirder_trait<T>::value>::type * = nullptr>
void method(T input) {
    cout << "weirder trait speaking" << endl;
}

template <typename T, typename enable_if<is_weird_trait<T>::value>::type * = nullptr>
void method(T input) {
    cout << "weird trait speaking" << endl;
}

#pragma mark - Test
@interface TestSpecialization : XCTestCase

@end

@implementation TestSpecialization

- (void)setUp {
    [super setUp];
    cout << "==============" << endl;
}

- (void)tearDown {
    cout << "==============" << endl;
    [super tearDown];
}

- (void)testExample {
    method(2);
    method(std::string("data"));
}

@end
