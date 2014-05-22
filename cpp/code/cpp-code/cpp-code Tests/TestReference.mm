//
//  TestReference.mm
//  cpp-code
//
//  Created by kutty banerjee on 5/22/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>

#include <iostream>
using std::cout;
using std::endl;

class ClassX {
public:
	int x;
};

bool testfunc(ClassX & ref) {
	cout << "address is " << &ref << endl;
	ClassX * ptr = &ref;
	return ptr == nullptr;
}

@interface TestReference : XCTestCase

@end

@implementation TestReference

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
	ClassX x;
	cout << "address is " << &x << endl;
	testfunc(x);
}

@end
