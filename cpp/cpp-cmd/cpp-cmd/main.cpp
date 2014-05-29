//
//  main.cpp
//  cpp-cmd
//
//  Created by Kutty Banerjee on 1/21/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//
#include <assert.h>
#include <iostream>
#include "D1.hpp"

#pragma mark DummyClass
class Dummy {
public:
    void print(void)      {}
    void print_more(void) {}
    void print_most(void) {}
};

template class D3<Dummy>;

#pragma mark Client
template <typename FIELD, typename MEMBER>
class Client {
private:
    Base<FIELD> subject;
public:
    void setup(Base<MEMBER> input);
};

using std::cout;
using std::endl;

template <typename FIELD, typename MEMBER>
void Client<FIELD, MEMBER>::setup(Base<MEMBER> input) {
    cout << "field variable" << endl;
    subject.print_all();
    
    cout << "input variable " << endl;
    input.print_all();
}


int main(void) {
    // Client<D1, Dummy> b; // This will not compile so it almost acts like Java Generics Wildcards
    Client<D1, D3<Dummy> > b;
    D3<Dummy> input;
    
    b.setup(input);
    
    return 0;
}
