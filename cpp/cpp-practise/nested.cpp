//
//  nested.cpp
//  cpp-practise
//
//  Created by kuttyb on 11/18/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#include "nested.hpp"
#include <iostream>

template <typename T>
void Nested<T>::init() {
	std::cout<< __PRETTY_FUNCTION__ << std::endl;
}

template class Nested<int>;
