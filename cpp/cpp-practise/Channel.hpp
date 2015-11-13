//
//  Channel.hpp
//  cpp-practise
//
//  Created by Kutty Banerjee on 11/13/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#ifndef Channel_h
#define Channel_h

#include <iostream>
#include "chipdispatch.h"
#include "BRN.hpp"

#pragma mark - Base
template <typename ChipDispatch>
class ChannelBase {
public:
    void init() {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    
    void close() {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

#endif /* Channel_h */
