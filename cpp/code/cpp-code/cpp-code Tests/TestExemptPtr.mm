//
//  TestExemptPtr.m
//  cpp-code
//
//  Created by kutty banerjee on 5/22/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include <iostream>
#include <memory>
#include "ExemptPtr.h"

using std::cout;
using std::endl;

class X {
public:
	void print() { cout << "hahaha" << endl; }
};

void test_func(ExemptPtr<X> & ref) {
	(*ref).print();
}

@interface TestExemptPtr : XCTestCase

@end

@implementation TestExemptPtr

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
	ExemptPtr<X> x(new X());
	test_func(x);
	(*x).print();
}

@end
