//
//  Base.h
//  cpp-cmd
//
//  Created by Kutty Banerjee on 5/24/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#ifndef __cpp_cmd__Base__
#define __cpp_cmd__Base__

#include <iostream>

#define DISPATCH(T)  (static_cast<T*>(this))

#pragma mark Base
template <typename SUBTYPE>
class Base {
public:
    void print(void)      { DISPATCH(SUBTYPE)->print();      }
    void print_more(void) { DISPATCH(SUBTYPE)->print_more(); }
    void print_most(void) { DISPATCH(SUBTYPE)->print_most(); }
    void print_all(void)  {
        print();
        print_more();
        print_most();
        std::cout << "size is " << Base<SUBTYPE>::get_size() << std::endl;
    }
    uint32_t get_size(void) const;
};

#pragma mark D1
class D1 : public Base<D1> {
private:
    int d1_state;
public:
    D1(int d1_input) : d1_state(d1_input){
        std::cout << "D1 ctor" << std::endl;
    }
    void print(void);
    void print_more(void);
    void print_most(void);
};

#pragma mark D2
class D2 : public D1, public Base<D2> {
private:
    int state;
public:
    D2(int input) : D1(input + 10), state(input) {
        std::cout << "D2 ctor" << std::endl;
    }
    void print(void);
    void print_more(void);
    void print_most(void);
    void local(void) {
        Base<D1>::print_all();
    }
};

#pragma mark D3
template <typename X>
class D3 : public D2, public Base<D3<X> >   {
public:
    D3(int input) : D2(input){}
    void print(void);
    void print_more(void);
    void print_most(void);
};

#pragma mark DummyClass
class Dummy {
public:
    void print(void)      {}
    void print_more(void) {}
    void print_most(void) {}
};

#endif /* defined(__cpp_cmd__Base__) */
