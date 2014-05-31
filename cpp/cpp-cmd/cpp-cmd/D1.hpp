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

// Keep in mind, Type Specialization going from one type to another
// only works when the types are already part of your Inheritance
// hierarchy

template <typename SUBTYPE>
void Base<SUBTYPE>::specialize()
{
    cout << "Generic version of specialized code" << endl;
}

#pragma mark D1
void D1::print(void) {
    cout << "D1 print " << d1_state << endl;
}

void D1::print_more() {
    cout << "D1 print_more" << endl;
}

void D1::print_most() {
    cout << "D1 print_most" << endl;
}

template <>
void Base<D1>::specialize()
{
    cout << "D1 specialized" << endl;
}

#pragma mark D2
void D2::print(void) {
    D1::print();
    cout << "D2 print " << state << endl;
 }

void D2::print_more(void) {
    D1::print_more();
}

void D2::print_most() {
    D1::print_most();
}

template <>
void Base<D2>::specialize()
{
    cout << "D2 specializing" << endl;
}

#pragma mark D3
template <typename X>
void D3<X>::print_more(void) {
    cout << "D3 print_more" << endl;
}

template <typename X>
void D3<X>::print(void) {
    D2::print();
    Base<D1>::specialize();
}

template <typename X>
void D3<X>::print_most(void) {
    D1::print_most();
    // As you can see, I am taking care of both using
    // type specialization
    cout << "==Type Specialization at play==" << endl;
    Base<D3<X> >::specialize();
    Base<D2>::specialize();
    Base<D1>::specialize();
}

// Bottomline, Type Specialization and Inheritance can both
// survive in harmony
template <>
void Base<D3<Dummy> >::specialize()
{
    cout << "D3 specialized" << endl;
}

