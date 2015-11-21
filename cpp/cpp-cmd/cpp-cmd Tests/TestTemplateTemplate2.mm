//
//  TestTemplateTemplate2.mm
//  cpp-cmd
//
//  Created by kuttyb on 9/9/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#include <iostream>
#include <functional>

using std::cout;
using std::endl;

#pragma mark - C++
template <typename T>
class A {
};

template <typename T>
class B {
};

template <typename T>
class C {
};

#pragma mark - Template Template
template <template <typename> class F, typename T>
struct function {
	void operator()(F<T> input) {
		cout << "Generic version" << endl;
	}
};

#pragma mark - Outer Param Specialization
template <typename T>
struct function <A, T> {
	void operator()(A<T> input) {
		cout << "A<T> version" << endl;
	}
};

template <typename T>
struct function <B, T> {
	void operator()(B<T> input) {
		cout << "B<T> version" << endl;
	}
};

#pragma mark - Inner Param Specialization
template <template <typename> class F>
struct function<F, int> {
	void operator()(F<int> input) {
		cout << "F<int> version" << endl;
	}
};

template <template <typename> class F>
struct function <F, double> {
	void operator()(F<double> input) {
		cout << "F<double> version" << endl;
	}
};

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

- (void)testTemplateTemplateSpecialization {
	A<float> a;
	function<A, float>()(a);

	B<float> b;
	function<B, float>()(b);
	
	C<int> x;
	function<C, int>()(x);
	
	C<double> y;
	function<C, double>()(y);
}

@end
