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
#if 0
    {
        // Client<D1, Dummy> b; // This will not compile so it almost acts like Java Generics Wildcards
        Client<D1, D3<Dummy> > b;
        D3<Dummy> input(2);
        b.setup(input);
    }
#endif
    
#if 0
    {
        Base<D2> *b = new D2(3);
        b->print();
    }
#endif
    
#if 0
    {
        Base<D1> *b = new D1(2);
        b->print();
    }
#endif
    
#if 0
    {
        Base<D3<Dummy> > d3;
        d3.print_most();
    }
#endif
    
#if 1
    {
        Base<D2> d;
        d.print_all();
    }
    
    {
        D2 x(2);
        x.local();
    }
#endif
    return 0;
}
