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

struct Channel3D {
	uintptr_t baseAddr;
	uint32_t  priority;
	uint32_t  runtime;
};

struct Channel3DG5 {
	Channel3D base;
	uint32_t estimate;
	uint32_t values;
};

#endif /* Channel3D_hpp */
