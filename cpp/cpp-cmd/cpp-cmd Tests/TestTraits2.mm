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

template <typename t> struct IsTraitThat { static const int type = 2; };
template <> struct IsTraitThat<A> { static const int type = 0; };
template <> struct IsTraitThat<B> { static const int type = 0; };
template <> struct IsTraitThat<C> { static const int type = 1; };

template <int TraitThat> void method(void) {
	cout << "method basic" << endl;
}

template <> void method<0>(void) {
	cout << "Type 0 " << endl;
}

template <> void method<1>(void) {
	cout << "Type 1" << endl;
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
	method<IsTraitThat<A>::type>();
	method<IsTraitThat<B>::type>();
	method<IsTraitThat<C>::type>();
	method<IsTraitThat<D>::type>();
}

@end
