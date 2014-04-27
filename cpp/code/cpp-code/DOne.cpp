//
//  DOne.cpp
//  cpp-code
//
//  Created by Kutty Banerjee on 1/21/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#include "BaseOne.hpp"

#include "DOne.h"
#include <memory>
#include <functional>

// Include BaseOne and instantiate it with type Derived
template class BaseOne<DOne>;

template <typename T>
class Port {
private:
    const int m_id;
    const std::function<void (T&, int)> dispatcher;
public:
    Port(int id, std::function<void (T&, int)>dispatcher) : m_id(id) {}
    void dispatch(T& ref, int context_id) { dispatcher(ref, context_id);}
};


void DOne::start(DOne *input) {
    auto f = [] (int& ref, int context_id) {
        
    };
    
    Port<int> port(3, f);
    
    if (input) ref = input;
    cout << "Derived class speaking" << endl;
}
