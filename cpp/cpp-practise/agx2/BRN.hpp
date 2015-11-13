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
template <bool val, typename ChipDispatch>
class brn1 {
public:
    void apply() {}
};

template <typename ChipDispatch>
class brn1<true, ChipDispatch> {
    int first;
    int second;
public:
	void apply() {
        cout << "BRN1 " << endl;
    }
};

#pragma mark - brn2
template <bool val, typename ChipDispatch>
class brn2 {
public:
	void apply() {
    }
};

template <typename ChipDispatch>
class brn2<true, ChipDispatch> {
    int first;
    int second;
public:
	void apply() {
        cout << "BRN2 " << endl;
    }
};

#pragma mark - brn3
template <bool val, typename ChipDispatch>
class brn3 {
public:
	void apply() {
    }
};

template <typename ChipDispatch>
class brn3<true, ChipDispatch> {
    int first;
    int second;
public:
    void apply() {
        cout << "BRN3 " << endl;
    }
};

#pragma mark - brn4
template <bool val, typename ChipDispatch>
class brn4 {
public:
	void apply() {}
};

template <typename ChipDispatch>
class brn4 <true, ChipDispatch> {
	int values;
public:
	void apply() {
		cout << "BRN4" << endl;
	}
};

#endif //_BRN_HPP
