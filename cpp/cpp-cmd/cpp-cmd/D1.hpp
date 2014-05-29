//
//  D1.cpp
//  cpp-cmd
//
//  Created by Kutty Banerjee on 5/24/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#include "Base.h"

using std::cout;
using std::endl;

#pragma mark D1
void D1::print(void) {
    cout << "D1 print" << endl;
}

void D1::print_more() {
    cout << "D1 print_more" << endl;
}

void D1::print_most() {
    cout << "D1 print_most" << endl;
}


#pragma mark D2
void D2::print(void) {
    cout << "D2 print" << endl;
}

void D2::print_more(void) {
    D1::print_more();
}

void D2::print_most() {
    D1::print_most();
}

#pragma mark D3
template <typename X>
void D3<X>::print_more(void) {
    cout << "D3 print_more" << endl;
}

template <typename X>
void D3<X>::print(void) {
    D2::print();
}

template <typename X>
void D3<X>::print_most(void) {
    D1::print_most();
}

