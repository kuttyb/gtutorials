//
//  Policy.mm
//  cpp-practise
//
//  Created by kuttyb on 12/30/14.
//  Copyright (c) 2014 kbanerjee. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#include <iostream>

using std::cout;
using std::endl;

#pragma mark - Core Functions
void methodOne(void) {
    cout << "Method one" << endl;
}

void methodTwo(void) {
    cout << "Method Two" << endl;
}

#pragma mark - Policy Structs
/* Use Structs with static methods when you want to pass it as a Strategy to an Algorithm */
struct One {
    static void process() {
        methodOne();
    }
};

struct Two {
    static void process() {
        methodTwo();
    }
};

template <typename Policy>
void top(void) {
    Policy::process();
    cout << "body of the method" << endl;
}

#pragma mark - Test Logic
@interface Policy : XCTestCase
@end

@implementation Policy

- (void)setUp {
    [super setUp];
}

- (void)tearDown {
    [super tearDown];
}

- (void)testExample {
    top<One>();
    top<Two>();
}

@end
