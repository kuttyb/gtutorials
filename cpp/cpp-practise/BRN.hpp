//
//  BRN.hpp
//  cpp-practise
//
//  Created by kuttyb on 11/5/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#include <iostream>
#include <assert.h>

using std::cout;
using std::endl;

#ifndef _BRN_HPP
#define _BRN_HPP

#pragma mark - brn1
/* BRN Data */
struct brn1Data {
	int first;
	int second;
};

/* BRN Algorithms */
template <bool val, typename ChipDispatch>
struct brn1 {
    static void apply(brn1Data * data) {}
};

template <typename ChipDispatch>
struct brn1<true, ChipDispatch> {
	static void apply(brn1Data * data) {
		assert(data);
        cout << "BRN1 " << endl;
    }
};

#pragma mark - brn2
/* BRN Data */
struct brn2Data {
	int first;
	int second;
};

/* BRN Algorithms */
template <bool val, typename ChipDispatch>
struct brn2 {
	static void apply(brn2Data * data) {
    }
};

template <typename ChipDispatch>
struct brn2<true, ChipDispatch> {
	static void apply(brn2Data * data) {
		assert(data);
        cout << "BRN2 " << endl;
    }
};

#pragma mark - brn3
/* BRN Data */
struct brn3Data {
	int first;
	int second;
};

/* BRN Algorithms */
template <bool val, typename ChipDispatch>
struct brn3 {
	static void apply(brn3Data * data) {
    }
};

template <typename ChipDispatch>
struct brn3<true, ChipDispatch> {
	static void apply(brn3Data * data) {
		assert(data);
        cout << "BRN3 " << endl;
    }
};
#endif //_BRN_HPP
