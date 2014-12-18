//
//  TestBasic.mm
//  cpp-practise
//
//  Created by kuttyb on 12/17/14.
//  Copyright (c) 2014 kbanerjee. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#include <iostream>

using std::cout;
using std::endl;

/* In our Modern C++ exercises, we shall stick to Functional/Generics and forego OO and Inheritance completely */

#pragma mark - POD
struct One {
    int header;
    int data;
    One(int h, int d) : header(h), data(d){}
    One(){}
};

struct Two {
    int header;
    int data;
    Two(int h, int d) : header(h), data(d){}
    Two(){}
};

struct Three {
    One one;
    Two two;
};

#pragma mark - Function (specialized by type)
/* Helper structs (with overloaded function call operator) are Policies or Strategies that are passed in by
 * type. Keep in mind, we did not pass any function pointers and that this is a direct function call.
 */
struct HelperOne {
    void operator()() {
        cout << "HelperOne" << endl;
    }
};

struct HelperTwo {
    void operator()() {
        cout << "HelperTwo" << endl;
    }
};

template <typename T, typename H>
void first_operate(T input) {
    cout << "Generic::first_operate" << endl;
    H h; h();
}

template <typename H>
void first_operate(One input) {
    cout << "One::first_operate" << endl;
    H h; h();
}

template <typename H>
void first_operate(Two input) {
    cout << "Two::first_operate" << endl;
    H h; h();
}

template <typename H>
void first_operate(Three input) {
    cout << "====================" << endl;
    cout << "Three::first_operate" << endl;
    first_operate<H>(input.one);
    first_operate<H>(input.two);
    cout << "====================" << endl;
}

template <typename T>
void top(void) {
    typename T::maintype data;
    first_operate<typename T::helper>(data);
}

#pragma mark - Configurators (They bind data and functions together with specific template instantiations)
struct ConfigOne {
    typedef One maintype;
    typedef Two secondtype;
    typedef HelperOne helper;
};

struct ConfigTwo {
    typedef Two maintype;
    typedef One secondtype;
    typedef HelperTwo helper;
};

struct ConfigThree : public ConfigTwo {
    typedef Three maintype;
    typedef One   secondtype;
};

#pragma mark - Objective C test layer
@interface TestBasic : XCTestCase
@end

@implementation TestBasic

- (void)setUp {
    [super setUp];
}

- (void)tearDown {
    [super tearDown];
}

- (void)testOne {
    top<ConfigOne>();
}

- (void)testTwo {
    top<ConfigTwo>();
}

- (void)testThree {
    top<ConfigThree>();
}

@end
