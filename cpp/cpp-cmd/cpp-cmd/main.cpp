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

class X {
public:
    int print(float f) {return 0;}
    void print_more(double  x) {}
};

class Y {
public:
    int call_value(void) { return 0;}
};

class C :  public Y {
};

class D : public X {
};

class E {
};

#define ASSERT_TYPE_START private: static const bool x_y =
#define ASSERT_TYPE_INHERITS(U, V)   ((U*)NULL == (V*)NULL) &&
#define ASSERT_TYPE_END    false;

template <typename T, typename U>
class A{
ASSERT_TYPE_START
    ASSERT_TYPE_INHERITS(T, X)
    ASSERT_TYPE_INHERITS(U, Y)
ASSERT_TYPE_END
    
private:
    float _var;
    
public:
    void set(float input) {
        _var = input;
        cout << "yes its working" << endl;
    }
};


int main(void) {
    num_main();
    
    A<D, C> n;
//    A<E, C> n; // this fails compilation as expected!!
    n.set(3.f);
    
    return 0;
}
