//
//  Channel3D.h
//  cpp-practise
//
//  Created by kuttyb on 11/5/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#ifndef Channel3D_hpp
#define Channel3D_hpp

#include <inttypes.h>
#include "BRN.hpp"

#pragma mark - Data
struct Channel3DG4 {
	uintptr_t baseAddr;
	uint32_t  priority;
	uint32_t  runtime;
	/* BRN Data */
	brn1Data b1Data;
};

struct Channel3DG5 {
	Channel3DG4 base;
	uint32_t estimate;
	uint32_t values;
	/* BRN Data */
	brn2Data b2Data;
	brn3Data b3Data;
};

#pragma mark - Algorithm Classes
template <typename Channel, typename ChipDispatch>
class Channel3DImpl {
public:
	static void init(Channel * channel);
	static void submit(Channel * channel, brn1Data * data, brn2Data * data2, brn3Data * data3);
};


#endif /* Channel3D_hpp */
