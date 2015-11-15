//
//  Accel.hpp
//  cpp-practise
//
//  Created by Kutty Banerjee on 11/13/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#ifndef Accel_h
#define Accel_h

#include <iostream>
#include "chipdispatch.h"
#include "BRN.hpp"

using std::cout;
using std::endl;

#pragma mark - Base
template <typename ChipDispatch>
class AccelBase {
	/* Delegates */
    brn1<ChipDispatch::BRN::brn1, ChipDispatch> b1;
	
public:
	/* Composites */
	typename ChipDispatch::channelTA * channel;

    void init() {
        cout << __PRETTY_FUNCTION__ << endl;
		assert(channel);
		
        b1.apply();
        channel->init();
    }
    
    void close() {
        cout << __PRETTY_FUNCTION__ << endl;
        channel->close();
    }
};

#include "AccelGen1.hpp"
#include "AccelGen2.hpp"

#endif /* Accel_h */
