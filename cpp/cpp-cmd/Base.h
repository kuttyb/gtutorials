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

#pragma mark Base
template <typename SUBTYPE>
class Base {
public:
    void print(void) { static_cast<SUBTYPE*>(this)->print();}
    void print_more(void) { static_cast<SUBTYPE*>(this)->print_more(); }
    void print_most(void) { static_cast<SUBTYPE*>(this)->print_most(); }
    void print_all(void) { print(); print_more(); print_most(); }
};

#pragma mark D1
class D1 : public Base<D1> {
public:
    void print(void);
    void print_more(void);
    void print_most(void);
};

#pragma mark D2
class D2 : public D1, public Base<D2> {
public:
    void print(void);
    void print_more(void);
    void print_most(void);
};

#pragma mark D3
class D3 : public D2, public Base<D3>   {
public:
    void print(void);
    void print_more(void);
   void print_most(void);
};

#endif /* defined(__cpp_cmd__Base__) */
