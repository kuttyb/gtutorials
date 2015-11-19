//
//  Gart.hpp
//  cpp-practise
//
//  Created by kuttyb on 11/18/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#ifndef Gart_h
#define Gart_h

#include <iostream>
#include "BRN.hpp"

using std::cout;
using std::endl;

#pragma mark - Base
template <typename ChipDispatch>
class GartBase {
	/* Delegates */
	brn2<ChipDispatch::BRN::brn1, ChipDispatch> b2;
public:
	/* Composites */
	typename ChipDispatch::accel * accel;
	
	void setup() {
		cout << __PRETTY_FUNCTION__ << endl;
		b2.apply();
		accel->close();
	}
};

#pragma mark - Gen1
template <typename ChipDispatch>
class GartGen1 : public GartBase<ChipDispatch> {
public:
	void init() {
		cout << __PRETTY_FUNCTION__ << endl;
		GartBase<ChipDispatch>::setup();
	}
};

#endif /* Gart_h */
