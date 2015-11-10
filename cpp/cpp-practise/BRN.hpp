//
//  BRN.hpp
//  cpp-practise
//
//  Created by kuttyb on 11/5/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#include <iostream>

using std::cout;
using std::endl;

#ifndef _BRN_HPP
#define _BRN_HPP

#pragma mark - brn1
/* BRN Data */
template <bool val>
struct brn1Data {};

/* BRN Algorithms */
template <bool val, typename ChipDispatch>
struct brn1 {
	static void apply(brn1Data<val> * data);
};

/* Specialize false */
template <>
struct brn1Data<false> {};

template <typename ChipDispatch>
struct brn1 <false, ChipDispatch> {
	static void apply(brn1Data<false> * data) {}
};

/* Specialize true */
template <>
struct brn1Data<true> {
	int first;
	int second;
};
template <typename ChipDispatch>
struct brn1<true, ChipDispatch> {
	static void apply(brn1Data<true> * data) {
        cout << "BRN1 " << endl;
    }
};

#pragma mark - brn2
template <bool val, typename ChipDispatch>
struct brn2 {
	static void apply() {
    }
};

template <typename ChipDispatch>
struct brn2<true, ChipDispatch> {
	static void apply() {
        cout << "BRN2 " << endl;
    }
};

#pragma mark - brn3
template <bool val, typename ChipDispatch>
struct brn3 {
	static void apply() {
    }
};

template <typename ChipDispatch>
struct brn3<true, ChipDispatch> {
	static void apply() {
        cout << "BRN3 " << endl;
    }
};
#endif //_BRN_HPP
