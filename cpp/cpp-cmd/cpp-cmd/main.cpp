//
//  main.cpp
//  cpp-cmd
//
//  Created by Kutty Banerjee on 1/21/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#include <iostream>
using std::cout;
using std::endl;

#include "NumberTemplates.hpp"

// Fake Objective-C Protocols
template <typename T>
class A{
private:
    int __contract(T type) {
        int x = type.print(3.4f); // int  print (float)
        type.print_more(x);       // void print_more(int)
    }
    T _var;
public:
    void set(T input) {
        _var = input;
    }
};

class X {
public:
    int print(float f) { return f;}
    void print_more(double  x) { }
};

int main(void) {
    num_main();
    X b;
    A<X> s;
    s.set(b);
    
    return 0;
}
