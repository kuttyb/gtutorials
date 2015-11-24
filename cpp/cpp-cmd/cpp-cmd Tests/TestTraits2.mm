//
//  TestTraits2.mm
//  cpp-cmd
//
//  Created by kuttyb on 11/24/15.
//  Copyright © 2015 Kutty Banerjee. All rights reserved.
//

#import <XCTest/XCTest.h>
#include <iostream>

/* WORD OF CAUTION:
 * ================
 * Gentlemen, my sincere request. As sexy as Trait Specialization may sound, stay the hell away from it.
 * Use the approach below instead.
 * 
 * This will help you in the case where you have `n' types and `m' implementations where n >> m
 */
using std::cout;
using std::endl;

#pragma mark - C++
struct A {
};

struct B {
};

struct C {
};

struct D {
};

template <typename t> struct TypeOf { static const int type = 2; };
template <> struct TypeOf<A> { static const int type = 0; };
template <> struct TypeOf<B> { static const int type = 0; };
template <> struct TypeOf<C> { static const int type = 1; };

template <int val> void method(void) {
	cout << "method basic" << endl;
}

template <> void method<0>(void) {
	cout << "Type 0 " << endl;
}

template <> void method<1>(void) {
	cout << "Type 1" << endl;
}

template <typename T>
void uppermethod(T& input) {
	method<TypeOf<T>::type>();
}

#pragma mark - Test
@interface TestTraits2 : XCTestCase

@end

@implementation TestTraits2

- (void)setUp {
    [super setUp];
	cout << "===================" << endl;
}

- (void)tearDown {
	cout << "===================" << endl;
    [super tearDown];
}

- (void) testBasic {
	A a;
	uppermethod(a);
	
	B b;
	uppermethod(b);
	
	C c;
	uppermethod(c);
	
	D d;
	uppermethod(d);
}

@end
