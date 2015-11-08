//
//  Accelerator.h
//  cpp-practise
//
//  Created by Kutty Banerjee on 11/6/15.
//  Copyright © 2015 kbanerjee. All rights reserved.
//

#ifndef Accelerator_hpp
#define Accelerator_hpp

#include "Channel3D.h"
#include "chipdispatch.h"

#pragma mark - Data
struct AcceleratorG4 {
	G4::channel3D * channel3D;
    uintptr_t     base_address;
};

struct AcceleratorG5 {
    AcceleratorG4   base;
	G5::channel3D * channel3D;
    uintptr_t       patch_address;
};

#pragma mark - Algorithm Classes
template <typename Accel, typename ChipDispatch>
class AcceleratorImpl {
public:
	static void init(Accel * accel);
	static void enumerate(Accel * accel);
};

#endif /* Accelerator_hpp */
