//
//  TestBasics.mm
//  cpp-cmd Tests
//
//  Created by kuttyb on 4/22/19.
//  Copyright © 2019 Kutty Banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include <iostream>

using namespace std;

#pragma mark - C++
template <typename T>
struct ABC {
	T data;
	ABC(T input) : data(input) {}
};

/* Base instance */
template <typename T>
void method(void) {
	cout << "Basic implementation " << endl;
}

/* Specialized instance */
template <>
void method<int>(void) {
	cout << "Int implemnentation " << endl;
}

#pragma mark - Tests
@interface TestBasics : XCTestCase

@end

@implementation TestBasics

- (void)setUp {
}

- (void)tearDown {
}

- (void) testMethodSpecialization {
	method<int>();
	
	method<float>();
}

- (void) testTypeSpecialization {
	{
		/* C++17 has template type inference */
		ABC data(12);
		cout << data.data << endl;
	}
	
	{
		ABC data(3.2f);
		cout << data.data << endl;
	}
}

@end
