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

#pragma mark - Data
struct Channel3DG4 {
	uintptr_t baseAddr;
	uint32_t  priority;
	uint32_t  runtime;
};

struct Channel3DG5 {
	Channel3DG4 base;
	uint32_t estimate;
	uint32_t values;
};

#pragma mark - Algorithm Classes
template <typename Channel, typename Config>
class Channel3DImpl {
public:
	static void init(Channel * channel);
	static void submit(Channel * channel);
};


#endif /* Channel3D_hpp */
