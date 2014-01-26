//
//  NonTemplate.cpp
//  cpp-code
//
//  Created by Kutty Banerjee on 1/12/14.
//  Copyright (c) 2014 Kutty Banerjee. All rights reserved.
//

#include <iostream>
#include "Initialization.h"

const int NonTemplate::VALUE = 3;

NonTemplate::NonTemplate(int input) : _value(2) {
    std::cout<<"Ctor" << std::endl;
}

NonTemplate::~NonTemplate(void) {
    std::cout<<"Dtor" << std::endl;
}

void NonTemplate::print(void) {
    std::cout<<"the value is " << _value << std::endl;
}
