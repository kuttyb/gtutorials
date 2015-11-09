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
template <bool val, typename ChipDispatch>
struct brn1 {
    void operator()() {
    }
};

template <typename ChipDispatch>
struct brn1<true, ChipDispatch> {
    void operator()() {
        cout << "BRN1 " << endl;
    }
};

#pragma mark - brn2
template <bool val, typename ChipDispatch>
struct brn2 {
    void operator()() {
    }
};

template <typename ChipDispatch>
struct brn2<true, ChipDispatch> {
    void operator()() {
        cout << "BRN2 " << endl;
    }
};

#pragma mark - brn3
template <bool val, typename ChipDispatch>
struct brn3 {
    void operator ()() {
    }
};

template <typename ChipDispatch>
struct brn3<true, ChipDispatch> {
    void operator()() {
        cout << "BRN3 " << endl;
    }
};
#endif //_BRN_HPP
