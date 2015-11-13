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
	brn4<ChipDispatch::BRN::brn4, ChipDispatch> b4;
	
public:
    void init() {
        cout << __PRETTY_FUNCTION__ << endl;
    }
	
    void close() {
        cout << __PRETTY_FUNCTION__ << endl;
		b4.apply();
    }
};

#pragma mark - Gen1
template <typename ChipDispatch>
class ChannelGen1 : public ChannelBase<ChipDispatch> {
public:
    void init() {
        cout << __PRETTY_FUNCTION__ << endl;
        ChannelBase<ChipDispatch>::init();
    }
};

#pragma mark - Gen2
template <typename ChipDispatch>
class ChannelGen2 : public ChannelBase<ChipDispatch> {
public:
    void init() {
        cout << __PRETTY_FUNCTION__ << endl;
        ChannelBase<ChipDispatch>::init();
    }
	
	void compute() {
		cout << __PRETTY_FUNCTION__ << endl;
	}
};

#endif /* Channel_h */
