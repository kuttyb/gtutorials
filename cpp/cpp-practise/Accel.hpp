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
    brn1<ChipDispatch::BRN::brn1, ChipDispatch> b1;
    
protected:
    typename ChipDispatch::channel * channel;
    
public:
	AccelBase(typename ChipDispatch::channel * inputChannel) {
		channel = inputChannel;
	}
	
    void init() {
        cout << __PRETTY_FUNCTION__ << endl;
        b1.apply();
        channel->init();
    }
    
    void close() {
        cout << __PRETTY_FUNCTION__ << endl;
        channel->close();
    }
};

#pragma mark - Gen1
template <typename ChipDispatch>
class AccelGen1 : public AccelBase<ChipDispatch> {
    brn2<ChipDispatch::BRN::brn2, ChipDispatch> b2;
    
public:
	AccelGen1(typename ChipDispatch::channel * inputChannel) : AccelBase<ChipDispatch>(inputChannel)  {
	}
	
    void init() {
        cout << __PRETTY_FUNCTION__ << endl;

        AccelBase<ChipDispatch>::init();
        b2.apply();
        
        /* This is how you access your parent's member variable when you go through Templated inheritance */
        AccelBase<ChipDispatch>::channel->init();
    }
};

#pragma mark - Gen2
template <typename ChipDispatch>
class AccelGen2 : public AccelGen1<ChipDispatch> {
    brn3<ChipDispatch::BRN::brn3, ChipDispatch> b3;
    
public:
	AccelGen2(typename ChipDispatch::channel * inputChannel) : AccelGen1<ChipDispatch>(inputChannel) {
	}
	
    void init() {
        cout << __PRETTY_FUNCTION__ << endl;
        /* Punt to Gen1 */
        AccelGen1<ChipDispatch>::init();
        b3.apply();
    }
};

#endif /* Accel_h */
