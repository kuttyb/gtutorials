//
//  SmartPtr.cpp
//  cpp-code
//
//  Created by kuttyb on 4/19/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#include "SmartPtr.h"
#include <assert.h>
#include <iostream>
#include <memory>

using std::unique_ptr;
using std::cout;
using std::endl;

// Preferred approach, please use this
template <typename T>
static void print_value(T & ref) {
    cout << ref << endl;
    ref++;
}

template <typename T>
static T* print_value_ref(const unique_ptr<T> & ref) {
    cout << *ref << endl;
    (*ref)++;
    
    // This is the real DANGER to this approach.
    // unique_ptr.get() gives you the pointer fair and simple
    // and now anybody can store/retain copy it as they please
    return ref.get();
}

void test_unique_ptr_reference() {
    unique_ptr<int> x(new int(3));
    print_value<int>(*x.get());
    cout << *x << endl;
    
    print_value_ref<int>(x);
    cout << *x << endl;
}
