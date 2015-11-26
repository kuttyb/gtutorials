//
//  TestMETA2.mm
//  cpp-cmd
//
//  Created by kuttyb on 11/26/15.
//  Copyright © 2015 Kutty Banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include <iostream>

using std::cout;
using std::endl;

#pragma mark - C++
template <int val>
struct Basic {
	static constexpr int calc() {
		return Basic<val - 1>::calc() + val + sizeof(val);
	}
};

template <>
struct Basic<0> {
	static constexpr int calc() {
		return 0;
	}
};

#pragma mark - Type Selection
template <unsigned int val>
struct TypeSelect {
};

template <>
struct TypeSelect<0> {
 int type;
};

template <>
struct TypeSelect<1> {
	char type;
};

#pragma mark - Test
@interface TestMETA2 : XCTestCase

@end

@implementation TestMETA2

- (void)setUp {
    [super setUp];
	cout << "===================" << endl;
}

- (void)tearDown {
	cout << "===================" << endl;
    [super tearDown];
}

- (void) testBasic {
	cout << Basic<4>::calc() << endl;
}

@end
